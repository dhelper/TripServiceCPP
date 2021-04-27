#define CATCH_CONFIG_MAIN

#include "turtle/catch.hpp"
#include "fakes/FakeUserSession.h"
#include "fakes/FakeTripDAO.h"
#include "helpers/UserSessionAccessor.h"
#include "../TripService.h"
#include "../UserNotLoggedInException.h"

using Catch::Matchers::Equals;

TEST_CASE("Should throw exception if not logged in", "")
{
    User *NotLoggedUser = nullptr;

    auto fakeUserSession = new FakeUserSession();
    MOCK_EXPECT(fakeUserSession->GetLoggedUser).returns(NotLoggedUser);
    UserSessionAccessor::Set(fakeUserSession);

    TripService tripService;

    User dummy(1);

    REQUIRE_THROWS_AS(
            tripService.GetTripsByUser(dummy), UserNotLoggedInException);
}

TEST_CASE("Should not return trips when logged user is not a friend")
{
    User user(1);

    auto fakeUserSession = new FakeUserSession();
    MOCK_EXPECT(fakeUserSession->GetLoggedUser).returns(&user);

    UserSessionAccessor::Set(fakeUserSession);

    TripService tripService;

    User notFriend(2);
    auto trips = tripService.GetTripsByUser(notFriend);

    REQUIRE(trips.size() == 0);
}

TEST_CASE("Should return trips when logged user is a friend")
{
    User user(1);

    auto fakeUserSession = new FakeUserSession();
    MOCK_EXPECT(fakeUserSession->GetLoggedUser).returns(&user);
    UserSessionAccessor::Set(fakeUserSession);

    User myFriend(2);
    myFriend.AddFriend(user);
    myFriend.AddTrip(Trip(1));
    myFriend.AddTrip(Trip(2));

    std::shared_ptr<FakeTripDAO> fakeTripDao(new FakeTripDAO);
    MOCK_EXPECT(fakeTripDao->FindTripsByUser).returns(myFriend.Trips());
    TripService tripService(fakeTripDao);

    auto trips = tripService.GetTripsByUser(myFriend);

    std::vector<Trip> actual(trips.begin(), trips.end());
    std::vector<Trip> expected(myFriend.Trips().begin(), myFriend.Trips().end());

    REQUIRE_THAT(actual, Equals(expected));
}
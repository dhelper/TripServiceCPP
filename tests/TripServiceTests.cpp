
#include "../User.h"
#include "../UserNotLoggedInException.h"
#include "helpers/UserSessionAccessor.h"
#include "../TripService.h"
#undef FAIL
#undef SUCCEED
#include "catch.hpp"
#include "fakes/FakeTripDAO.h"

using Catch::Matchers::Equals;
using testing::Return;

TEST_CASE("Should throw exception if not logged in", "")
{
    User *NotLoggedUser = nullptr;

    auto fakeUserSession = new FakeUserSession();
    EXPECT_CALL(*fakeUserSession, GetLoggedUser).WillRepeatedly(Return(NotLoggedUser));
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
    EXPECT_CALL(*fakeUserSession, GetLoggedUser).WillRepeatedly(Return(&user));

    UserSessionAccessor::Set(fakeUserSession);

    TripService tripService;

    User notFriend(2);
    auto trips = tripService.GetTripsByUser(notFriend);

    REQUIRE(trips.empty());
}

TEST_CASE("Should return trips when logged user is a friend")
{
    User user(1);

    auto fakeUserSession = new FakeUserSession();
    EXPECT_CALL(*fakeUserSession, GetLoggedUser).WillRepeatedly(Return(&user));
    UserSessionAccessor::Set(fakeUserSession);

    TripServiceBase<FakeTripDAO> tripService;

    User myFriend(2);
    myFriend.AddFriend(user);
    myFriend.AddTrip(Trip(1));
    myFriend.AddTrip(Trip(2));

    auto trips = tripService.GetTripsByUser(myFriend);

    std::vector<Trip> actual(trips.begin(), trips.end());
    std::vector<Trip> expected(myFriend.Trips().begin(), myFriend.Trips().end());

    REQUIRE_THAT(actual, Equals(expected));
}
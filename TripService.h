#ifndef TRIPSERVICE_TRIPSERVICE_H
#define TRIPSERVICE_TRIPSERVICE_H

#include "Trip.h"
#include <list>
#include "UserNotLoggedInException.h"
#include "UserSession.h"
#include "TripDAO.h"

class User;

class TripService {
    std::shared_ptr<TripDaoInstance> tripDao;

public:
    TripService()  {
        tripDao = std::make_shared<TripDaoInstance>();
    }

    TripService(const std::shared_ptr<TripDaoInstance> &tripDao) : tripDao(tripDao) {}


    std::list<Trip> GetTripsByUser(User user);
};

std::list<Trip> TripService::GetTripsByUser(User user) {
    std::list<Trip> triplist;
    User *loggedUser = UserSession::GetInstance()->GetLoggedUser();
    bool isFriend = false;
    if (loggedUser) {
        for (auto i = user.GetFriends().begin(); i != user.GetFriends().end(); ++i) {
            if (*i == *loggedUser) {
                isFriend = true;
                break;
            }
        }
        if (isFriend) {
            triplist = tripDao->FindTripsByUser(user);
        }
        return triplist;
    } else {
        throw UserNotLoggedInException();
    }
};

#endif //TRIPSERVICE_TRIPSERVICE_H

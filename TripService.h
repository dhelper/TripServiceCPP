#ifndef TRIPSERVICE_TRIPSERVICE_H
#define TRIPSERVICE_TRIPSERVICE_H

#include "Trip.h"
#include <list>
#include "UserNotLoggedInException.h"
#include "UserSession.h"
#include "TripDAO.h"

class User;

class TripService {
protected:
    virtual void FindTripsByUser(User &user, std::list<Trip> &triplist);
public:
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
            FindTripsByUser(user, triplist);
        }
        return triplist;
    } else {
        throw UserNotLoggedInException();
    }
}

void TripService::FindTripsByUser(User &user, std::list<Trip> &triplist) {
    triplist = TripDAO::FindTripsByUser(user);
};


#endif //TRIPSERVICE_TRIPSERVICE_H

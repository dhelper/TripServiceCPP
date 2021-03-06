#ifndef TRIPSERVICE_TRIPSERVICE_H
#define TRIPSERVICE_TRIPSERVICE_H


class User;

class TripService
{
public:
    static std::list<Trip> GetTripsByUser(User user);

};

std::list<Trip> TripService::GetTripsByUser(User user)
{
    std::list<Trip> triplist;
    User* loggedUser = UserSession::GetInstance()->GetLoggedUser();
    bool isFriend = false;
    if (loggedUser)
    {
        for (auto i = user.GetFriends().begin(); i != user.GetFriends().end(); ++i)
        {
            if (*i == *loggedUser)
            {
                isFriend = true;
                break;
            }
        }
        if (isFriend)
        {
            triplist = TripDAO::FindTripsByUser(user);
        }
        return triplist;
    }
    else
    {
        throw UserNotLoggedInException();
    }
}


#endif //TRIPSERVICE_TRIPSERVICE_H

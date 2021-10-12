//
// Created by drorh on 10/7/2021.
//

#ifndef TRIPSERVICE_FAKETRIPDAO_H
#define TRIPSERVICE_FAKETRIPDAO_H


#include "../TripDAO.h"
#include "gmock/gmock.h"

class FakeTripDAO {
public:
    static std::list<Trip> FindTripsByUser(User user) {
        return user.Trips();
    }
};


#endif //TRIPSERVICE_FAKETRIPDAO_H

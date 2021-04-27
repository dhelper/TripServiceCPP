//
// Created by drorh on 4/27/2021.
//

#ifndef TRIPSERVICE_TRIPDAOINSTANCE_H
#define TRIPSERVICE_TRIPDAOINSTANCE_H

#include "TripDAO.h"

class TripDaoInstance{
public:
    virtual std::list<Trip> FindTripsByUser(User user){
       return TripDAO::FindTripsByUser(user);
    }
};
#endif //TRIPSERVICE_TRIPDAOINSTANCE_H

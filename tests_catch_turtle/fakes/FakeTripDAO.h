#ifndef TRIPSERVICE_FAKETRIPDAO_H
#define TRIPSERVICE_FAKETRIPDAO_H

#include "turtle/catch.hpp"
#include "../TripDAO.h"
#include "../TripDaoInstance.h"

MOCK_BASE_CLASS(FakeTripDAO, TripDaoInstance){
    MOCK_METHOD(FindTripsByUser, 1)
};

#endif //TRIPSERVICE_FAKETRIPDAO_H

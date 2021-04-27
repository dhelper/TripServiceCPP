#ifndef TRIPSERVICE_FAKETRIPDAO_H
#define TRIPSERVICE_FAKETRIPDAO_H

#include "turtle/catch.hpp"
#include <list>
#include "../TripDAO.h"
#include "../Trip.h"
#include "../User.h"

MOCK_CLASS(FakeTripDAO) {
    MOCK_STATIC_METHOD(FindTripsByUser, 1, std::list<Trip>(User))
};

#endif //TRIPSERVICE_FAKETRIPDAO_H

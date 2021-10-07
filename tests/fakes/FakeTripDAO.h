#ifndef TRIPSERVICE_FAKETRIPDAO_H
#define TRIPSERVICE_FAKETRIPDAO_H

#include "../TripDAO.h"
#include "../TripDaoInstance.h"
#include "gmock/gmock.h"

class FakeTripDAO : public TripDaoInstance{
public:
    MOCK_METHOD(std::list<Trip>, FindTripsByUser, (User));
};

#endif //TRIPSERVICE_FAKETRIPDAO_H

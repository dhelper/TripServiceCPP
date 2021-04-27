#ifndef TRIPSERVICE_TRIPSERVICEFORTESTS_H
#define TRIPSERVICE_TRIPSERVICEFORTESTS_H

#include "../TripService.h"

class TripServiceForTests : public TripService {
    std::list<Trip> trips;

public:
    explicit TripServiceForTests(const std::list<Trip> &trips) : trips(trips) {}

protected:
    void FindTripsByUser(User &user, std::list<Trip> &triplist) override {
        triplist = trips;
    }
};

#endif //TRIPSERVICE_TRIPSERVICEFORTESTS_H

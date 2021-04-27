#ifndef TRIPSERVICE_TRIPDAO_H
#define TRIPSERVICE_TRIPDAO_H

class TripDAO
{
public:
    inline static std::list<Trip> FindTripsByUser(User user)
    {
        throw "TripDAO should not be invoked on an unit test.";
    }
}

#endif //TRIPSERVICE_TRIPDAO_H

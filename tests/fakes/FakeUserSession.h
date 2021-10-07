#ifndef TRIPSERVICE_FAKEUSERSESSION_H
#define TRIPSERVICE_FAKEUSERSESSION_H

#include "../../UserSession.h"
#include "../../User.h"
#include "gmock/gmock.h"

class FakeUserSession : public UserSession{
public:
    MOCK_METHOD(bool, IsUserLoggedIn, (User));
    MOCK_METHOD(User*, GetLoggedUser, ());
};

#endif //TRIPSERVICE_FAKEUSERSESSION_H

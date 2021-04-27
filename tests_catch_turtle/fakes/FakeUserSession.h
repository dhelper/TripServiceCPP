#ifndef TRIPSERVICE_FAKEUSERSESSION_H
#define TRIPSERVICE_FAKEUSERSESSION_H

#include "../turtle/mock.hpp"
#include "../../UserSession.h"
#include "../../User.h"

MOCK_BASE_CLASS(FakeUserSession, UserSession) {
    MOCK_METHOD(IsUserLoggedIn, 1, bool(User))
    MOCK_METHOD(GetLoggedUser, 0, User*())
};

#endif //TRIPSERVICE_FAKEUSERSESSION_H

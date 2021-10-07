#ifndef TRIPSERVICE_USERSESSIONACCESSOR_H
#define TRIPSERVICE_USERSESSIONACCESSOR_H

#include "fakes/FakeUserSession.h"
#include "../UserSession.h"

class UserSessionAccessor {
public:
    static void Set(FakeUserSession *fakeUserSession) {
        UserSession::GetInstance();

        delete UserSession::instance;

        UserSession::instance = fakeUserSession;
    }

};

#endif //TRIPSERVICE_USERSESSIONACCESSOR_H

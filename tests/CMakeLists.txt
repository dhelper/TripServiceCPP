project(trip_service_tests)

find_package(Catch2 CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)

add_executable(trip_service_tests
        main.cpp
        gmock_catch_interceptor.hpp
        gmock_catch_interceptor.cpp
        TripServiceTests.cpp
        helpers/UserSessionAccessor.h
        fakes/FakeUserSession.h
        )

target_link_libraries(trip_service_tests
        PUBLIC TripService
        PRIVATE Catch2::Catch2
        PRIVATE GTest::gmock
        PRIVATE GTest::gtest
        )


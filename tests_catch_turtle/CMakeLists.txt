project(trip_service_catch_turtle_tests)
set(CMAKE_CXX_STANDARD 14)

set(Boost_USE_STATIC_LIBS OFF)
set (Boost_USE_MULTITHREAD ON)  # enable multithreading
find_package (Boost REQUIRED COMPONENTS unit_test_framework)

add_executable(cash_register_tests TripServiceTests.cpp fakes/FakeUserSession.h helpers/UserSessionAccessor.h helpers/TripServiceForTests.h)
target_include_directories(cash_register_tests PUBLIC ./ ./turtle ${Boost_INCLUDE_DIRS})
target_link_libraries(cash_register_tests TripService ${Boost_LIBRARIES})
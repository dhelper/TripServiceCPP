cmake_minimum_required(VERSION 3.19)
project(TripService)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(tests_catch_turtle)

add_library(TripService Trip.h TripDAO.h TripService.h User.h UserNotLoggedInException.h UserSession.cpp UserSession.h TripDaoInstance.h)
#define CATCH_CONFIG_RUNNER

#include "gtest/gtest.h"
#include "gmock_catch_interceptor.hpp"
#undef FAIL
#undef SUCCEED
#include "catch.hpp"

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    ::testing::TestEventListeners& listeners = ::testing::UnitTest::GetInstance()->listeners();
    listeners.Append(new gmock_catch_interceptor());

    delete listeners.Release(listeners.default_result_printer());

    return Catch::Session().run(argc, argv);
}
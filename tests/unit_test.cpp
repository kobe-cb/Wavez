#include "gtest/gtest.h"
#include "login_test.hpp"
#include "rating_test.hpp"
#include "review_test.hpp"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

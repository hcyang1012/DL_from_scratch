#include <gtest/gtest.h>

// Framework
#include <variable.hpp>

TEST(VariableTest, VariableTest) {
  dl_framework::Variable<float> x(1.0f);
  EXPECT_EQ(x.Data(), 1.0f);
}
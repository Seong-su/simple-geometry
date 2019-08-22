#include <gtest/gtest.h>

#include <lbt-info.hpp>
#include <StepReader.hpp>

TEST(Step, Reader) {
  StepReader reader("models/cube806020.step");
  EXPECT_TRUE(reader.is_open());
}
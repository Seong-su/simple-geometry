#include <gtest/gtest.h>

#include <lbt-info.hpp>
#include <StepReader.hpp>

TEST(Step, Reader) {
  StepReader reader("models/Cubes.step"); 
  EXPECT_TRUE(reader.succeeded());
}
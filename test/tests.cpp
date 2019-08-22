#include <gtest/gtest.h>

// #include <STEPControl_Reader.hxx>

#include <lbt-info.hpp>
// #include <StepReader.hpp>

TEST(Algebra, sum) {
  EXPECT_EQ(2, sum(1,1));
}

TEST(Step, Reader) {
  //StepReader reader("models/cube806020.step");
  //STEPControl_Reader reader;
  bool a = true;
  // EXPECT_FALSE(a);
}
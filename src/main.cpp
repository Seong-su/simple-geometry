#include <iostream>

#include <StepReader.hpp>

int main(int argc, char const *argv[])
{
  StepReader reader("models/cube806020.step");
  std::cout << reader.is_open() << std::endl;

  // while (true)
  // {
  //   std::cout << "HI" << std::endl;
  // }

  return 0;
}

#pragma once

#include <string>

class StepReader {
 public:
  StepReader(const std::string& file_name);
  ~StepReader();

  bool succeeded() { return succeeded_; }
  
 private:
  std::string file_name_;
  bool succeeded_ = false;
};
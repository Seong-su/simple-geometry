#pragma once

#include <string>

class StepReader {
 public:
  StepReader(const std::string& file_name);
  ~StepReader();

  bool is_open() { return is_open_; }
  
 private:
  std::string file_name_;
  bool is_open_ = false;
};
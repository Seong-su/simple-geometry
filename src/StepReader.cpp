#include <StepReader.hpp>

// #include <STEPControl_Reader.hxx>

class FileDialog {
 private:
  /* data */
 public:
  FileDialog(/* args */) {}
  ~FileDialog() {}
};

class Geometry {
 private:
  /* data */
 public:
  Geometry(/* args */) {}
  ~Geometry() {}
};

StepReader::StepReader(const std::string& file_name) : file_name_(file_name) {
  // STEPControl_Reader reader; 
  // IFSelect_ReturnStatus stat = reader.ReadFile(file_name_.c_str());

  // switch (stat)
  // {
  // case IFSelect_RetVoid:
  // case IFSelect_RetDone:
  //   is_open_ = true;
  //   break;
  
  // default:
  //   is_open_ = false;
  //   break;
  // }
}

StepReader::~StepReader() {}
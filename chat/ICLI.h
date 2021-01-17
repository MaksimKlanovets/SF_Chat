#pragma once
#include <string>
class ICLI
{
public:
  virtual std::string getHelp();
  virtual bool runCommand(std::string command);
};


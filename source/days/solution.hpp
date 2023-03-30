#pragma once
#include <iostream> 

struct Solution {
  long part_one;
  long part_two;
};

struct Day {
  std::string name;
  std::string filename;
  Solution (*entry)(std::istream* input);
};
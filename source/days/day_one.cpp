#include <algorithm>
#include <iostream>

#include "solution.hpp"

using std::vector;

namespace days {
  Solution day_one(std::istream *input) {
    std::vector<int> calories = {};

    int elf = 0;
    while (*input) {
      int entry = 0;
      if (input->peek() == '\n') {
        calories.push_back(elf);
        std::push_heap(calories.begin(), calories.end());
        elf = 0;
        input->ignore(1, '\n');
      } else {
        *input >> entry;
        elf += entry;
        input->ignore(1, '\n');
      }
    }

    long top_elf = calories.front();

    long top_three = 0;
    for (auto i = 0; i < 3; i++) {
      top_three += calories.front();
      std::pop_heap(calories.begin(), calories.end());
      calories.pop_back();
    }

    return Solution{top_elf, top_three};
  }
}
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::vector, std::string;

struct Solution {
  long part_one;
  long part_two;
};

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

int main() {
  using std::chrono::duration;
  using std::chrono::duration_cast;
  using std::chrono::high_resolution_clock;
  using std::chrono::milliseconds;

  const string fname = "../data/day1.txt";
  std::ifstream f{fname};

  if (!f.is_open()) {
    std::cout << "Could not open file: " << fname << std::endl;
    return EXIT_FAILURE;
  }
  std::cout << "Starting day_one" << std::endl;

  auto t1 = high_resolution_clock::now();
  auto solution = day_one(&f);
  auto t2 = high_resolution_clock::now();

  duration<double, std::milli> ms_double = t2 - t1;

  std::cout << "Part 1: " << solution.part_one
            << " Part 2: " << solution.part_two << std::endl;
  std::cout << "Runtime:" << ms_double.count() << "ms" << std::endl;
  return 0;
}
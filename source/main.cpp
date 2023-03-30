#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "days/all.hpp"
#include "days/solution.hpp"

using std::vector, std::string;


int main() {
  using std::chrono::duration;
  using std::chrono::duration_cast;
  using std::chrono::high_resolution_clock;
  using std::chrono::milliseconds;

  const string fname = "../data/day1.txt";

  std::vector<Day> days = {Day{"day1", "../data/day1.txt", days::day_one}};

  auto total_begin = high_resolution_clock::now();
  for (auto day : days) {
    std::ifstream f{day.filename};

    if (!f.is_open()) {
      std::cout << "Could not open file: " << fname << std::endl;
      return EXIT_FAILURE;
    }
    std::cout << "Starting day_one" << std::endl;

    auto t1 = high_resolution_clock::now();
    auto solution = day.entry(&f);
    auto t2 = high_resolution_clock::now();

    duration<double, std::milli> ms_double = t2 - t1;

    std::cout << "Part 1: " << solution.part_one
              << " Part 2: " << solution.part_two << std::endl;
    std::cout << "Runtime:" << ms_double.count() << "ms" << std::endl;

  }

  auto total_end = high_resolution_clock::now();
  duration<double, std::milli> total_ms = total_end - total_begin;
  std::cout << "Total Runtime:" << total_ms.count() << "ms" << std::endl;

  return 0;
}
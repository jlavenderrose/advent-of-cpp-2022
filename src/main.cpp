#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>

using std::vector, std::string;

int main()
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();
    const string fname = "../data/day1.txt";
    std::ifstream f{fname};

    std::vector<int> calories = {};

    if (!f.is_open()) {
        std::cout << "Could not open file: " << fname << std::endl;
        return EXIT_FAILURE;
    }

    int elf;
    while (f) 
    {
        int entry = 0;
        if (f.peek() == '\n') {
            calories.push_back(elf);
            std::push_heap(calories.begin(), calories.end());
            elf = 0;
            f.ignore(1, '\n');
        } else {
            f >> entry;
            elf += entry;
            f.ignore(1, '\n');
        }
    }

    std::cout << "day2 part 1: " << calories.front() << std::endl;

    int top_three = 0;
    for (int i = 0; i<3; i++) {
        std::pop_heap(calories.begin(), calories.end());
        top_three += calories.back();
        calories.pop_back();
    }

    std::cout << "day2 part 2: " << top_three << std::endl;
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - t1;

    std::cout << ms_double.count() << "ms" << std::endl;
    return 0;
}

#include <iostream>
#include "Day1.hpp"

int main()
{
    std::ifstream myFile("input_1.txt");
    aoc::day1::Solution s(myFile);
    std::cout << s.solve();
}

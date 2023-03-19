
#include <iostream>
#include "Day1.hpp"
#include "Day2.hpp"
#include "Day3.hpp"
#include "Day4.hpp"
#include "Day5.hpp"
#include "Day6.hpp"
#include "Day7.hpp"
#include "Day8.hpp"
#include "Day9.hpp"
#include "Day10.hpp"



int main()
{
    std::ifstream myFile("input_1.txt");
    aoc::day10::Solution s(myFile);
    //print INT_MAX + INT_MIN plus std::endl;
    s.solveSecond();
}

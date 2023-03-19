#include <iostream>
#include <vector>
#include "Solution.h"

namespace aoc {
	namespace day11 {
		class Monkey {
		public:
			std::vector<int> items;
			int (*func)(int);
			bool (*func2)(int);
			int test_true;
			int test_false;
		
			Monkey(std::vector<int>& i,
				int (*func)(int),
				bool (*func2)(int),
				int test_true,
				int test_false) : items(i), func(func), func2(func2), test_true(test_true), test_false(test_false) {}
		};
		class Solution : ISolution {

		public:
			Solution(std::ifstream& a) : ISolution(a) {};
			int solveFirst() {
				std::vector<Monkey> monkeys;
				auto l1 = [](int n) {return n * 13; };
				auto l2 = [](int n) {return n % 5; };
				Monkey m({ 52,78,79,63,51,94 },l1, l2 , 1, 6);
			}

		};
	}
}
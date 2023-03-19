#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
namespace aoc {
	namespace day4 {
		class Solution {
		private:
		private:
			std::ifstream& m_file;
		public:
			Solution(std::ifstream& input_file) : m_file(input_file) {}
			/// <summary>
			/// The goal is to calculate the biggest number of calories an elf is carrying
			/// </summary>
			/// <returns></returns>
			int solveFirst() {
				if (!m_file.is_open()) return 0;
				int first, second, third, fourth;
				char _char;
				int counter = 0;
				while (m_file >> first >> _char >> second >> _char >> third >> _char >> fourth) {
					if (first >= third && second <= fourth) counter++;
					else if (first <= third && second >= fourth) counter++;
				}
				return counter;
			}
			int solveSecond() {
				if (!m_file.is_open()) return 0;
				int first, second, third, fourth;
				char _char;
				int counter = 0;
				while (m_file >> first >> _char >> second >> _char >> third >> _char >> fourth) {
					if (first >= third && first <= fourth) counter++;
					else if (second >= third && second <= fourth) counter++;
					else if (third >= first && third <= second) counter++;
					else if (fourth >= first && fourth <= second) counter++;
				}
				return counter;
			}
		};
	}
}
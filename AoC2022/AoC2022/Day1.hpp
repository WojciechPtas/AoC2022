#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
namespace aoc {
	namespace day1 {
		class Solution {
		private:
		private:
			std::ifstream& m_file;
		public:
			Solution(std::ifstream& input_file) :  m_file(input_file) {}
			/// <summary>
			/// The goal is to calculate the biggest number of calories an elf is carrying
			/// </summary>
			/// <returns></returns>
			int solve() {
				if (!m_file.is_open()) return 0;
				std::string line;
				std::vector<int> calories;
				int curr{0};
				while (std::getline(m_file, line)) {
					if (line != "") {
						curr += std::stoi(line);
					}
					else {
						calories.push_back(curr);
						curr = 0;
					}
				}
				calories.push_back(curr);
				m_file.close();
				std::sort(calories.begin(), calories.end(),std::greater<int>());
				return calories[0]+calories[1]+calories[2];
			}
		};
	}
}

#include <fstream>
#include <iostream>
#include <unordered_map>
namespace aoc {
	namespace day2 {
		class Solution {
		private:
			std::ifstream& m_file;
		public:
			Solution(std::ifstream& a) : m_file(a) {};
			int solveFirst() {
				std::unordered_map<char, std::unordered_map<char, int>> rules;
				rules['A']['X'] = 4;
				rules['A']['Y'] = 8;
				rules['A']['Z'] = 3;
				rules['B']['X'] = 1;
				rules['B']['Y'] = 5;
				rules['B']['Z'] = 9;
				rules['C']['X'] = 7;
				rules['C']['Y'] = 2;
				rules['C']['Z'] = 6;

				char oponent, my;
				int score=0;
				while (m_file >> oponent >> my) {
					score += rules[oponent][my];
				}
				return score;
			}
			int solveSecond() {
				std::unordered_map<char, std::unordered_map<char, int>> rules;
				rules['A']['X'] = 3;
				rules['A']['Y'] = 4;
				rules['A']['Z'] = 8;
				rules['B']['X'] = 1;
				rules['B']['Y'] = 5;
				rules['B']['Z'] = 9;
				rules['C']['X'] = 2;
				rules['C']['Y'] = 6;
				rules['C']['Z'] = 7;

				char oponent, my;
				int score = 0;
				while (m_file >> oponent >> my) {
					score += rules[oponent][my];
				}
				return score;
			}
		};
	}
}
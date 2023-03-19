#include <iostream>
#include <vector>
#include "Solution.h"

namespace aoc {
	namespace day10 {
		class Solution : ISolution {
		
		public:
			Solution(std::ifstream& a) : ISolution(a) {};
			int solveFirst() {
				std::string command;
				int value;
				std::vector<int> tacts(1,1);
				while (m_file >> command) {
					if (tacts.size() == 220) {
						int i = 0;
					}
					if (command == "noop") {
						tacts.push_back(*(tacts.end() - 1));
					}
					else if (command == "addx") {
						tacts.push_back(*(tacts.end() - 1));
						m_file >> value;
						tacts.push_back(*(tacts.end() - 1)+value);
					}
					else {
						std::cout << "ERR";
					}
				}
				int i = -1;
				return tacts[20+i] * 20 + tacts[60+i] * 60 + tacts[100+i] * 100 + tacts[140+i] * 140 + tacts[180+i] * 180 + tacts[220+i] * 220;
			}
			void solveSecond()
			{
					std::string command;
					int value;
					std::vector<int> tacts(1, 1);
					while (m_file >> command) {
						if (tacts.size() == 220) {
							int i = 0;
						}
						if (command == "noop") {
							tacts.push_back(*(tacts.end() - 1));
						}
						else if (command == "addx") {
							tacts.push_back(*(tacts.end() - 1));
							m_file >> value;
							tacts.push_back(*(tacts.end() - 1) + value);
						}
						else {
							std::cout << "ERR";
						}
					}
					for (int i = 0; i < 6; i++) {
						for (int j = 0; j < 40; j++) {
							int curpos = 40 * i + j;
							if (j >= tacts[curpos] - 1 && j <= tacts[curpos] + 1) {
								std::cout << "#";
							}
							else {
								std::cout << " ";
							}
						}
						std::cout << std::endl;
					}
					//return tacts[20 + i] * 20 + tacts[60 + i] * 60 + tacts[100 + i] * 100 + tacts[140 + i] * 140 + tacts[180 + i] * 180 + tacts[220 + i] * 220;
			}
			
		};
	}
}
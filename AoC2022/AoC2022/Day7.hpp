

#include <unordered_map>
#include <string>
#include "Solution.h"

namespace aoc{
	namespace day7 {
		class Solution : ISolution {
			std::vector<int> size;
			int getSize(std::string name) {
				std::string line;
				int size{ 0 };
				while (std::getline(m_file, line)) {					
					if (line[0] == '$') {
						if (line[2] == 'c') {
							if (line[5] == '.') {
								this->size.push_back(size);
								return size;
							}
							else {
								size += this->getSize(std::string(line.begin() + 5, line.end()));
							}
						}
						else if (line[2] == 'l') {
							//READ
							continue;
						}	
					}
					else if (isdigit(line[0])) {
						std::string num = "";
						int i = 0;
						while (isdigit(line[i])) {
							num += line[i++];
						}
						size += std::stoi(num);						
					}
				}
				this->size.push_back(size);
				return size;
			}
		public:
			Solution(std::ifstream& a) : ISolution(a) {};
			int solveFirst() {
				int res{0};
				std::string line;
				std::getline(m_file, line);
				auto a = this->getSize("/");
				for (auto a : size) {
					if (a<= 100000) res += a;
				}
				return res;
			}
			int solveSecond() {
				int min{ INT_MAX };
				int sum = 0;
				std::string line;
				std::getline(m_file, line);
				auto a = this->getSize("/");
				sum = *(this->size.end() - 1);
				//int taken = 70000000 - sum;
				int to_free = 30000000 + sum - 70000000;
				for (auto a : size) {
					if (a >= to_free) {
						min = min < a ? min : a;
					}
				}
				return min;
			}
		};
}
}
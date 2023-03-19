
#include <fstream>
#include <string>
#include <iostream>
#include <unordered_map>
namespace aoc {
	namespace day3 {
		class Solution {
		private:
			std::ifstream& m_file;
		public:
			Solution(std::ifstream& a) : m_file(a) {};
			int solveFirst() {
				if (m_file.is_open()) {
					std::string line;
					int score = 0;
					while (std::getline(m_file, line)) {
						bool found = false;
						for (int i = 0; !found && i < line.size() / 2; i++) {
							if (std::end(line) != std::find(line.begin() + line.size() / 2, line.end(), line[i])) {
								found = true;
								if (isupper(line[i])) {
									score += line[i] - 38;
								}
								else {
									score += line[i] - 96;
								}
							}
						}
					}
					return score;
				}
			}
			int solveSecond() {
				if (m_file.is_open()) {
					std::string line1, line2, line3;
					int score = 0;
					while (std::getline(m_file, line1)) {
						bool found = false;
						std::getline(m_file, line2);
						std::getline(m_file, line3);
						for (int i = 0; !found && i < line1.size(); i++) {
							if (std::find(line2.begin(), line2.end(), line1[i]) != std::end(line2) && std::find(line3.begin(), line3.end(), line1[i]) != std::end(line3)) {
								found = true;
								if (isupper(line1[i])) {
									score += line1[i] - 38;
								}
								else {
									score += line1[i] - 96;
								}
							}
						}
					}
					return score;
				}
			};
		};
	}
}

#include <string>
#include <set>
#include "Solution.h"


namespace aoc {
	namespace day6 {
		class Solution : ISolution {
		public:
			Solution(std::ifstream& a) : ISolution(a) {};
			int solveFirst() {
				int i = 0;
				char _4{ 'a' }, _3{ 'a' }, _2{ 'a' }, _1{ 'a' };
				while (m_file >> _1) {
					i++;
					std::set<char> check;
					check.insert(_1);
					check.insert(_2);
					check.insert(_3);
					check.insert(_4);
					if (check.size() == 4 && i >3 ) return i;
					_4 = _3;
					_3 = _2;
					_2 = _1;
				}
				return 0;
			}
			int solveSecond() {
				std::vector<char> marker(14,'a');
				int i = 0;
				while (m_file >> marker[13]) {
					i++;
					std::set<char> check(marker.begin(), marker.end());
					if (check.size() == 14 && i > 14) return i;
					for (int j = 0; j < 13; j++) {
						marker[j] = marker[j + 1];
					}
				}
				return 0;
			}
		};
	}
}

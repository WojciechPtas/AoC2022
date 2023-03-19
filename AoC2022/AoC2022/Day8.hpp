#include <vector>
#include <string>
#include "Solution.h"


namespace aoc {
	namespace day8 {
		class Solution : ISolution {
			std::vector<std::vector<int>> map;
			void initMap() {
				std::string line;
				//std::vector<std::vector<int>> map;
				while (std::getline(m_file, line)) {
					std::vector < int> v;
					for (auto& a : line) {
						v.push_back(int(a) - 48);
					}
					this->map.push_back(v);
				}
			}
		public:
			Solution(std::ifstream& a) : ISolution(a) {};
			int solveFirst() {
				this->initMap();
				///
				int visible_trees{ 0 };
				visible_trees += 2 * map.size();
				visible_trees += 2 * map[0].size();
				visible_trees -= 4;
				for (int i = 1; i < map.size() - 1; ++i) {
					for (int j = 1; j < map[0].size() - 1; j++) {
						bool _1{0}, _2{0},_3{0},_4{0};
						for (int k = i+1; k <map.size(); k++) {
							if (map[k][j] >= map[i][j]) {
								_1 = true;
								break;
							}
						}
						
						for (int k = i -1; k >=0; k--) {
							if (map[k][j] >= map[i][j]) {
								_2 = true;
								break;
							}
						}
						//if (isvisible) {
						//	visible_trees++;
						//	continue;
						//}
						for (int k = j + 1; k < map[i].size(); k++) {
							if (map[i][k] >= map[i][j]) {
								_3 = true;
								break;
							}
						}
						
						for (int k = j-1; k >=0; k--) {
							if (map[i][k] >=map[i][j]) {
								_4 = true;
								break;
							}
						}
						if (!(_1 &&_2&&_3&& _4)) {
							
							//std::cout << " i: " << i << ", j: " << j << "  map[i][j]: " << map[i][j] << std::endl;
							visible_trees++;
						}
					}
				}
				return visible_trees;
			}
			int solveSecond() {
				this->initMap();
				int val{ 0 };
				for (int i = 1; i < map.size() - 1; i++) {
					for (int j = 1; j < map[0].size() - 1; j++) {
						std::vector<int> treesSeen(4, 0);
						std::vector<bool> isblocked(4, false);
						int index{0};
						for (int k = i+1; k < map.size(); k++) {
							treesSeen[index]++;
							if (map[k][j] >= map[i][j]) {
								break;
							}
						}
						index++;
						for(int k = i-1; k >=0 ; k--) {
							treesSeen[index]++;
							if (map[k][j] >= map[i][j]) {
								break;
							}
						}
						index++;
						for (int k = j + 1;  k < map[i].size(); k++) {
							treesSeen[index]++;
							if (map[i][k] >= map[i][j]) {
								break;
							}
						}
						index++;
						for (int k = j - 1; k >= 0; k--) {
							treesSeen[index]++;
							if (map[i][k] >= map[i][j]) {
								break;
							}
						}
						int curVal = treesSeen[0] * treesSeen[1] * treesSeen[2] * treesSeen[3];
						val = curVal > val ? curVal : val;
					}
				}
				return val;
			}
		};
	}
}
#include <iostream>
#include <set>
#include "Solution.h"
class V {
public:
	V() {
		x = 0;
		y = 0;
	};
	int x;
	int y;
};
namespace aoc {
	namespace day9 {
		class Solution : ISolution {
		public:
			Solution(std::ifstream& a) : ISolution(a) {};
			int solveFirst() {
				char direction;
				int step;
				V H;
				V T;
				std::set<std::pair<int, int>> visited;
				visited.insert({ 0,0 });
				while (m_file >> direction >> step) {
					V dir;
					if (direction == 'U') {
						dir.y = 1;
					}
					else if (direction == 'D') {
						dir.y = -1;
					}
					else if (direction == 'R') {
						dir.x = 1;
					}
					else if (direction == 'L') {
						dir.x = -1;
					}
					else {
						std::cout << "ERRROR\n";
					}

					// UPDATE
					for (int i = 0; i < step; i++)
					{
						H.x += dir.x;
						H.y += dir.y;
						int dist = (H.x - T.x) * (H.x - T.x) + (H.y - T.y) * (H.y - T.y);
						if (dist <= 2) continue;
						//Movement of tail
						if (H.x == T.x) {
							if (H.y > T.y) {
								T.y += 1;
							}
							else {
								T.y -= 1;
							}
						}
						else if (H.y == T.y) {
							if (H.x > T.x) {
								T.x += 1;
							}
							else {
								T.x -= 1;
							}
						}
						else { //diagonal case
							if (H.x > T.x) {
								if (H.y > T.y) {
									T.x += 1;
									T.y += 1;
								}
								else {
									T.x += 1;
									T.y += -1;
								}
							}
							else {
								if (H.y > T.y) {
									T.x += -1;
									T.y += 1;
								}
								else {
									T.x += -1;
									T.y += -1;
								}
							}
						}
						visited.insert({ T.x,T.y });


					}

				}
				m_file.close();
				return visited.size();
			}
			int solveSecond() {
				char direction;
				int step;
				std::vector<V> knots(10);
				//V knots[i-1];
				//V knots[i];
				std::set<std::pair<int, int>> visited;
				visited.insert({ 0,0 });
				while (m_file >> direction >> step) {
					V dir;
					if (direction == 'U') {
						dir.y = 1;
					}
					else if (direction == 'D') {
						dir.y = -1;
					}
					else if (direction == 'R') {
						dir.x = 1;
					}
					else if (direction == 'L') {
						dir.x = -1;
					}
					else {
						std::cout << "ERRROR\n";
					}

					// UPDAknots[i]E
					for (int i = 0; i < step; i++)
					{
						knots[0].x += dir.x;
						knots[0].y += dir.y;
						for(int i=1;i<10;++i){
							int dist = (knots[i-1].x - knots[i].x) * (knots[i-1].x - knots[i].x) + (knots[i-1].y - knots[i].y) * (knots[i-1].y - knots[i].y);
							if (dist <= 2) continue;
							//Movement of tail
							if (knots[i-1].x == knots[i].x) {
								if (knots[i-1].y > knots[i].y) {
									knots[i].y += 1;
								}
								else {
									knots[i].y -= 1;
								}
							}
							else if (knots[i-1].y == knots[i].y) {
								if (knots[i-1].x > knots[i].x) {
									knots[i].x += 1;
								}
								else {
									knots[i].x -= 1;
								}
							}
							else { //diagonal case
								if (knots[i-1].x > knots[i].x) {
									if (knots[i-1].y > knots[i].y) {
										knots[i].x += 1;
										knots[i].y += 1;
									}
									else {
										knots[i].x += 1;
										knots[i].y += -1;
									}
								}
								else {
									if (knots[i-1].y > knots[i].y) {
										knots[i].x += -1;
										knots[i].y += 1;
									}
									else {
										knots[i].x += -1;
										knots[i].y += -1;
									}
								}
							}
						}
						visited.insert({ knots[9].x,knots[9].y}); // we track last knot


					}

				}
				m_file.close();
				return visited.size();
			}
		};
	}
}

#include <string>
#include <stack>
#include "Solution.h"


namespace aoc {
	namespace day5 {
		class Solution : ISolution {
		public:
			Solution(std::ifstream& a) : ISolution(a) {};
			std::string solveFirst() {
				int amount, from, to;
				std::vector<std::stack<char>> stacks;
				std::string s;
				for (int i = 0; i < 9; i++) {
					std::stack<char> st;
					std::getline(m_file, s);
					for (auto a : s) {
						st.push(a);
					}
					stacks.push_back(st);
				}

				std::string words;
				while (m_file >> words >> amount >> words >> from >> words >> to) {
					from--;
					to--;
					for (int i = 0; i < amount; i++) {
						stacks[to].push(stacks[from].top());
						stacks[from].pop();
					}
				}
				std::string res = "";
				for (auto a : stacks) {
					res += a.top();
				}
				return res;
			}
			std::string solveSecond() {
				int amount, from, to;
				std::vector<std::stack<char>> stacks;
				std::string s;
				for (int i = 0; i < 9; i++) {
					std::stack<char> st;
					std::getline(m_file, s);
					for (auto a : s) {
						st.push(a);
					}
					stacks.push_back(st);
				}

				std::string words;
				while (m_file >> words >> amount >> words >> from >> words >> to) {
					from--;
					to--;
					std::stack<char> temp;
					for (int i = 0; i < amount; i++) {
						temp.push(stacks[from].top());
						stacks[from].pop();
					}
					for (int i = 0; i < amount; i++) {
						stacks[to].push(temp.top());
						temp.pop();
					}
				}
				std::string res = "";
				for (auto a : stacks) {
					res += a.top();
				}
				return res;
			}
		};
	}
}

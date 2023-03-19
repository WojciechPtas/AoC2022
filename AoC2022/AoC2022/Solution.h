#include <fstream>
#pragma once
class ISolution {
protected:
	std::ifstream& m_file;
public:
	ISolution(std::ifstream& input_file) : m_file(input_file) {};	
};

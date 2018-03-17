#pragma once
#include "Sort.h"
class RomanSort :
	public Sort
{
public:
	RomanSort();
	RomanSort(std::string fileDir) : Sort(fileDir) { typeName = "RomanSort"; };

	~RomanSort();

	void sort();

private:
	std::vector<int> * helperFieldA;
	std::vector<int> * helperFieldB;
};


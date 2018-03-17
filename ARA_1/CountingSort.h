#pragma once
#include "Sort.h"
class CountingSort :
	public Sort
{
public:
	CountingSort();
	CountingSort(std::string fileDir) : Sort(fileDir) { typeName = "CountingSort"; };

	~CountingSort();

	void sort();

private:
	std::vector<int> * helperFieldA;
	std::vector<int> * helperFieldB;
};


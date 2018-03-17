#include "stdafx.h"
#include "RomanSort.h"


RomanSort::RomanSort()
{
	typeName = "RomanSort";
}


RomanSort::~RomanSort()
{
}

void RomanSort::sort() {

	if (buffer.empty())
		return;

	findBufferValues();

	helperFieldA = new std::vector<int>(bufferMax - bufferMin + 1, 0);

	helperFieldB = new std::vector<int>(); // init with size causes trailing zeros
	helperFieldB->reserve(buffer.size()); // reserve instead


	for (int i = 0; i < buffer.size(); i++) {
		helperFieldA->at(buffer[i] - bufferMin) = helperFieldA->at(buffer[i] - bufferMin) + 1;
	}


	for (int i = bufferMin; i <= bufferMax; i++) {
		for (int j = helperFieldA->at(i - bufferMin); j > 0; j--) {
			helperFieldB->emplace_back(i);
		}
	}

	delete helperFieldA;

	buffer = *helperFieldB;
}

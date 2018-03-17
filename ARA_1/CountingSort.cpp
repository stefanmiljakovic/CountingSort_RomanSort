#include "stdafx.h"
#include "CountingSort.h"


CountingSort::CountingSort()
{
	typeName = "CountingSort";
}


CountingSort::~CountingSort()
{
}


void CountingSort::sort() {

	if (buffer.empty())
		return;

	findBufferValues();

	helperFieldA = new std::vector<int>(bufferMax - bufferMin + 1, 0);

	helperFieldB = new std::vector<int>(buffer.size());

	// Za vsako vrednost A[i] povečamo polje C z C[A[i]]=C[A[i]]+1.

	for (int i = 0; i < buffer.size(); i++) {
		helperFieldA->at(buffer[i] - bufferMin) = helperFieldA->at(buffer[i] - bufferMin) + 1;
	}

	// Seštejemo vrednosti polja C kot C[i]=C[i]+C[i-1] za i>0.

	for (int i = 1; i < helperFieldA->size(); i++) {
		helperFieldA->at(i) = helperFieldA->at(i) + helperFieldA->at(i - 1);
	}

	// Nato za vsako vrednost A[i] (od zadaj naprej) zapišemo izhod v B kot B[C[A[i]]-1] = A[i] 
	// in dekrementiramo C[A[i]]=C[A[i]]-1.

	for (int i = buffer.size() - 1; i >= 0; i--) {
		helperFieldB->at(helperFieldA->at(buffer[i] - bufferMin) - 1) = buffer[i];
		helperFieldA->at(buffer[i] - bufferMin)--;
	}

	delete helperFieldA;

	buffer = *helperFieldB;
}

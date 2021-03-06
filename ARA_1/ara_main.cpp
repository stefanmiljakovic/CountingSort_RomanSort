// ara_main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

#include "RomanSort.h"
#include "CountingSort.h"

#define START_ARGUMENT "vaja1"
#define OPTION_COUNTING '0'
#define OPTION_ROMAN '1'

using namespace std;

int main(int argc, char * argv[])
{
	cout << argv[1] << endl;

	if (strcmp(argv[1], START_ARGUMENT))
		return 0; // stop program if first argument doesn't match

	Sort * sortingAlg;

	switch (argv[2][0]) { // expecting 1 number

	case OPTION_COUNTING:
		sortingAlg = new CountingSort(argv[3]);
		break;
	case OPTION_ROMAN:
		sortingAlg = new RomanSort(argv[3]);
		break;
	default:
		cout << "No option selected ?";
		system("pause");
		return 0;
	}

	sortingAlg->sort();

	for each(int var in sortingAlg->getVector()) {
		cout << var << endl;
	}

	cout << endl << "Sorted by: " << sortingAlg->getTypeName() << ".\n\n";

	system("pause");
    return 0;
}


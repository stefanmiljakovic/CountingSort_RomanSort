#pragma once
#include <vector>

class Sort
{
public:
	Sort();
	Sort(std::string);
	~Sort();

	void assignVector(std::vector<int>&);
	void assignFile(std::string);
	std::vector<int> getVector() const;
	
	virtual void sort() = 0; // to be overriden by sorts

	std::string getTypeName();

protected:
	std::vector<int> buffer;

	void findBufferValues();

	int bufferMin, bufferMax;

	std::string typeName;

private:
	void populateFromFile(std::string);

	void findBufferMin();
	void findBufferMax();
	
};


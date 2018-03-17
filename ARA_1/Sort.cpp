#include "stdafx.h"
#include "Sort.h"

#include <fstream>
#include <string>
#include <stdexcept>
#include <algorithm>

Sort::Sort(){
	typeName = "Sort";
}

Sort::Sort(std::string fileDir) {
	assignFile(fileDir);
	typeName = "Sort";
}

Sort::~Sort(){

}

void Sort::assignVector(std::vector<int>& vect) {
	buffer.clear();
	this->buffer = vect;
}

void Sort::assignFile(std::string fileDir) {
	buffer.clear();
	populateFromFile(fileDir);
}

std::vector<int> Sort::getVector() const{
	return this->buffer;
}

void Sort::populateFromFile(std::string fileDir) {

	std::ifstream file(fileDir);

	if (file.is_open()) {
		std::string numberBuffer;

		while (std::getline(file, numberBuffer, ' ')) {
			try {
				buffer.emplace_back(std::stoi(numberBuffer));
			}
			catch (const std::invalid_argument& e) {
				throw std::invalid_argument("One of the entries is not a number?");
			}
		}
	}

}

void Sort::findBufferMax() {
	bufferMin = *std::min_element(buffer.begin(), buffer.end());
}

void Sort::findBufferMin() {
	bufferMax = *std::max_element(buffer.begin(), buffer.end());
}

void Sort::findBufferValues() {
	findBufferMax();
	findBufferMin();
}

std::string Sort::getTypeName() {
	return this->typeName;
}
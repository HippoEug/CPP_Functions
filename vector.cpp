#include <iostream>
#include <algorithm>
#include <vector>

// Pass by reference
void printIntVec(std::vector<int>& intVec) {
	for (int i = 0; i < intVec.size(); i++) {
		std::cout << intVec[i] << " ";
	}
}

void printBoolVec(std::vector<bool>& boolVec) {
	for (int i = 0; i < boolVec.size(); i++) {
		std::cout << boolVec[i] << " ";
	}
}

int main() {
	std::cout << "C++ Vector Code" << std::endl;
	std::cout << "===============" << std::endl;

	// Create a vector
	std::vector<int> intVec;
	std::vector<bool> boolVec;

	// Add some values to the vectors
	intVec.push_back(4);
	intVec.push_back(3);
	intVec.push_back(2);
	intVec.push_back(1);

	boolVec.push_back(true);
	boolVec.push_back(true);
	boolVec.push_back(false);
	boolVec.push_back(false);

	// Print the unsorted vector.
	std::cout << "Unsorted vector: " << std::endl;
	printIntVec(intVec);
	std::cout << std::endl;
	printBoolVec(boolVec);
	std::cout << std::endl << std::endl;

	// Sort the vector using std's sort.
	std::sort(intVec.begin(), intVec.begin() + intVec.size());
	std::sort(boolVec.begin(), boolVec.begin() + boolVec.size());

	// Print the sorted vector.
	std::cout << "Sorted vector: " << std::endl;
	printIntVec(intVec);
	std::cout << std::endl;
	printBoolVec(boolVec);
	std::cout << std::endl << std::endl;

	std::cin.get();
	std::cin.ignore();
}

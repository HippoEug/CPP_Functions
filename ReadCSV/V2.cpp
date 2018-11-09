#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
	char eater;
	float temp;

	std::vector<float> results;

	std::ifstream coordinatesFile;
	coordinatesFile.open("test2.csv_Depth_3068.csv");

	for (int i = 0; i < 1280; i++) {
		coordinatesFile >> temp;
		results.push_back(temp);
		coordinatesFile >> eater;
	}

	for (int i = 0; i < 1280; i++) {
		std::cout << results[i] << " ";
	}

	coordinatesFile.close();
	std::cin.get();
	std::cin.ignore();
}

#include <iostream>
#include <fstream>
#include <chrono>

int main() {
	char i;
	int x = 0;
	int y = 0;
	int percent = 10;

	std::ofstream myfile;
	myfile.open("test.csv");

	std::cout << "Start operation? (y/n):";
	std::cin >> i;

	if (i == 'y') {
		std::cout << "Calculating..." << std::endl;

		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
		myfile << "x,y,depth\n";

		do {
			for (int x = 0; x < 1280; x++) {
				myfile << x << "," << y << "," << "c\n";
			}
			y++;

			if (y % 72 == 0) {
				std::cout << "Status: " << percent << "%" << std::endl;
				percent+=10;
			}

		} while (y < 720);

		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
		std::cout << "\nDONE" << std::endl;
		std::cout << "The operation took: " << duration << "ms" << std::endl;
	}

	myfile.close();

	std::cin.get();
	std::cin.ignore();
}

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <chrono>

template <class T, size_t W, size_t H>
class Array2D {
public:
	const int width = W;
	const int height = H;
	typedef typename T type;
	
	Array2D() {
		buffer.resize(width*height);
	}

	T& operator() (int x, int y) {
		return buffer[y*width + x];
	}

	const T& operator() (int x, int y) const {
		return buffer[y*width + x];
	}

private:
	std::vector<T> buffer;
};

int main() {
	char eater;
	int xs, ys;

	//Array2D<double, 1281, 721> a;
	Array2D<double, 1280, 720> a;

	std::ifstream coordinatesFile;
	coordinatesFile.open("test2.csv_Depth_3068.csv");

	std::cout << "COPYING" << std::endl;

	/*
	for (int y = 1; y < 720; y++) {
		for (int x = 1; x < 1280; x++) {
			coordinatesFile >> a(x, y);
			coordinatesFile >> eater;
		}
		coordinatesFile >> eater;
	}
	
	for (int y{}; y < 720; ++y)
		for (int x{}; x < 1280; ++x)
			coordinatesFile >> a(x, y) >> std::noskipws >> eater >> std::skipws;
	*/

	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	for (int y{}; y < 720; ++y) {
		for (int x{}; x < 1280; ++x) {
			if (!(coordinatesFile >> a(x, y) >> std::noskipws >> eater >> std::skipws)
				&& !coordinatesFile.eof() && eater != ',' && eater != '\n')
			{
				std::cerr << "Format error at " << x + 1 << '/' << y + 1 << " :(\n\n";
				return EXIT_FAILURE;
			}
		}
	}
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	std::cout << "The operation took: " << duration << "ms" << std::endl;

	while (1) {
		std::cout << "Enter X val: ";
		std::cin >> xs;
		std::cout << "Enter Y val: ";
		std::cin >> ys;

		std::cout << "Value = " << a(xs - 1, ys - 1) << std::endl;
	}

	coordinatesFile.close();
	std::cin.get();
	std::cin.ignore();
}

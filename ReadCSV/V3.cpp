#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

template <class T, size_t W, size_t H>
class Array2D {
public:
	const int width = W;
	const int height = H;
	typedef typename T type;
	
	Array2D() {
		buffer.resize(width*height);
	}

	const T &operator() (int x, int y) const {
		return buffer[y*width + x];
	}

	T &operator() (int x, int y) {
		return buffer[y*width + x];
	}

private:
	std::vector<T> buffer;
};

int main() {
	int percent = 0;
	char eater;
	double temp;
	int x = 1;
	int y = 1;

	int xs, ys;

	Array2D<double, 1281, 721> a;

	std::ifstream coordinatesFile;
	coordinatesFile.open("test2.csv_Depth_3068.csv");

	std::cout << "COPYING" << std::endl;

	for (int y = 1; y < 720; y++) {
		for (int x = 1; x < 1280; x++) {
			coordinatesFile >> temp;
			a(x, y) = temp;
			coordinatesFile >> eater;
		}
		coordinatesFile >> eater;
	}

	while (1) {
		std::cout << "Enter X val: ";
		std::cin >> xs;
		std::cout << "Enter Y val: ";
		std::cin >> ys;

		std::cout << "Value = " << a(xs, ys) << std::endl;
	}

	coordinatesFile.close();
	std::cin.get();
	std::cin.ignore();
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <boost/algorithm/string.hpp>

/*
struct XYZCoordinates {
	int x;
	int y;
	float z;
	friend std::istream& operator >> (std::istream& in, XYZCoordinates &xyz) {
		float a, b;
		in >> a >> b >> xyz.z;
		xyz.x = std::rint(a);
		xyz.y = std::rint(b);
		return in;
	}
};
class Coordinates {
public:
	friend std::ostream& operator << (std::ostream&out, const Coordinates &c) {
		return out << "[ " << c.xmin << ", " << c.xmax << "], [" << c.ymin << ", " << c.ymax << "], with " << c.values.size() << " points" << std::endl;
	}
	friend std::istream& operator >> (std::istream& in, Coordinates &c) {
		while (in.peek == '#') {
			in, ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		
		XYZCoordinates xyz;
		while (in >> xyz) {
			c.values.push_back(xyz);
			c.xmin = std::min<int>(c.xmin, xyz.x);
			c.xmax = std::max<int>(c.xmax, xyz.x);
			c.ymin = std::min<int>(c.xmin, xyz.y);
			c.ymax = std::max<int>(c.xmax, xyz.y);
		}
		return in;
	}
private:
	int xmin;
	int xmax;
	int ymin;
	int ymax;
	std::vector<XYZCoordinates> values;
};
*/

int main() {
	std::string line, csvItem;
	int lineNumber = 0;
	int lineNumberSought = 0;
	int x, y, z;

	int count = 1;

	std::ifstream coordinatesFile;
	coordinatesFile.open("test2.csv_Depth_3068.csv");

	if (coordinatesFile.is_open()) {
		std::cout << "File Opened Successfully" << std::endl;

		//std::cout << "Enter x-coordinate: ";
		//std::cin >> x;
		//std::cout << "Enter y-coordinate: ";
		//std::cin >> y;

		while (coordinatesFile.good()) {
			if (count % 10000 == 0) {
				std::cout << count << std::endl;
			}

			count++;
		}
	}
	else {
		std::cout << "File NOT Opened Successfully" << std::endl;
	}

	coordinatesFile.close();
	std::cin.get();
	std::cin.ignore();
}

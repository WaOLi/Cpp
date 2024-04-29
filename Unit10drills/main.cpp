#include <iostream>
#include <vector>
#include <fstream>

struct Point
{
	Point(int X, int Y);
	int x, y;
};

std::ostream& operator<<(std::ostream& os, const Point& p)
{
	return os << "x: " << p.x << ", y: " << p.y << std::endl;
}
std::istream& operator>>(std::istream& is, Point& p)
{
	is >> p.x >> p.y;
	return is;
}



std::vector<Point> original_points;
std::vector<Point> processed_points;

int main()
{
	for (int i{}, _x, _y; i < 7; i++)
	{
		std::cout << "Enter new Point: ";
		std::cin >> _x >> _y;
		original_points.push_back(Point(_x, _y));
	}

	std::ofstream ofs{ "mydata.txt" };
	if (!ofs)
	{
		std::cerr << "couldn't get the file to open";
	}
	else
	{
		for (Point p : original_points)
		{
			ofs << p.x << " " << p.y << std::endl;
		}
	}
	ofs.close();


	std::ifstream ifs{ "mydata.txt" };
	if (!ifs)
	{
		std::cerr << "couldn't open ifs";
	}
	else
	{
		for (Point p{ 0,0 }; ifs >> p;)
		{
			processed_points.push_back(p);
		}
	}
	for (Point p : processed_points)
	{
		std::cout << p;
	}
	for (Point p : original_points)
	{
		std::cout << p;
	}
}

Point::Point(int X, int Y)
	:x{X}, y{Y}{}

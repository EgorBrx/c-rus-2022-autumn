#include <iostream>

struct Point {
	int x;
	int y;

	Point(int x = 0, int y = 0) : x(x), y(y) {}

	Point(const Point& m) :x(m.x), y(m.y) {};

	~Point() {};

	double Distance()
	{
		return(sqrt(x * x + y * y));
	}

	void PrintPoint()
	{
		std::cout << x << ' ' << y << std::endl;
	}
};

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	std::cout << std::endl;

	Point* a = (Point*)malloc(n * sizeof(Point));

	for (int i = 0; i < n; ++i)
	{
		Point point;
		std::cin >> point.x >> point.y;
		a[i] = point;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = n - 1; j > i; --j)
		{
			if (a[j - 1].Distance() > a[j].Distance())
			{
				Point temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		a[i].PrintPoint();
	}
	free(a);
	return EXIT_SUCCESS;
}
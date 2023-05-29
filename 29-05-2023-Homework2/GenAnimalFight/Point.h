#pragma once
#include <iostream>
class Point
{
private:
	int x;
	int y;
public:
	Point(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}
	Point(const Point& p)
	{
		x = p.x;
		y = p.y;    // для примера]

	}
	~Point()

	{
		//std::cout << "point deleted\n";
	}
	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}
	int SetX(int x)
	{
		this->x = x;
		return x;
	}
	int SetY(int y)
	{
		this->y = y;
		return y;
	}
	Point operator+(Point point2)
	{
		return Point(x + point2.GetX(), y + point2.GetY());
	}
	friend std::ostream& operator<<(std::ostream& stream, Point p)
	{
		stream << p.GetX() << ", " << p.GetY();
		return stream;
	}
};

#include <iostream>
struct Shape
{
public:
	int a;
	int b;
	int c;
	int d;

	Shape(int a = 0, int b = 0, int c = 0, int d = 0) : a(a), b(b), c(c), d(d) {};
	Shape(const Shape& sh) : a(sh.a), b(sh.b), c(sh.c), d(sh.d) {};
	~Shape() {};
};

struct Triangle : public Shape
{
	Triangle(int a = 0, int b = 0, int c = 0) : Shape(a, b, c) {};

	float area()
	{
		float half_per = 0.5 * (a + b + c);
		return sqrt(half_per * (half_per - a) * (half_per - b) * (half_per - c));
	}

	~Triangle() {};
};

struct Rectangle : public Shape
{
	Rectangle(int a = 0, int b = 0) : Shape(a, b) {};

	float area()
	{
		return a * b;
	}

	~Rectangle() {}
};

struct Square : public Rectangle
{
	Square(int a = 0) : Rectangle(a, a) { };
	~Square() {};
};

struct Circle : public Shape
{
	Circle(int a = 0) : Shape(a) {};

	float area()
	{
		return (3.14) * (a * a);
	}

	~Circle() {};
};


int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	std::cin >> a >> b >> c;

	Triangle triang = Triangle(a, b, c);
	std::cout << "Triangle area is " << triang.area() << std::endl;

	Rectangle rect = Rectangle(a, b);
	std::cout << "Rectangle area is " << rect.area() << std::endl;

	Square square = Square(a);
	std::cout << "Square area is " << square.area() << std::endl;

	Circle circle = Circle(a);
	std::cout << "Circle area is " << circle.area() << std::endl;

	return EXIT_SUCCESS;
}
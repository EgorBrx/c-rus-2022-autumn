#include<iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	std::cin >> a >> b;
	std::cout << a << " + " << b << " = " << a + b << std::endl;

	char c = 0;
	short s = 0;
	int i = 0;
	long l = 0;
	long long ll = 0;

	unsigned char uc = 0;
	unsigned short us = 0;
	unsigned int ui = 0;
	unsigned long ul = 0;
	unsigned long long ull = 0;

	float f = 0.5f;
	double d = 0.5;
	bool bb = true;

	a = a + b;
	a = a - b;
	a = a * b;
	a = a / b;
	a = a % b;
	a = a | b;
	a = a & b;
	a = a ^ b;
	b = ~a;
	a = b >> 3; // /1000
	b = a << 2; // *100

	bb = !bb;
	bb = a && b;
	bb = a || b;
	bb = a == b;
	bb = a != b;
	bb = a <= b;
	bb = a >= b;
	bb = a < b;
	bb = a > b;

	a = 13;
	b = 6;
	c = a & b; //and
			   //a      = 13_10 = 1101_2
			   //b      =  6_10 = 0110_2
			   //a & b  =  4_10 = 0100_2

	c = a && b; //and
				//a 	 = 13_10 = 1101_2
				//b 	 =  6_10 = 0110_2
				//a && b =  true =    1_2

	std::cout << (1 && 5) << " " << (1123 && 0) << " " << std::endl;
	std::cout << (1 || 5) << " " << (1123 || 0) << " " << std::endl;
				
	std::cout << (1 & 5) << " " << (1123 & 0) << " " << std::endl;
	std::cout << (1 | 5) << " " << (1123 | 0) << " " << std::endl;

	c = a | b; //or
			   //a      = 13_10 = 1101_2
			   //b      =  6_10 = 0110_2
			   //a | b  = 15_10 = 1111_2

	c = a || b; //or
				//a 	 = 13_10 = 1101_2
				//b 	 =  6_10 = 0110_2
				//a || b = true  =    1_2

	c = a ^ b; //xor
			   //a      = 13_10 = 1101_2
			   //b      =  6_10 = 0110_2
			   //a ^ b  = 11_10 = 1011_2

	c = !a; //not
			//a 	 = 13_10 = 1101_2
			//!a 	 = false =    0_2

	c = ~a; //inverse
			//a 	 = 13_10 = 1101_2
			//~a     =  2_10 = 0010_2

	c = a >> 2; //right bit shift
				//a 	 = 13_10 = 0000 1101_2
				//a >> 2 =  3_10 = 0000 0011_2

	c = a << 2; //left bit shift
				//a 	 = 13_10 = 0000 1101_2
				//a << 2 = 52_10 = 0011 0100_2

	return EXIT_SUCCESS;
}
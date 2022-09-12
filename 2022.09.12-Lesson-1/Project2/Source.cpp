#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	
	cin >> a >> b;

	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	cout << a << " * " << b << " = " << a * b << endl;
	cout << a << " / " << b << " = " << a / b << endl;
	cout << a << " % " << b << " = " << a % b << endl;
	cout << a << " // " << b << " = " << 1.0f * a / b << endl;
	cout << a << " // " << b << " = " << (float) a / b << endl;

	char c = 0;
	int i = 0;
	long l = 0;
	long long ll = 0; // -2^63 .. 2^63 - 1

	unsigned char cc = 0;
	unsigned int ii = 0;
	unsigned long lll = 0;
	unsigned long long llll = 0;// 0 .. 2^64

	float f = 0.5f;
	double d = 0.5;

	f = 1.5f;

	//c-style input/output
	scanf("%d", &a); //считывание переменной a
	scanf("%d", &b); //считывание переменной b
	printf("%d + %d = %d\n", a, b, a + b);

	return EXIT_SUCCESS;
}
#include <iostream>
#include <string>

struct Student {
private:
	std::string name;
	std::string surname;
	int m1;
	int m2;
	int m3;
public:

	Student(std::string name = "Vasya", std::string surname = "Ivanov", int m1 = 0, int m2 = 0, int m3 = 0) :
		name(name), surname(surname), m1(m1), m2(m2), m3(m3) {};

	Student(const Student& st) :
		name(st.name), surname(st.surname), m1(st.m1), m2(st.m2), m3(st.m3) {};

	~Student() {};

	int Sum()
	{
		return(m1 + m2 + m3);
	}

	void PrintSt()
	{
		std::cout << name << ' ' << surname << std::endl;
	}
};

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	std::cout << std::endl;

	Student* st = new Student[n];

	std::string name;
	std::string sname;
	int m;
	int ph;
	int inf;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> name;
		std::cin >> sname;
		std::cin >> m;
		std::cin >> ph;
		std::cin >> inf;
		st[i] = Student(name, sname, m, inf, ph);
	}

	for (int i = 0; i < n; ++i) //sort
	{
		for (int j = n - 1; j > i; --j)
		{
			if (st[j - 1].Sum() < st[j].Sum())
			{
				Student temp = st[j - 1];
				st[j - 1] = st[j];
				st[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		st[i].PrintSt();
	}

	delete[] st;
	return EXIT_SUCCESS;
}
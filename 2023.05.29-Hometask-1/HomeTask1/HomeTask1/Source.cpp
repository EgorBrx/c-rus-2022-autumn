#include <iostream>
#include <string>

struct Animal
{
	std::string type;
	std::string name;
	int age;

	Animal(std::string type = "cat", std::string name = "Vasya", int age = 3)
	{
		this->type = type;
		this->name = name;
		this->age = age;
	}

	Animal(const Animal& beast)
	{
		this->type = beast.type;
		this->name = beast.name;
		this->age = beast.age;
	}

	~Animal()
	{
	}
};

void printAnimal(Animal beast)
{
	std::cout << "It\'s name is " << beast.name << '.' << std::endl;
	std::cout << beast.name << " is " << beast.type << '.' << std::endl;
	std::cout << "It is " << beast.age << " years old." << std::endl;
}

void ElderAnimal(Animal& beast)
{
	beast.age ++;
}

int main(int argc, char* argv[])
{
	Animal beast;
	ElderAnimal(beast);
	printAnimal(beast);
	return EXIT_SUCCESS;
}
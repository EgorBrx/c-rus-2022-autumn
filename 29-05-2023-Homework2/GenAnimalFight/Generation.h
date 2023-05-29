#pragma once
#include "Animal.h"



class Generation
{
private:
	Animal** Animals;
	int count = 0;
	int lived = 0;
public:
	void Import(int fileNum);
	Generation(int count = 100);
	void fillRandom();
	void Print(std::ostream& stream, bool isAll);
	int GetSize();
	int GetLived();///удалить
	Animal* GetAnimal(int id);
	bool GetGen();
	bool GetAnimalStatus(int id);
	void CreateNewGeneration();
	~Generation();
	friend std::ostream& operator<<(std::ostream& stream, Generation& gen)
	{
		gen.Print(stream, false);
		return stream;
	}
	void AddAnimal(Animal& beast);
	void Import(std::string fileName);
	void Extract(int fileNum);
	void Extract(std::string fileName);
};






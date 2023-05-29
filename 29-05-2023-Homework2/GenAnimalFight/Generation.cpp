#pragma once
#include "Generation.h"


void Generation::fillRandom()
{
	for (int i = lived; i < count; i++)
	{
		Animals[i] = GetRandomAnimal();
		this->lived++;

	}
}
int Generation::GetSize()
{
	return count;
}
int Generation::GetLived()
{
	return this->lived;////////удалить
}
Animal* Generation::GetAnimal(int id)
{
	return Animals[id];
}
bool Generation::GetGen()
{
	return 1;
}

void Generation::CreateNewGeneration()
{
	int countParents = this->lived;
	assert(countParents != 0);
	for (int i = countParents; i < count; i++)
	{
		Animals[i] = Animals[i % countParents]->Mutation();

	}
}
Generation::~Generation()
{
	for (int i = 0; i < this->GetSize(); i++)
	{
		delete Animals[i];
	}
	delete[] Animals;
};

void Generation::AddAnimal(Animal& beast)
{
	Animals[lived] = &beast;

	lived++;
}

Generation::Generation(int count)
{
	static int i = 0;
	Animals = new Animal*[count];
	for (int i = 0; i < count; i++)
	{
		Animals[i] = nullptr;
	}
	this->lived = 0;
	this->count = count;
	i++;
}

void Generation::Print(std::ostream& stream, bool isAll = false)
{
	if (!isAll)
	{
		for (int j = 0; j < countParentinGen; j++)
		{
			Animal* maxlivetime = this->GetAnimal(0);
			for (int i = 0; i < this->GetSize(); i++)
			{
				if (this->GetAnimal(i)->GetLivetime() > maxlivetime->GetLivetime())
				{
					maxlivetime = this->GetAnimal(i);
				}
			}
			if (!maxlivetime->GetDeadStatus())
			{
				maxlivetime->SetDeadReason("No death");
			}
			stream << j << ":\n" << *maxlivetime;
			maxlivetime->SetLiveTime(-1);
		}
	}
	else
	{
		for (int i = 0; i < this->GetSize() && Animals[i] != nullptr; i++)
		{
			stream << i << ":\n" << *Animals[i];
		}
	}
}
void Generation::Import(std::string fileName)
{
	std::string str[15];
	std::ifstream file;
	Animal* current = nullptr;
	int numAnimals = 0;
	file.open(fileName);
	for (int i = 0; !file.eof() && i < 9; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			getline(file, str[j]);
		}
		if (str[0] != "")
		{
			current = GetAnimalById(str[1], str[2], str[3], str[4]);
			this->AddAnimal(*current);
			numAnimals++;
		}
	}
	file.close();
}
void Generation::Import(int fileNum)
{
	std::ifstream file;
	const std::string txt = ".txt";
	std::string fileName = "Generations/gen" + std::to_string(fileNum) + txt;
	this->Import(fileName);
}
void Generation::Extract(std::string fileName)
{
	std::ofstream file;
	file.open(fileName);
	file << *this;
	file.close();
}
void Generation::Extract(int fileNum)
{
	const std::string txt = ".txt";
	std::string fileName = "Generations/gen" + std::to_string(fileNum) + txt;
	std::ofstream file;
	file.open(fileName);
	file << *this;
	file.close();
}

#pragma once
#include "Animal.h"
#include "Cell.h"
#include "Field.h"
#include "Generation.h"

Field::Field()
{
	Cells = new Cell * *[GetSize()];
	for (int i = 0; i < GetSize(); i++)
	{
		Cells[i] = new Cell * [GetSize()];
	}
	for (int i = 0; i < this->GetSize(); i++)
	{
		for (int j = 0; j < this->GetSize(); j++)
		{
			Point p(i, j);
			Cells[i][j] = GetRandomCell(p, Cells);
		}
	}
};
Field::~Field()
{
	for (int i = 0; i < this->GetSize(); i++)
	{
		for (int j = 0; j < this->GetSize(); j++)
		{
			delete Cells[i][j];
		}
	}
	for (int i = 0; i < GetSize(); i++)
	{
		delete[] Cells[i];
	}
	delete[] Cells;
};
Cell* Field::GetCell(Point& p)
{
	return Cells[p.GetX()][p.GetY()];
}
int Field::GetSize()
{
	return size;
}
void Field::Clear()
{
	for (int i = 0; i < this->GetSize(); i++)
	{
		for (int j = 0; j < this->GetSize(); j++)
		{
			Cells[i][j]->Clear();
		}
	}
}

void Field::IncreaseDeadZone()
{

	/*
	* 		for (int j = ZoneSize; j < GameSize - ZoneSize - 1; j++)
		{
			Cells[ZoneSize][j].dead();
		}
		for (int i = ZoneSize; i < GameSize - ZoneSize - 1; i++)
		{
			Cells[i][ZoneSize].dead();
		}
		for (int i = ZoneSize; i < GameSize - ZoneSize - 1; i++)
		{
			Cells[i][GameSize - ZoneSize - 1].dead();
		}
		for (int j = ZoneSize; j < GameSize - ZoneSize; j++)
		{
			Cells[GameSize - ZoneSize - 1][j].dead();
		}
	*/
	ZoneSize++;
}
void Field::Refresh()
{
	ZoneSize = 0;
	this->RandomSetting();

}


void Field::RandomSetting(int randomPoint)
{
	try
	{
		for (int i = 0; i < randomPoint; i++)
		{
			int x = GetRandomInt(0, this->GetSize() - 1);
			int y = GetRandomInt(0, this->GetSize() - 1);
			Cells[x][y]->RandomSetting();
		}
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
void Field::Print(std::ostream& stream, Field& field)
{

	for (int i = 0; i < GameSize; i++)
	{
		for (int j = 0; j < GameSize; j++)
		{
			Cells[i][j]->printCell(stream);
		}
		stream << std::endl;
	}
}
void Field::AddAnimal(Animal* beast, Point& p)
{
	if (!isCorrectPoint(p, *this))
	{
		return;
	}
	Cells[p.GetX()][p.GetY()]->AddAnimal(beast);
}
void Field::ImportGeneration(Generation& gen)
{
	int* C = new int[GameSize * GameSize];
	for (int i = 0; i < GameSize * GameSize; i++)
	{
		C[i] = i;
	}
	ShuffleArray(C, GameSize * GameSize);
	for (int i = 0; i < gen.GetSize(); i++)
	{
		Animal* A = gen.GetAnimal(i);
		Point p(C[i] / GameSize, C[i] % GameSize);
		A->SetPoint(p);
		AddAnimal(A, p);
		assert(!A->GetDeadStatus());
	}
	delete[] C;
}

void Field::AddFood(int countFood2)
{
	int* C = new int[GameSize * GameSize];
	int sizeArray = 0;
	for (int i = 0; i < GameSize * GameSize; i++)
	{
		Point p = Point(i / GameSize, i % GameSize);
		if (this->GetCell(p)->GetTypeId() == empty)
		{
			C[sizeArray] = i;
			sizeArray++;
		}
	}
	ShuffleArray(C, sizeArray);
	//std::cout <<"sizeArray = " << sizeArray << std::endl;
	for (int i = 0; i < countFood2 && i < sizeArray; i++)
	{

		Point p = Point(C[i] / GameSize, C[i] % GameSize);
		replaceCell(p, Cells, food);
	}
	delete[] C;
}

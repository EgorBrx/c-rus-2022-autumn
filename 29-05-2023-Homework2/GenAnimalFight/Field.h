#pragma once
#include <iostream>
#include "Point.h"

class Animal;
class Generation;
class Cell;
extern const int GameSize;

class Field
{
private:
	Cell*** Cells;
	int ZoneSize = 0;
	int size = GameSize;
	void Print(std::ostream& stream, Field& beast);
public:
	Field();
	~Field();
	Cell* GetCell(Point& p);
	void Clear();
	int  GetSize();
	void RandomSetting(int randomPoint = GameSize * 45);
	void AddFood(int countFood2);
	void ImportGeneration(Generation&);
	void AddAnimal(Animal* beast, Point& p);
	void IncreaseDeadZone();
	void Refresh();
	void Print(std::ofstream& stream, Field& field);
	friend std::ostream& operator<<(std::ostream& stream, Field& field)
	{
		field.Print(stream, field);
		return stream;
	}

};




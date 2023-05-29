#pragma once
#include <string>
#include <iostream>
#define deadzone -1
#define empty 0
#define food 1
#define bone 2
#define cliff 3
#define zagluska 4
#define supermeat 5
const int         coutCellsType = 5;
class Field;
class Animal;
class Cell;
Cell* GetRandomCell(Point p, Cell*** Cells);
void replaceCell(Point p, Cell*** Cells);
void replaceCell(Point p, Cell*** Cells, int typeId);
class Cell
{
private:
	std::string mark = "-";
	Cell*** Cells = nullptr;
public:
	Animal* inAnimal = nullptr;
	Point p;
	int typeId = -10;
	std::string virtual GetMark() { return mark; };
	Cell(Point p, Cell*** Cells = nullptr)
	{
		this->p = Point(p);
		this->Cells = Cells; //////костыль
	}
	Point GetPoint()
	{
		return p;
	}
	void SetTypeId(int n) { typeId = n; };
	void SetMark(std::string mark) { this->mark = mark; };
	void printCell(std::ostream& stream);
	int GetTypeId();
	void virtual Clear()
	{
		replaceCell(this->GetPoint(), Cells);
	};
	void virtual AddAnimal(Animal* beast);
	void virtual OnEnter(Animal* beast) = 0;
	void virtual OnLeave(Animal* beast = nullptr)
	{
		this->Clear();
	}
	void RandomSetting()
	{
		replaceCell(p, Cells, GetRandomInt(0, coutCellsType + 3));
	}
	virtual ~Cell() { };
};
class C_Cliff : public Cell
{
private:
	const int typeId = cliff;
	const std::string mark = "3";
public:
	int GetTypeId()
	{
		return typeId;
	}
	std::string GetMark()
	{
		return mark;
	}
	void OnEnter(Animal* beast);
	C_Cliff(Point p, Cell*** Cells) : Cell(p, Cells) {
		this->SetMark(mark);
		this->SetTypeId(typeId);
	}
	~C_Cliff() 
	{
	}
};
class C_Supermeat : public Cell
{
private:
	const int typeId = food;
	const std::string mark = "5";
public:
	int GetTypeId()
	{
		return typeId;
	}
	void OnEnter(Animal* beast);
	C_Supermeat(Point p, Cell*** Cells) : Cell(p, Cells) {
		this->SetMark(mark);
		this->SetTypeId(typeId);
	}
	~C_Supermeat()
	{
	}
};
class C_Zagluska : public Cell
{
private:
	const int typeId = zagluska;
	const std::string mark = "4";
public:
	int GetTypeId()
	{
		return typeId;
	}
	void OnEnter(Animal* beast)
	{
		AddAnimal(beast);
	}
	C_Zagluska(Point p, Cell*** Cells) : Cell(p, Cells) {
		this->SetMark(mark);
		this->SetTypeId(typeId);
	}
	~C_Zagluska() {};
};
class C_Empty : public Cell
{
private:
	const int typeId = empty;
	const std::string mark = "*";
public:
	int GetTypeId()
	{
		return typeId;
	}
	void OnEnter(Animal* beast)
	{
		AddAnimal(beast);
	}
	C_Empty(Point p, Cell*** Cells) : Cell(p, Cells) {
		this->SetMark(mark);
		this->SetTypeId(typeId);
	}
	~C_Empty() 
	{
	}
};
class C_Food : public Cell
{
private:
	const int typeId = food;
	const std::string mark = "1";
public:
	int GetTypeId()
	{
		return typeId;
	}
	void OnEnter(Animal* beast);
	C_Food(Point p, Cell*** Cells) : Cell(p, Cells) {
		this->SetMark(mark);
		this->SetTypeId(typeId);
	}
	~C_Food() 
	{
	};
};
class C_Bone : public Cell
{
private:
	const int typeId = bone;
	const std::string mark = "2";
public:
	int GetTypeId()
	{
		return typeId;
	}
	void OnEnter(Animal* beast)
	{
		AddAnimal(beast);
		///beast->IncreaseHunger();
	}
	C_Bone(Point p, Cell*** Cells) : Cell(p, Cells) {
		this->SetMark(mark);
		this->SetTypeId(typeId);
	}
	~C_Bone() 
	{
	};
};
Cell* GetRandomCell(Point p, Cell*** Cells);
Cell* GetCellByTypeId(Point p, Cell*** Cells, int celltype);
void replaceCell(Point p, Cell*** Cells);
void replaceCell(Point p, Cell*** Cells, int typeId);








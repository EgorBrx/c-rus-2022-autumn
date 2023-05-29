#pragma once
#include "Animal.h"
#include "Cell.h"
#include "Field.h"

void Cell::AddAnimal(Animal* beast)
{
	inAnimal = beast;
	beast->SetPoint(p);
};
void C_Food::OnEnter(Animal* beast)
{
	AddAnimal(beast);
	beast->IncreaseEat();
	beast->DescreaseHunder(foodEfficiency);
}
int Cell::GetTypeId()
{
	return this->typeId;
}
void C_Supermeat::OnEnter(Animal* beast)
{
	this->AddAnimal(beast);
	beast->Mighter();
	beast->Mighter();
	beast->Mighter();
	beast->Mighter();
}
void C_Cliff::OnEnter(Animal* beast)
{
	beast->dead("jumped off a cliff");
}
void Cell::printCell(std::ostream& stream)
{
	if (inAnimal != nullptr)
	{
		Animal* my = inAnimal;
		stream << my->GetName()[0] << " ";
		return;
	}
	else
	{
		stream << this->GetMark() << " ";
	}
}


void replaceCell(Point p, Cell*** Cells)
{
	assert(Cells != nullptr);

	delete Cells[p.GetX()][p.GetY()];
	Cells[p.GetX()][p.GetY()] = new C_Empty(p, Cells);
	Cells[p.GetX()][p.GetY()]->inAnimal = nullptr;
}
void replaceCell(Point p, Cell*** Cells, int typeId)
{
	delete Cells[p.GetX()][p.GetY()];
	Cells[p.GetX()][p.GetY()] = GetCellByTypeId(p, Cells, typeId);
	Cells[p.GetX()][p.GetY()]->inAnimal = nullptr;
}


Cell* GetRandomCell(Point p, Cell*** Cells)
{
	int celltype = GetRandomInt(0, coutCellsType * 4);
	switch (celltype)
	{
	case food:
		return new C_Food(p, Cells);
		break;
	case zagluska:
		return new C_Zagluska(p, Cells);
		break;
	case bone:
		return new C_Bone(p, Cells);
		break;
	case cliff:
		return new C_Cliff(p, Cells);
		break;
	case supermeat:
		return new C_Supermeat(p, Cells);
		break;
	default:
		return new C_Empty(p, Cells);
		break;
	}
}
Cell* GetCellByTypeId(Point p, Cell*** Cells, int celltype)
{
	switch (celltype)
	{
	case food:
		return new C_Food(p, Cells);
		break;
	case zagluska:
		return new C_Zagluska(p, Cells);
		break;
	case bone:
		return new C_Bone(p, Cells);
		break;
	case cliff:
		return new C_Cliff(p, Cells);
		break;
	case supermeat:
		return new C_Supermeat(p, Cells);
		break;
	default:
		return new C_Empty(p, Cells);
		break;
	}

}
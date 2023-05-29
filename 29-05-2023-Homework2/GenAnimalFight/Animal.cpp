#pragma once
#include "Animal.h"
#include "Field.h"
#include "Cell.h"

void Animal::Mighter()
{
	int newpower = this->GetPower() + 1;
	this->SetPower(newpower);
}
int Animal::GetY()
{
	return point.GetY();
}
int Animal::GetLivetime()
{
	return this->livetime;
}
void Animal::RandomStats()
{
	Power = GetRandomInt(minPower, maxPower);
	type = GetRandomInt(1, typecount);
	name = GetRandomName();
}
void Animal::SetPoint(Point p)
{
	point = p;
}
void Animal::SetHunger(int newhunger)
{
	if (newhunger > 0)
	{
		this->hunger = newhunger;
	}
	else
	{
		this->hunger = 0;
	}
}
int Animal::GetHunger()
{
	return this->hunger;
}
int Animal::GetX()
{
	return point.GetX();
}
std::string Animal::GetDeadReason()
{
	return this->deadreason;
}
int Animal::GetKill()
{
	return kill;
}
bool Animal::GetDeadStatus()
{
	return deadStatus;
}
void Animal::dead(std::string str)
{
	if (str != "")
	{
		this->SetDeadReason(str);
	}
	deadStatus = 1;
}
int Animal::GetPower()
{
	return this->Power;
}
int Animal::GetTypeId()
{
	return this->type;
}
void Animal::SetTypeId(int newtype)
{
	type = newtype;
}
void Animal::SetName(std::string str)
{
	name = str;
}
void Animal::IncreaseKill()
{
	kill++;
}
void Animal::IncreaseEat()
{
	eatcount++;
}
int Animal::faceId()
{
	return faceDegreeInGroup;
}
void Animal::SetDeadReason(std::string str)
{
	this->deadreason = str;
}
int Animal::SetRotate(int id)
{
	this->faceDegreeInGroup = id;
	this->faceDegree = cardinalGroup[id % 8];
	return faceDegreeInGroup;
}
void Animal::SetLiveTime(int newlivetime)
{
	this->livetime = newlivetime;
}
void Animal::Rotate(int degree)
{
	this->SetRotate(degree + this->faceId());
}
void Animal::HungerZero()
{
	this->hunger = 0;
}
void Animal::DescreaseHunder(int by)
{
	this->hunger -= by;
	if (this->hunger < 0)
	{
		this->hunger = 0;
	}
}
void Animal::IncreaseLivetime()
{
	this->livetime++;
}
int Animal::GetDnaId(int i)
{
	return DNA[i];
}
void Animal::SetPower(int newPower)
{
	Power = newPower;
}
std::string Animal::GetName()
{
	return name;
}
Point Animal::GetPoint()
{
	return point;
}

Animal::Animal(int type, std::string name, int power)
{

	this->type = type;
	this->name = name;
	this->Power = power;
	this->point = Point(0, 0);
	FillArrayRandomNumbers(DNA, 256, 0, countCommand + 256 - 1);///	FillArrayRandomNumbers(DNA, dnaSize, 0, countCommand + dnaSize - 1);
}
Animal::Animal(const Animal& beast)
{
	this->type = beast.type;
	this->name = beast.name;
	this->Power = beast.Power;
	for (int i = 0; i < 256; i++) // dnaSize
	{
		this->DNA[i] = beast.DNA[i];
	}
}
Animal* Animal::Mutation()
{
	Animal* newbeast = GetAnimalById(this->GetTypeId(), GetRandomName(), GetRandomInt(minPower, maxPower));
	for (int i = 0; i < 256; i++)/// dnaSize
	{
		newbeast->DNA[i] =this->DNA[i]; // dnaSize
	}
	for (int i = 0; i < MutationLvl; i++)
	{
		newbeast->DNA[GetRandomInt(0, 256)] = GetRandomInt(0, countCommand + 256 - 1); // dnaSize
	}
	return newbeast;
}
Animal::Animal(std::string& str1Name, std::string& str2TypeId, std::string& str3Power, std::string& str4DNA)
{
	this->name = NameParse(str1Name);
	this->type = FirtNumberParse(str2TypeId);
	this->Power = GetRandomInt(minPower, maxPower);
	ArrayParse(str4DNA, DNA, 256); // dnaSize
}

bool AnimalFight(Animal* Attacker, Animal* Attacking)
{
	Animal* loser;
	Animal* winner;
	assert(!Attacker->GetDeadStatus() && !Attacking->GetDeadStatus());
	FIGHT++;
	bool answer = true;
	int AnimalPowerAttacing = Attacking->AnimalPowerFight();
	int AnimalPowerAttacker = Attacker-> AnimalPowerFight();
	if (AnimalPowerAttacker >= AnimalPowerAttacing)//AnimalPower1 >= AnimalPower2
	{
		loser = Attacking;
		winner = Attacker;
	}
	else
	{
		loser = Attacker;
		winner = Attacking;
		answer = false;
	}
	winner->Mighter();
	winner->IncreaseKill();
	winner->DescreaseHunder(20);
	loser->dead("EATEN BY " + winner->GetName());

	assert(!Attacking->GetDeadStatus() || !Attacker->GetDeadStatus());
	assert(Attacking->GetDeadStatus() || Attacker->GetDeadStatus());
	return answer;
}
int Animal::Move(int direction, Field& field)
{
	assert(!this->GetDeadStatus());
	Point newpoint = this->GetPoint() + GetRotatePoint(this->faceId(), direction);
	Point oldpoint = this->GetPoint();
	NormalizePoint(newpoint);
	NormalizePoint(oldpoint);

	assert(isCorrectPoint(newpoint, field) && isCorrectPoint(oldpoint, field));

	Cell* cellFrom = field.GetCell(oldpoint);
	Cell* cellTo = field.GetCell(newpoint);
	Animal* inAnimal = cellTo->inAnimal;

	assert(cellFrom != nullptr);
	assert(cellTo != nullptr);
	if (inAnimal != nullptr)
	{
		assert(this != nullptr && inAnimal != nullptr);
		assert(!this->GetDeadStatus() && !inAnimal->GetDeadStatus());
		if (AnimalFight(this, inAnimal))
		{
			cellTo->inAnimal = this;
			this->SetPoint(cellTo->GetPoint());
			cellFrom->Clear();
		}
		else
		{
			cellFrom->Clear();
		}

		assert(field.GetCell(oldpoint)->inAnimal == nullptr || field.GetCell(newpoint)->inAnimal == nullptr);
		assert(this->GetDeadStatus() || inAnimal->GetDeadStatus());
	}
	else
	{
		//std::cout << "I MOVE" << std::endl;
		//assert(false);
		cellTo->OnEnter(this);
		cellFrom->OnLeave(this);
	}


	//field.beastAction(this, cellTo, cellFrom);

	assert(field.GetCell(newpoint)->inAnimal == nullptr || field.GetCell(oldpoint)->inAnimal == nullptr);
	return -1;
}
void Animal::Ability(Point direction, Field& field)
{

}
int Animal::Check(Point direction, Field& field)
{
	Point checkpoint = this->GetPoint() + direction;
	NormalizePoint(checkpoint);
	Cell* checkcell = field.GetCell(checkpoint);
	if (checkcell->inAnimal != nullptr)
	{
		if (checkcell->inAnimal->GetPower() < this->GetPower())
		{
			return 1;
		}
		return 2;
	}
	if (checkcell->GetTypeId() != -1)
	{
		return 3 + checkcell->GetTypeId();
	}
	else
	{
		return 4 + typecount;
	}
}
void Animal::IncreaseHunger(Field& field)
{
	this->hunger++;
	if (hunger > maxHunger)
	{
		this->SetDeadReason("Hunger");
		Point p = this->GetPoint();
		field.GetCell(p)->Clear();
		this->dead();
	}
}
void Animal::turn(Field& field)
{
	Point checkpoint;
	int Command = 0;
	for (int i = 0; Command < BrainPowerMax; Command++)
	{
		if (this->GetDeadStatus())
		{
			return;
		}
		i++;
		i = i % 256;//dnaSize
		switch (this->GetDnaId(i))
		{
		case 0:
			this->Move(forwardMove, field);

			Command = BrainPowerMax;
			break;
		case 1:
			this->Move(backMove, field);
			Command = BrainPowerMax;
			break;
		case 2:
			this->Move(leftMove, field);
			Command = BrainPowerMax;
			break;
		case 3:
			this->Move(rightMove, field);
			Command = BrainPowerMax;
			break;
		case 4:
			this->Move(leftforward, field);
			Command = BrainPowerMax;
			break;
		case 5:
			this->Move(rightforward, field);
			Command = BrainPowerMax;
			break;
		case 6:
			this->Move(leftback, field);
			Command = BrainPowerMax;
			break;
		case 7:
			this->Move(rightback, field);;
			Command = BrainPowerMax;
			break;
		case 8:
			this->Rotate(1);
			Command++;
			break;
		case 9:
			this->Rotate(2);
			Command++;
			break;
		case 10:
			this->Rotate(3);
			Command++;
			break;
		case 11:
			this->Rotate(4);
			Command++;
			break;
		case 12:
			this->Rotate(5);
			Command++;
			break;
		case 13:
			this->Rotate(6);
			Command++;
			break;
		case 14:
			this->Rotate(7);
			Command++;
			break;
		case 15:
			checkpoint = GetRotatePoint(this->faceId(), 0);//forward
			i += this->Check(checkpoint, field) - 1;
			Command++;
			break;
		case 16:
			checkpoint = GetRotatePoint(this->faceId(), 1);//forward-right
			i += this->Check(checkpoint, field) - 1;
			Command++;
			break;
		case 17:
			checkpoint = GetRotatePoint(this->faceId(), 2);//right
			i += this->Check(checkpoint, field) - 1;
			Command++;
			break;
		case 18:
			checkpoint = GetRotatePoint(this->faceId(), 3);//rightback
			i += this->Check(checkpoint, field) - 1;
			Command++;
			break;
		case 19:
			checkpoint = GetRotatePoint(this->faceId(), 4);//back
			i += this->Check(checkpoint, field) - 1;
			Command++;
			break;
		case 20:
			checkpoint = GetRotatePoint(this->faceId(), 5);//leftback
			i += this->Check(checkpoint, field) - 1;
			Command++;
			break;
		case 21:
			checkpoint = GetRotatePoint(this->faceId(), 6);//left
			i += this->Check(checkpoint, field) - 1;
			Command++;
			break;
		case 22:
			checkpoint = GetRotatePoint(this->faceId(), -1);//forwardleft
			i += this->Check(checkpoint, field) - 1;
			Command++;
		case 23:
			i += this->Check(north + north, field);
			Command++;
		case 24:
			i += this->Check(south + south, field);
			Command++;
		case 25:
			i += this->Check(east + east, field);
			Command++;
		case 26:
			i += this->Check(west + west, field);
			Command++;
			break;
		case 27:
			//i += coutCellsType + 3;
			this->Ability(west, field);;
			//Command = BrainPowerMax;
			break;
		default:
			i += GetDnaId(i);
			break;
			/*
			* 		case 28:
			this->Ability(north_west, field);
			//Command = BrainPowerMax;
			break;
		case 29:
			this->Ability(north, field);
			//Command = BrainPowerMax;
			break;
		case 30:
			this->Ability(north_east, field);
			//Command = BrainPowerMax;
			break;
		case 31:
			this->Ability(east, field);
			//Command = BrainPowerMax;
			break;
		case 32:
			this->Ability(south_east, field);
			//Command = BrainPowerMax;
			break;
		case 33:
			this->Ability(south, field);
			//Command = BrainPowerMax;
			break;
		case 34:
			this->Ability(south_west, field);
			//Command = BrainPowerMax;
			break;
		case 35:
			*/
		}
	}
}



std::string GetRandomName()
{
	return nameArray[rand() % nameCount];
}

int Animal::AnimalPowerFight()
{
	return this->GetPower() + GetRandomInt(1, 5);
}

bool AnimalFight(Animal* Attacker, Animal* Attacking);


Point GetRotatePoint(int IdRotate, int rotateDegree)
{
	return cardinalGroup[intmod(IdRotate + rotateDegree, 8)];///8 - количество направлений
}


void NormalizePoint(Point& p)////////////принимать бы поле, а не глобалку
{
	p.SetX(intmod(p.GetX(), GameSize));
	p.SetY(intmod(p.GetY(), GameSize));
}
bool isCorrectPoint(Point& p, Field& field)
{
	return p.GetX() >= 0 && p.GetY() >= 0 && p.GetX() < GameSize && p.GetY() < GameSize;//field->GetSize() 
}
Animal* GetAnimalById(int celltype, std::string name, int power)
{
	switch (celltype)
	{
	case Coyote:
		return new C_Coyote(celltype, name, power);
		break;
	case Snake:
		return new C_Snake(celltype, name, power);
		break;
	case Capybara:
		return new C_Capybara(celltype, name, power);
		break;
	default:
		assert(false);
		break;
	}
}
Animal* GetAnimalById(std::string& str1Name, std::string& str2TypeId, std::string& str3Power, std::string& str4DNA)
{
	switch (FirtNumberParse(str2TypeId))
	{
	case Coyote:
		return new C_Coyote(str1Name, str2TypeId, str3Power, str4DNA);
		break;
	case Snake:
		return new C_Snake(str1Name, str2TypeId, str3Power, str4DNA);
		break;
	case Capybara:
		return new C_Capybara(str1Name, str2TypeId, str3Power, str4DNA);
		break;
	default:
		assert(false);
		break;
	}
}
Animal* GetRandomAnimal()
{
	std::string name     = GetRandomName();
	int         power    = GetRandomInt(minPower, maxPower);
	int         celltype = GetRandomInt(1, typecount);
	switch (celltype)
	{
	case Coyote:
		return new C_Coyote(celltype, name, power);
		break;
	case Snake:
		return new C_Snake(celltype, name, power);
		break;
	case Capybara:
		return new C_Capybara(celltype, name, power);
		break;
	default:
		assert(false);
		break;
	}
}

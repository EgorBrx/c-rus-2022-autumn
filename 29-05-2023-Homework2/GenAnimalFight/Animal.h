#pragma once
#include "IAnimal.h"
#include <string>
#include "MassiveFuncAndRandomFunc.h"
#include "Point.h"
#include <fstream>
#include <assert.h>
#include "Constats.h"
class Field;
class Animal;

#define Snake 1
#define Capybara 2
#define Coyote 3

#define forwardMove 0
#define rightforward 1
#define rightMove 2
#define rightback 3
#define backMove 4
#define leftback 5
#define leftforward 6
#define leftMove 7

#define leaveCell 0
#define enterCell 1

const std::string nameArray[100] = { "A", "B", "C", "D", "E", "F","C", "Barsik","Musya","Fluffy","Slinky", "Slytherin","Basilisk","Bella","Luna","Lola","Nala","Filip", "18" };
bool AnimalFight(Animal* Attacker, Animal* Attacking);
void NormalizePoint(Point& p);
std::string GetRandomName();
int AnimalPowerFight(Animal* beast);
bool AnimalFight(Animal* Attacker, Animal* Attacking);
Point GetRotatePoint(int IdRotate, int rotateDegree = 0);
bool isCorrectPoint(Point& p, Field& field);
bool isCorrectPoint(Point& p, Field& field);
class Animal
{
private:
	std::string name;
	int         Power = 0;
	int         type;
	Point       point;
	int		    DNA[256]{ 0 };// dnaSize
	int         livetime = 0;
	int		    hunger = 0;
	Point       faceDegree = north;///north
	int         faceDegreeInGroup = 1;
	int         kill = 0;
	int         eatcount = 0;
	//Cell*		myCell;
	std::string deadreason = "unknown";
	int         deadStatus = 0;
	void PrintInfo(std::ostream& stream, Animal& beast)
	{

		stream << "name   = " << beast.name << std::endl;
		stream << "TypeId = " << beast.type << std::endl;
		stream << "Power  = " << beast.Power << std::endl;
		printArray(DNA, 256, stream);//!/!/! printArray(DNA, dnaSize, stream) extern const int		 dnaSize = 256;
		stream << std::endl;
		stream << "livetime  = " << beast.livetime << std::endl;
		stream << "kill  = " << beast.kill << std::endl;
		stream << beast.deadreason << std::endl;
	}
public:
				void		SetHunger(int newhunger);
				int			GetHunger();
				void		RandomStats();
				void		SetPoint(Point p);
				int			GetX();
				int			GetY();
				int			GetLivetime();
				std::string GetDeadReason();
				int         GetKill();
				bool        GetDeadStatus();
				void        dead(std::string str = "");
				int         GetPower();
				int         GetTypeId();
				void        SetTypeId(int newtype);
				void        SetName(std::string str);
				void        IncreaseKill();
				void		IncreaseEat();
				int			faceId();
				void		SetDeadReason(std::string str);
				int			SetRotate(int id);
				void		SetLiveTime(int newlivetime);
				void		Rotate(int degree = 1);
				void		HungerZero();
		virtual void		DescreaseHunder(int by = 1);
				void		IncreaseLivetime();
				int			GetDnaId(int i);
				void		SetPower(int newPower);
				std::string GetName();
				Point	    GetPoint();
				int			Move(int direction, Field& field);
				int			Check(Point direction, Field& field);
		virtual int         AnimalPowerFight();
				void		turn(Field& field);
		virtual	void		Mighter();
				void		IncreaseHunger(Field& field);
				void		Ability(Point direction, Field& field);

	Animal(int type = Snake, std::string name = "Vasya", int power = minPower);
	Animal(const Animal& beast);
	Animal* Mutation();
	Animal(std::string& str1Name, std::string& str2TypeId, std::string& str3Power, std::string& str4DNA);
	virtual ~Animal()
	{
	};
	friend std::ostream& operator<<(std::ostream& stream, Animal& beast)
	{
		beast.PrintInfo(stream, beast);
		return stream;
	}
};
class C_Snake : public Animal
{
private:
	const int typeId = Snake;
public:
	void Mighter()
	{
		this->SetPower(this->GetPower() + 2);
	}
	C_Snake(std::string& str1Name, std::string& str2TypeId, std::string& str3Power, std::string& str4DNA) : Animal(str1Name, str2TypeId, str3Power, str4DNA)
	{}
	C_Snake(int type = Snake, std::string name = "Vasya", int power = minPower) : Animal(type, name, power)
	{}
	~C_Snake() {};
};
class C_Capybara : public Animal
{
private:
	const int typeId = Capybara;
public:
	int AnimalPowerFight()
	{	
		
		return 0;/////слабая
	}
	void DescreaseHunder(int by = 1)
	{
		this->SetHunger(GetHunger() - 2 * by);
	}
	C_Capybara(std::string& str1Name, std::string& str2TypeId, std::string& str3Power, std::string& str4DNA) : Animal(str1Name, str2TypeId, str3Power, str4DNA)
	{}
	C_Capybara(int type = Snake, std::string name = "Vasya", int power = minPower) : Animal(type, name, power)
	{}
	~C_Capybara() {};
};
class C_Coyote : public Animal
{
private:
	const int typeId = Coyote;
public:
	C_Coyote(std::string& str1Name, std::string& str2TypeId, std::string& str3Power, std::string& str4DNA) : Animal(str1Name, str2TypeId, str3Power, str4DNA)
	{
		this->SetTypeId(typeId);
	}
	C_Coyote(int type = Snake, std::string name = "Vasya", int power = minPower) : Animal(type, name, power)
	{}
	~C_Coyote() {};
};
Animal* GetAnimalById(int celltype, std::string name = "Vasya", int power = minPower);
Animal* GetAnimalById(std::string& str1Name, std::string& str2TypeId, std::string& str3Power, std::string& str4DNA);
Animal* GetRandomAnimal();

/*
* (неактуально)
описание днк в скобках указаны стандартные настройки:
днк представляет себя массив из dnaSize(32) элементов,
команды животного:
0-7 движение на клетку. 0 северо-запад, 1 север, 2 восток...(по часовой)
8-15 осмотр клеток поблизости. (8-15 северо-запад ..., 16-19 север-север, восток-восток...)
16-23 осмотр клеток поблизости. (поворот клетки на pi/4, 2*pi/4 ... по часовой)
команда 20 - это просмотр текущего состояния поля
команда 21-28 - это использование особых способностей вида на клетку
команды с countCommand(29) по  countCommand + dnaSize (32+29) сдвиг на номер команды - dnaSize в массиве и продолжить исполнение.
осмотр:
мы смотрим на структуру cell,
если есть враг и мы сильнее него указатель в днк сдвигаем на 1 (при исполнение)
если есть враг и мы слабее него указатель в днк сдвигаем на 2
если там нет врага, то указатель сдвигаем на typeIdCell + 3
*/


/*
void Cell::AddAnimal(Animal* beast)
{
	inAnimal = beast;
}
*/
/*
* int TreatmentAnimalMove(Animal* beast)
	{
		if (inAnimal != nullptr)
		{
			if (!AnimalFight(beast, inAnimal))
			{
				return 0;
			}
		}
		if (this->GetTypeId() == -1)
		{
			beast->GetGen()->DeadStatus(beast->GetGenId());
			inAnimal = nullptr;
			return 1;
		}
		if (this->GetTypeId() == food)
		{
			beast->IncreaseEat();
			beast->DescreaseHunder(5);
		}
		if (this->GetTypeId() == 2)
		{
			beast->IncreaseHunger();
		}

		if (this->GetTypeId() == 3)
		{
			beast->SetDeadReason("jumped off a cliff");
			inAnimal = beast;
			this->dead();
			return 1;
		}
		if (this->GetTypeId() == 5)
		{

	* 		beast->Mighter();
			beast->Mighter();
			beast->Mighter();
			beast->Mighter();

		}
		inAnimal = beast;
		return 1;
	}*/



#pragma once

class Animal;
class Generation;
class Cell;
class Field;

const int speedDeadZone = 10;
class Generation;
/*
* class Player
{
private:
	Animal* beast;
public:
	Animal* GetAnimal()
	{
		return beast;
	}
	Player(std::string name)
	{
		beast = new Animal(GetRandomInt(0, typecount), name, GetRandomInt(minPower, maxPower));
	}
	void turn(Field& field)
	{
		Point checkpoint;
		std::cout << "your turn!" << std::endl;
		int n = 0;

		int Command = 0;
		for (int i = 0; i < 20; i++)
		{
			std::cin >> n;
			switch (n)
			{
			case 0:
				beast->Move(forwardMove, field);
				//i = 21;
				break;
			case 1:
				beast->Move(backMove, field);
				i = 21;
				break;
			case 2:
				beast->Move(leftMove, field);
				i = 21;
				break;
			case 3:
				beast->Move(rightMove, field);
				i = 21;
				break;
			case 4:
				beast->Move(leftforward, field);
				i = 21;
				break;
			case 5:
				beast->Move(rightforward, field);
				i = 21;
				break;
			case 6:
				beast->Move(leftback, field);
				i = 21;
				break;
			case 7:
				beast->Move(rightback, field);
				i = 21;
				break;
			case 8:
				beast->Rotate(1);
				Command++;
				break;
			case 9:
				beast->Rotate(2);
				Command++;
				break;
			case 10:
				i = 21;
				//beast->Rotate(3);
				Command++;
				break;
			case 11:
				beast->Rotate(4);
				Command++;
				break;
			case 12:
				beast->Rotate(5);
				Command++;
				break;
			case 13:
				beast->Rotate(6);
				Command++;
				break;
			case 14:
				beast->Rotate(7);
				Command++;
				break;
			case 15:
				checkpoint = GetRotatePoint(beast->faceId(), 0);//forward
				std::cout << beast->Check(checkpoint, field);
				i++;
				Command++;
				break;
			case 16:
				//p
				checkpoint = GetRotatePoint(beast->faceId(), 1);//forward-right
				std::cout << beast->Check(checkpoint, field);
				i++;
				Command++;
				break;
			case 17:
				checkpoint = GetRotatePoint(beast->faceId(), 2);//right
				std::cout << beast->Check(checkpoint, field);
				Command++;
				break;
			case 18:
				checkpoint = GetRotatePoint(beast->faceId(), 3);//rightback
				std::cout << beast->Check(checkpoint, field);
				Command++;
				break;
			case 19:
				checkpoint = GetRotatePoint(beast->faceId(), 4);//back
				std::cout << beast->Check(checkpoint, field);
				Command++;
				break;
			case 20:
				checkpoint = GetRotatePoint(beast->faceId(), 5);//leftback
				std::cout << beast->Check(checkpoint, field);
				Command++;
				break;
			case 21:
				checkpoint = GetRotatePoint(beast->faceId(), 6);//left
				std::cout << beast->Check(checkpoint, field);
				Command++;
				break;
			case 22:
				checkpoint = GetRotatePoint(beast->faceId(), -1);//forwardleft
				std::cout << beast->Check(checkpoint, field);
				Command++;
			}
		}
	}
	~Player()
	{
		//delete GetAnimal();
	}
};
*/
class Game
{
private:
	Field* field;
	Generation* gen;
	//Player* player;
	int TurnNum = 1;
	int livetime = 0;
	int DeadZoneSize = 0;

public:
	/*
	* 	void AddPlayer(std::string name, int x = 0, int y = 0)
	{
		//player = new Player(name);
		Point p(x, y);
		field->AddAnimal(player->GetAnimal(), p);
	}
	*/

	bool turn(bool visual = false);
	void Refresh();
	Game(Generation* gen, Field* field);
	~Game();
	Generation* GetGen();
};
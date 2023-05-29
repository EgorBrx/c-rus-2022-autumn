#include "Game.h"
#include "Animal.h"
#include "Field.h"
#include "Cell.h"
#include "Generation.h"


/*
* void Game::AddPlayer(std::string name, int x = 0, int y = 0)
{
	player = new Player(name);
	Point p(x, y);
	field->AddAnimal(player->GetAnimal(), p);
}
*/

bool Game::turn(bool visual)
{
	livetime++;
	int live = 0;

	/*
	* 
	if (player != nullptr)
	{
		player->turn(*field);
	}
	*/
	for (int i = 0; i < gen->GetSize(); i++)
	{
		if (!gen->GetAnimal(i)->GetDeadStatus())
		{
			Animal* current = gen->GetAnimal(i);
			live++;
			current->turn(*field);
			current->IncreaseHunger(*field);
			if (!gen->GetAnimal(i)->GetDeadStatus())
			{
				current->IncreaseLivetime();
			}
			else
			{
				live--;
			}

		}
	}
	TurnNum = (TurnNum + 1) % speedDeadZone;
	if (TurnNum == 0)
	{
		field->AddFood(live * 3);//live
		//IncreaseDeadZone();
	}
	if (live < 1 or livetime > 100000)
	{
		std::cout << "livetime=" << livetime << std::endl;
		return false;
	}
	if (visual) {
		system("cls");
		std::cout << *field << std::endl;
	}

	return true;
}
void Game::Refresh()
{
	DeadZoneSize = 0;
}
Game::Game(Generation* gen, Field* field)
{
	this->gen = gen;
	this->field = field;
}
Game::~Game()
{
	//delete player;
}
Generation* Game::GetGen()
{
	return gen;
}
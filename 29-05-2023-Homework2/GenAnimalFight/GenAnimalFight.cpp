#pragma once
#include <iostream>
#include <string>
#include <random>
#include "Point.h"
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#include <fstream>
#include <cstdio>

#include "Field.h"
#include "Animal.h"
#include "Generation.h"
#include "Game.h"



int main(int argc, char* argv[])
{
	int fileNum = 0;
	std::string param;
	srand(time(0));

	std::cout << "print \"Go\ *num* to start Random generation and save in *num* file\n";
	std::cout << "print \"Import *num*\" to import gen\n";
	std::cout << "print \"Gen *num* *numIteration* *paramVisual*\" to start generation *num* for *numIteration* iteration with flag *paramVisual*\n";
	
	std::cin >> param;

	if (param == "Import" || param == "import")
	{
		Generation gen(100);
		Field field;
		field.RandomSetting();
		std::cin >> fileNum;
		gen.Import(fileNum);
		//gen.fillRandom();
		gen.CreateNewGeneration();
		gen.Print(std::cout, true);
	}

	if (param == "Go" || param == "go")
	{
		std::cin >> fileNum;
		Generation gen(100);
		Field field;
		Game game(&gen, &field);
		field.RandomSetting();
		gen.fillRandom();
		field.ImportGeneration(gen);

		while (game.turn(true)){}///true

		//gen.Print(std::cout, true);
		gen.Extract(fileNum);
	}
	int genereations = 0;
	if (param == "gen" || param == "Gen")
	{
		int num = 1;
		bool paramVisual = false;
		char param2 = '1';

		std::cin >> fileNum;
		std::cin >> num;
		std::cin >> param2;
		if (param2 == '1' || param2 == 't') { paramVisual = true; }
		while (num != 0)
		{
			Generation gen(100);
			Field field;
	
			field.RandomSetting();
			Game game(&gen, &field);
			FIGHT = 0;
			gen.Import(fileNum);
			gen.CreateNewGeneration();
			
			//gen.fillRandom();
			field.ImportGeneration(gen);

			while (game.turn(paramVisual)){}
			
			gen.Extract(fileNum);

			if (num == 0)
			{
				gen.Print(std::cout, true);
			}
			num--;
		}
	}
	int n;
	std::cout << "FIGHT = " << FIGHT << std::endl;
	std::cout << "end";
	std::cin >> n;

	return EXIT_SUCCESS;
}

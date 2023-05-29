#pragma once


#include "MassiveFuncAndRandomFunc.h"


bool isInt(char A)
{
	return (A >= 48) && (A <= 59);
}

int FirtNumberParse(std::string& str, int& end, bool Save)
{
	//std::cout << "start FROM: " << end << std::endl;
	std::string resultNum = "        ";
	for (; !isInt(str[end]) && end < str.size() - 1; end++) {}
	int j = 0;
	for (; isInt(str[end + j]) && end + j < str.size() - 1; j++)
	{
		//std::cout << end << "= i check \n";
		resultNum[j] = str[end + j];
	}
	resultNum[j + 1] = '\0';
	end = end + j;

	if (j != 0)
	{
		return std::stoi(resultNum);
	}

	else
	{
		return -1;
	}
}
void ArrayParse(std::string str, int* Array, int maxSize, char leftbrackets, char rightbrackets )
{
	int end = 0;
	//std::cout << "my str : " << str << std::endl;
	for (int j = 0; j < maxSize && str[end] != rightbrackets && end < str.size() - 1; end++)
	{
		Array[j] = FirtNumberParse(str, end, true);
		j++;
	}
	//return result;
}

std::string NameParse(std::string str)
{
	std::string result = "                      ";
	int i = 0;
	for (i = 0; str[i] != '='; i++) {}
	i++;
	int j = 0;
	for (; j < str.size() - i; j++)
	{
		result[j] = str[j + i];
	}
	//result[j + 1] = '\0';
	return result;
}




int FirtNumberParse(std::string str)
{
	std::string resultNum = "        ";
	int i = 0;
	for (i = 0; !isInt(str[i]); i++) {}
	int j = 0;
	for (; isInt(str[i + j]); j++)
	{
		resultNum[j] = str[i + j];
	}
	resultNum[j + 1] = '\0';
	return std::stoi(resultNum);
}
int GetRandomInt(int a, int b)
{
	return a + rand() % (b - a + 1);
}
//
void printArray(int* A, int size, std::ostream& stream)
{
	stream << "{";
	for (int i = 0; i < size; i++)
	{
		stream << A[i] << ", ";
	}
	stream << "}";

}
void FillArrayRandomNumbers(int* A, int size, int a, int b)
{
	for (int i = 0; i < size; i++)
	{
		A[i] = GetRandomInt(a, b);
	}
}
void swap(int& a, int& b)
{
	int c = b;
	b = a;
	a = c;
}
void ShuffleArray(int* A, int size)
{
	for (int i = 0; i < size; i++)
	{
		swap(A[i], A[i + GetRandomInt(0, size - i - 1)]);
	}
}
int intmod(int i, int mod)
{
	int answer = i % mod;
	if (answer >= 0)
	{
		return answer;
	}
	return mod + answer;
}
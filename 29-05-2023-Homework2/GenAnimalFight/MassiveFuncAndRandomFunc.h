#pragma once
#include<iostream>
#include<random>
#include<string>
#include <cstdio>
bool isInt(char A);

int FirtNumberParse(std::string& str, int& end, bool Save);
void ArrayParse(std::string str, int* Array, int maxSize, char leftbrackets = '{', char rightbrackets = '}');
std::string NameParse(std::string str);



int FirtNumberParse(std::string str);
int GetRandomInt(int a, int b);
//
void printArray(int* A, int size, std::ostream& stream);
void FillArrayRandomNumbers(int* A, int size, int a, int b);
void swap(int& a, int& b);
void ShuffleArray(int* A, int size);
int intmod(int i, int mod);
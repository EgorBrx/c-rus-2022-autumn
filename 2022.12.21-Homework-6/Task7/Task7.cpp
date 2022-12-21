#include <iostream>

int FillArray(int* Array, int n);
int FindNumOfMinInArray(int* Array, int n);
int FindNumOfMaxInArray(int* Array, int n);
int FindSumNumbersInArray(int* Array, int n);
int FindMultiplicationNumbersInArray(int* Array, int from, int to);
int swap(int& a, int& b);

int main(int argc, char* argv[])/////решение здорового человека
{
    int n = 0;
    int left = 0;
    int right = 0;

    std::cin >> n;
    int Array[100]{ 0 };
    FillArray(Array, n);

    left = FindNumOfMinInArray(Array, n);
    right = FindNumOfMaxInArray(Array, n);

    std::cout << FindSumNumbersInArray(Array, n) << std::endl;
    std::cout << FindMultiplicationNumbersInArray(Array, left, right) << std::endl;

    return EXIT_SUCCESS;
}

int swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
    return 0;
}
int FillArray(int* Array, int n)
{
    for (int i = 0; i < n; i++)
        std::cin >> Array[i];
    return 0;
}
int FindNumOfMaxInArray(int* Array, int n)
{
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        if (Array[i] > Array[max])
            max = i;
    }
    return max;
}
int FindNumOfMinInArray(int* Array, int n)
{
    int min = 0;
    for (int i = 1; i < n; i++)
    {
        if (Array[i] < Array[min])
            min = i;
    }

    return min;
}
int FindSumNumbersInArray(int* Array, int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (Array[i] > 0)
            result += Array[i];
    }

    return result;
}
int FindMultiplicationNumbersInArray(int* Array, int from, int to)
{
    if (to < from)
        swap(to, from);
    int result = 1;
    for (int i = from + 1; i < to; i++)
    {
        result *= Array[i];
    }
    return result;
}

int SevenProblem6DzInOneWay()///решение нездорового человека
{
    int n = 0;
    int max = 0;
    int min = 0;
    int SumPositive = 0;
    int result = 1;
    int temp = 1;

    std::cin >> n;
    int Array[100]{ 0 };
    FillArray(Array, n);

    for (int i = 1; i < n; i++)
    {
        temp *= Array[i];

        if (Array[i] > Array[max])
        {
            if (max > min)
            {
                result *= Array[max] * temp / Array[i];
            }
            else
            {
                result = temp / Array[i];
            }
            temp = 1;
            max = i;
        }
        if (Array[i] < Array[min])
        {
            if (min > max)
            {
                result *= Array[min] * temp / Array[i];
            }
            else
            {
                result = temp / Array[i];
            }
            temp = 1;

            min = i;
        }
        if (Array[i] > 0)
            SumPositive += Array[i];
    }
    if (Array[0] > 0)
        SumPositive += Array[0];
    std::cout << SumPositive << std::endl;
    std::cout << result << std::endl;
    return EXIT_SUCCESS;
}
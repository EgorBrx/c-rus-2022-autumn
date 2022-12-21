#include <iostream>

int FillArray(int* Array, int n);
int ShowArray(int* Array, int n);

int main(int argc, char* argv[])
{
    int N           = 0;
    int OddNumbers  = 0;
    int EvenNumbers = 0;
    int Array[100]{ 0 };
    int EvenNum[50]{ 0 };
    int OddNum[50]{ 0 };

    std::cin >> N;
    FillArray(Array, N);

    for (int i = 0; i < N; i++)
        if (Array[i] % 2)
        {
            OddNum[OddNumbers] = Array[i];
            OddNumbers += 1;
        }
        else
        {
            EvenNum[EvenNumbers] = Array[i];
            EvenNumbers += 1;
        }

    ShowArray(OddNum, OddNumbers);
    ShowArray(EvenNum, EvenNumbers);
    if (OddNumbers <= EvenNumbers)
        std::cout << "YES";

    return EXIT_SUCCESS;
}

int FillArray(int* Array, int n)
{
    for (int i = 0; i < n; i++)
        std::cin >> Array[i];
    return 0;
}
int ShowArray(int* Array, int n)
{
    for (int i = 0; i < n; i++)
        std::cout << Array[i] << " ";
    std::cout << std::endl;
    return 0;
}
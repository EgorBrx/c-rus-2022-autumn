#include <iostream>

int** CreateArray(int n, int k);
int FillArray(int** Array, int n, int k);
int ShowArray(int** Array, int n, int k);
int DeleteArray(int** Array, int n, int k);
int transpositionHorizontal(int** Matrix, int n, int k);
int swap(int& a, int& b);

int main(int argc, char* argv[])
{
    int n = 0;
    int k = 0;

    std::cin >> n >> k;
    int** Array = CreateArray(n, k);

    FillArray(Array, n, k);

    transpositionHorizontal(Array, n, k);
    ShowArray(Array, n, k);

    DeleteArray(Array, n, k);

    return EXIT_SUCCESS;
}

int swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
    return 0;
}
int transpositionHorizontal(int** Matrix, int n, int k)
{
    if (n == 1)
        return 0;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n / 2; j++)
            swap(Matrix[j][i], Matrix[n - j - 1][i]);

    return 0;
}
int** CreateArray(int n, int k)
{
    int** Array = new int* [n];
    for (int i = 0; i < n; i++)
        Array[i] = new int[k];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            Array[i][j] = 0;

    return Array;
}
int FillArray(int** Array, int n, int k)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            std::cin >> Array[i][j];

    return 0;
}
int ShowArray(int** Array, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
            std::cout << Array[i][j] << " ";//std::cout << Array[i][j];
        std::cout << std::endl;
    }

    return 0;
}
int DeleteArray(int** Array, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        delete[] Array[i];
    }
    delete[] Array;

    return 0;
}
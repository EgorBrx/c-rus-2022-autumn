#include <iostream>

int** CreateArray(int n, int k);
int FillArray(int** Array, int n, int k);
int ShowArray(int** Array, int n, int k);
int DeleteArray(int** Array, int n, int k);
int transpositionMatrixSecDig(int** Matrix, int n);
int swap(int& a, int& b);

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;
    int** Array = CreateArray(n, n);
    FillArray(Array, n, n);

    transpositionMatrixSecDig(Array, n);
    ShowArray(Array, n, n);

    DeleteArray(Array, n, n);

    return EXIT_SUCCESS;
}

int swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
    return 0;
}
int transpositionMatrixSecDig(int** Matrix, int n)
{
    if (n == 1)
        return 0;
    for (int i = 0; i < n; i++)
        for (int j = n - i - 2; j >= 0; j--)
            swap(Matrix[j][i], Matrix[n - i - 1][n - j - 1]);

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
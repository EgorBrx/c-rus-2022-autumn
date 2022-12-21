#include <iostream>

int** CreateArray(int n, int k);
int FillArray(int** Array, int n, int k);
int ShowArray(int** Array, int n, int k);
int DeleteArray(int** Array, int n, int k);
int** SumMatrix(int** Matrix_1, int** Matrix_2, int n, int k);

int main(int argc, char* argv[])
{
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    int** Matrix_1 = CreateArray(n, k);
    int** Matrix_2 = CreateArray(n, k);

    FillArray(Matrix_1, n, k);
    FillArray(Matrix_2, n, k);

    int** answer = SumMatrix(Matrix_1, Matrix_2, n, k);
    ShowArray(answer, n, k);

    DeleteArray(Matrix_1, n, k);
    DeleteArray(Matrix_2, n, k);
    DeleteArray(answer, n, k);

    return EXIT_SUCCESS;
}
int** SumMatrix(int** Matrix_1, int** Matrix_2, int n, int k)
{
    int** result = CreateArray(n, k);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            result[i][j] = Matrix_1[i][j] + Matrix_2[i][j];

    return result;
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
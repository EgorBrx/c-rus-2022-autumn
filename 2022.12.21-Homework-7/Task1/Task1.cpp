#include <iostream>

int** CreateArray(int n, int k);
int   FillArray(int** Array, int n, int k);
int   ShowArray(int** Array, int n, int k);
int   DeleteArray(int** Array, int n, int k);
int*  CreateArray(int n);

int*  SumInColumns(int** Array, int n, int k, bool Save=false);
int*  SumInLines(int** Array, int n, int k, bool Save=false);
int   SumInColumn(int** Array, int NumColumn, int n, int k);
int   SumInLine(int** Array, int NumLine, int n, int k);

int main(int argc, char* argv[])
{
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    int** Array = CreateArray(n, k);
    FillArray(Array, n, k);

    SumInLines(Array, n, k);
    SumInColumns(Array, n, k);
    std::cout << std::endl;
    ShowArray(Array, n, k);

    DeleteArray(Array, n, k);

    return EXIT_SUCCESS;
}

int* CreateArray(int n)
{
    int* Array = new int[n] {0};
    return Array;
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

int SumInLine(int** Array, int NumLine, int n, int k)
{
    int sum = 0;
    if (NumLine >= n)
        return 0;
    for (int i = 0; i < k; i++)
        sum += Array[NumLine][i];

    return sum;
}
int SumInColumn(int** Array, int NumColumn, int n, int k)
{
    int sum = 0;
    if (NumColumn >= k)
        return 0;

    for (int i = 0; i < n; i++)
        sum += Array[i][NumColumn];

    return sum;
}
int* SumInLines(int** Array, int n, int k, bool Save)
{
    if (Save)
    {
        int* Sums = CreateArray(n);
        for (int i = 0; i < n; i++)
        {
            //std::cout <<"i = " << i << " ";
            Sums[i] = SumInLine(Array, i, n, k);
        }
        return Sums;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << SumInLine(Array, i, n, k) << " ";
        }
        std::cout << std::endl;
        return 0;
    }
}
int* SumInColumns(int** Array, int n, int k, bool Save)
{
    if (Save)
    {
        int* Sums = CreateArray(k);
        for (int j = 0; j < k; j++)
        {
            Sums[j] = SumInColumn(Array, j, n, k);
        }
        return Sums;
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            std::cout << SumInColumn(Array, i, n, k) << " ";
        }
        std::cout << std::endl;
        return 0;
    }
}
#include <iostream>

int BinomialCoefficients(int n, int k, int** buffer);
int BinomialCoefficients(int n, int k);
int DeleteArray(int** Array, int n, int k);
int** CreateArray(int n, int k);

int main(int argc, char* argv[])
{
    int n = 0;
    int k = 0;

    std::cin >> n >> k;

    std::cout << BinomialCoefficients(n, k);

    return 0;
}

int BinomialCoefficients(int n, int k, int** buffer)
{
    if (n == k || k == 0)
        return 1;
    if (buffer[n][k] == 0)
        buffer[n][k] = BinomialCoefficients(n - 1, k, buffer) + BinomialCoefficients(n - 1, k - 1, buffer);
    return buffer[n][k];
}
int BinomialCoefficients(int n, int k)
{
    int** buffer = new int* [n + 1] {0};
    int   result = 0;
    for (int i = 0, p = k; i < n; i++)
        buffer[i] = new int[p + 1] {0};

    if (n == k || k == 0)
        return 1;
    result = BinomialCoefficients(n - 1, k, buffer) + BinomialCoefficients(n - 1, k - 1, buffer);

    DeleteArray(buffer, n, 0);

    return result;
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
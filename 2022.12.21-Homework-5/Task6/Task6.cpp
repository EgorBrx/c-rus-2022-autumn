#include <iostream>

int* CreateArray(int n);
int FillArray(int* Array, int n);
int DeleteArray(int* Array, int n);

int main(int argc, char* argv[])
{
    int n       = 0;
    int NumMax  = 0;
    int Current = 0;

    std::cin >> n;
    int* V = CreateArray(n);
    int* P = CreateArray(n);

    FillArray(V, n);
    FillArray(P, n);

    int Max = V[0] * P[0];

    for (int i = 0; i < n; i++)
    {
        Current = V[i] * P[i];
        if (Current > Max)
        {
            Max = Current;
            NumMax = i;
        }
    }

    std::cout << NumMax + 1;
    
    DeleteArray(V, n);
    DeleteArray(P, n);

    return EXIT_SUCCESS;
}

int FillArray(int* Array, int n)
{
    for (int i = 0; i < n; i++)
        std::cin >> Array[i];

    return 0;
}
int* CreateArray(int n)
{
    int* Array = new int[n] {0};

    return Array;
}
int DeleteArray(int* Array, int n)
{
    delete[] Array;

    return 0;
}
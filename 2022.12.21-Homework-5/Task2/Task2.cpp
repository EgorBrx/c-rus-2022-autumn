#include <iostream>

//general
int* CreateArray(int n);
int FillArray(int* Array, int n);
int ShowArray(int* Array, int n);

int main(int argc, char* argv[])
{
    int n        = 0;
    int L        = 0;
    int R        = 0;
    int Max      = 0;
    int MaxIndex = 0;
    std::cin >> n;
    int* A = CreateArray(n);
    FillArray(A, n);

    std::cin >> L >> R;
    Max = A[L - 1];
    MaxIndex = L - 1;
    

    for (int i = L - 1; i <= R - 1; i++)
        if (A[i] > Max)
        {
            Max = A[i];
            MaxIndex = i;
        }

    std::cout << Max << " " << MaxIndex + 1;

    return EXIT_SUCCESS;
}

//general
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
int ShowArray(int* Array, int n)
{
    for (int i = 0; i < n; i++)
        std::cout << Array[i] << " ";
    std::cout << std::endl;
    return 0;
}




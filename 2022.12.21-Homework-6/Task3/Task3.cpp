#include <iostream>

int FillArray(int* Array, int n);

int main(int argc, char* argv[])
{
    int n = 0;
    int x = 0;
    int result = 1;

    std::cin >> n;
    int A[100]{ 0 };
    FillArray(A, n);
    
    std::cin >> x;
    

    while (A[result - 1] >= x)
    {
        result++;
    }
    std::cout << result;

    return EXIT_SUCCESS;
}

int FillArray(int* Array, int n)
{
    for (int i = 0; i < n; i++)
        std::cin >> Array[i];
    return 0;
}
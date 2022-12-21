#include <iostream>

int ShowSubArray(int* Array, int left, int right);

int* CreateArray(int n);
int FillArray(int* Array, int n);
int ShowArray(int* Array, int n);

int main(int argc, char* argv[])
{
    int n = 0;
    int m = 0;
    int Array[1000]{ 0 };
    int i = 0;
    int j = 0;

    std::cin >> n;
    FillArray(Array, n);
    std::cin >> m;

    for (int k = 0; k < m; k++)
    {
        std::cin >> i >> j;
        ShowSubArray(Array, i, j);
    }

    return EXIT_SUCCESS;
}

int ShowSubArray(int* Array, int left, int right)
{
    left--;
    right--;
    if (left <= right)
    {
        for (; left <= right; left++)
            std::cout << Array[left] << " ";
        std::cout << std::endl;
    }
    else
    {
        for (; left >= right; left--)
            std::cout << Array[left] << " ";
        std::cout << std::endl;
    }

    return 0;
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




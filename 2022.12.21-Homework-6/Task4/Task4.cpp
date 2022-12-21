#include <iostream>

int FillArray(int* Array, int n);
int ShowArray(int* Array, int n);
int ReversSubArray(int* Array, int left, int right);
int swap(int& a, int& b);

int main(int argc, char* argv[])
{
    int N = 0;
    int A = 0;
    int B = 0;
    int C = 0;
    int D = 0;
    int Array[1000]{ 0 };

    std::cin >> N >> A >> B >> C >> D;
    for (int i = 0; i < N; i++)
        Array[i] = i + 1;

    ReversSubArray(Array, A, B);
    ReversSubArray(Array, C, D);
    ShowArray(Array, N);

    return EXIT_SUCCESS;
}

int swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
    return 0;
}

int ReversSubArray(int* Array, int left, int right)
{
    left--;
    right--;
    if (left > right)
        return 0;//swap(left, right);
    for (int i = 0; i <= (right - left) / 2; i++)
        swap(Array[i + left], Array[right - i]);
    return 0;
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
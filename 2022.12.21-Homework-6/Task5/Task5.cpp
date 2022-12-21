#include <iostream>

int FillArray(int* Array, int n);
int ShowArray(int* Array, int n);
int ReversSubArray(int* Array, int left, int right);
int swap(int& a, int& b);
int ShiftArray(int* Array, int n, int shift);
int FindNumInArray(int* Array, int n, int num);

int main(int argc, char* argv[])
{
    int N = 0;
    int shift = 0;
    int Array[100000]{ 0 };

    std::cin >> N;
    FillArray(Array, N);

    shift = (N - FindNumInArray(Array, N, 1)) % N;
    ShiftArray(Array, N, shift);
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
int FindNumInArray(int* Array, int n, int num)
{
    for (int i = 0; i < n; i++)
        if (Array[i] == num)
            return i;

    return -1;
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
int ShiftArray(int* Array, int n, int shift)
{
    shift = shift % n;

    if (shift < 0)
        shift += n;
    if (shift == 0)
        return 0;

    ReversSubArray(Array, 1, n);
    ReversSubArray(Array, 1, shift);
    ReversSubArray(Array, shift + 1, n);

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
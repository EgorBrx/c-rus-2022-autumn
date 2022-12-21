#include <iostream>

int FillArray(int* Array, int n);
int ShowArray(int* Array, int n);
int ReversSubArray(int* Array, int left, int right);
int swap(int& a, int& b);
int ShiftArray(int* Array, int n, int shift);

int main(int argc, char* argv[])
{
    int n     = 0;
    int shift = 0;

    std::cin >> n;
    int Array[10000]{ 0 };

    FillArray(Array, n);
    std::cin >> shift;

    ShiftArray(Array, n, shift);
    ShowArray(Array, n);

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
        return 0;
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
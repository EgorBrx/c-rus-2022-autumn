#include <iostream>

int FillArray(int* Array, int n);

int main(int argc, char* argv[])
{
    int n = 0;
    int length = 1;
    int price = 0;
    int price_index = 0;
    int old_price_index = 0;
    int result = 0;
    int Array[100]{ 0 };
    std::cin >> n;

    FillArray(Array, n);

    price = Array[0];

    while (old_price_index != n - 1)
    {
        for (int i = old_price_index + 1; i < n; ++i)
            if (Array[i] > price)
            {
                price = Array[i];
                price_index = i;
            }
        length += price_index - old_price_index;
        result += length * price;
        old_price_index = price_index;
        price = 0;
        length = 0;
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
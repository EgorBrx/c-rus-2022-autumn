#include <iostream>
#include <cstring>

int DeleteCharsString(char* str, int left, int right, int& LentghResult);
std::string DeleteCharsString(char* str);

int main(int argc, char* argv[])
{
    char str[1001];
    std::cin >> str;

    std::cout << DeleteCharsString(str);

    return EXIT_SUCCESS;
}


int DeleteCharsString(char* str, int left, int right, int& LentghResult)
{
    if (left < right)
    {
        if (str[left] == str[right])
        {
            str[left] = '0';
            str[right] = '0';

        }
        else
            LentghResult += 2;
        DeleteCharsString(str, left + 1, right - 1, LentghResult);
    }
    if (left == right)
    {
        LentghResult++;
    }

    return 0;
}
std::string DeleteCharsString(char* str)
{
    int LentghResult = 0;

    DeleteCharsString(str, 0, strlen(str) - 1, LentghResult);
    char* result = new char[LentghResult + 1] {'0'};

    for (int i = 0, curr = 0; curr < LentghResult; i++)
    {
        if (str[i] != '0')
        {
            result[curr] = str[i];
            curr++;
        }
    }

    return result;
}
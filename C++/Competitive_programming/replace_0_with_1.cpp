#include <iostream>
#include <string>

int replaceZeroWithOne(int num)
{
    int result = 0;
    int place = 1;

    while (num > 0)
    {
        int digit = num % 10;
        if (digit == 0)
        {
            digit = 1;
        }
        result = digit * place + result;
        place *= 10;
        num /= 10;
    }
    return result;
}

int replaceZeroWithOneUsingString(int num)
{
    std::string str = std::to_string(num);

    for (char &ch : str)
    {
        if (ch == '0')
        {
            ch = '1';
        }
    }

    return std::stoi(str);
}

int main()
{
    std::cout << "Apporoach 1 : " << replaceZeroWithOne(30201) << std::endl;
    std::cout << "Apporoach 2 : " << replaceZeroWithOneUsingString(30201) << std::endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

std::string compress_string(std::string &input)
{
    if (input.empty())
    {
        return "";
    }

    std::unordered_map<char, int> temp_map;
    std::vector<char> vec;
    std::string compressed;

    for (char ch : input)
    {
        if (temp_map[ch] == 0)
        {
            vec.push_back(ch);
        }
        temp_map[ch]++;
    }

    for (char ch : vec)
    {
        compressed += ch;
        compressed += std::to_string(temp_map[ch]);
    }

    return compressed;
}

int main()
{
    std::string input = "hheegwh";
    std::string output = compress_string(input);
    std::cout << " output : " << output << std::endl;
    return 0;
}
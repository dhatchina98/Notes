#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main()
{
    // creating map
    std::map<int, int> map = {{1, 5}, {2, 4}, {3, 8}, {4, 6}};
    
    // creating vector which contains pairs
    std::vector<std::pair<int, int>> mapPairs;

    // add map pairs to vector
    for (const auto &pair : map)
    {
        mapPairs.push_back(pair);
    }

    std::sort(mapPairs.begin(), mapPairs.end(),
              [](const std::pair<int, int> &a, const std::pair<int, int> &b)
              { return a.second < b.second; });

    for (const auto &pair : mapPairs)
    {
        std::cout << "{" << pair.first << ", " << pair.second << "}" << std::endl;
    }

    return 0;
}
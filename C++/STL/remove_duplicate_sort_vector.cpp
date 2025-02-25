#include <iostream>
#include <vector>
#include <algorithm> // For sort() and unique()

int main()
{
    // Initialize the vector
    std::vector<int> vec = {4, 1, 3, 2, 4, 4, 6};

    // Step 1: Sort the vector
    std::sort(vec.begin(), vec.end());

    // Step 2: Remove duplicates
    auto last = std::unique(vec.begin(), vec.end());

    // Step 3: Erase the "removed" elements
    vec.erase(last, vec.end());

    // Print the result
    std::cout << "Sorted vector with duplicates removed: ";
    for (const auto &elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}

/**
 *  Another Way
 */

#include <iostream>
#include <vector>
#include <set>

int main()
{
    std::vector<int> vector = {2, 1, 3, 2, 5, 6};

    std::set<int> set_temp(vector.begin(), vector.end());

    std::vector<int> sorted_unique_vector(set_temp.begin(), set_temp.end());

    // Print the result
    std::cout << "Sorted vector with duplicates removed: ";
    for (const auto &elem : sorted_unique_vector)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}

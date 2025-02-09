#include <iostream>
#include <list>
#include <iterator>

// Function to find the merging point of two linked lists
std::list<int>::iterator findMergePoint(std::list<int>& list1, std::list<int>& list2) {
    auto it1 = list1.begin();
    auto it2 = list2.begin();
    
    // Calculate the lengths of both lists
    size_t len1 = list1.size();
    size_t len2 = list2.size();
    
    // Align starting points
    if (len1 > len2) {
        std::advance(it1, len1 - len2);
    } else {
        std::advance(it2, len2 - len1);
    }
    
    // Traverse both lists together to find the merge point
    while (it1 != list1.end() && it2 != list2.end()) {
        if (&(*it1) == &(*it2)) { // Compare addresses to check merge point
            return it1;
        }
        ++it1;
        ++it2;
    }
    
    return list1.end(); // No merge point found
}

int main() {
    // Create two linked lists with a merge point
    std::list<int> list1 = {1, 2, 3, 4, 5};
    std::list<int> list2 = {9, 10};

    // Creating a merge point
    auto it = list1.begin();
    std::advance(it, 2); // Merge starts at node with value 3
    list2.splice(list2.end(), list1, it, list1.end());

    // Find the merge point
    auto mergePoint = findMergePoint(list1, list2);

    if (mergePoint != list1.end()) {
        std::cout << "Merge point found at value: " << *mergePoint << std::endl;
    } else {
        std::cout << "No merge point found." << std::endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void brute_force_solution(vector<int> &vec)
{
    // add elements to set  // Time complexity : O(N log N)
    set<int> sett;
    for (int i = 0; i < vec.size(); i++)
    {
        sett.insert(vec[i]);
    }

    // add set elements to array // Time complexity : O(N)
    int index = 0;
    for (auto it : sett)
    {
        vec[index] = it;
        index++;
    }

    // finally array containes unique elements at first and return index also

    // Total Time complexity : O(N log N + N)
    // space complexity : O(N) -> maximum size of set

    for (auto it : vec)
    {
        cout << it << ", ";
    }
    cout << endl;
}

void optimal_solution(vector<int> &vec)
{
    int i = 0;

    for (int j = 1; j < vec.size(); j++)
    {
        if (vec[i] != vec[j])
        {
            vec[i + 1] = vec[j];
            i++;
        }
        i++;
    }
    // return i+1 for the end iterator

    // Time complexity : O(N)
    // Space complexity : O(1)

    for (auto it : vec)
    {
        cout << it << ", ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec = {1, 2, 5, 5, 6, 7, 7, 8};

    brute_force_solution(vec);

    optimal_solution(vec);

    return 0;
}
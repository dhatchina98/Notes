#include <iostream>
#include <vector>

using namespace std;

void brute_force_method(vector<int> &vec)
{
    // sort the array 
    // return the last element

    // Time complexity : O(N log N)
    // Space complexity : O(1)
}

void optimal_solution(vector<int> &vec)
{
    // Time complexity : O(N)

    int largest = vec[0];

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] > largest)
        {
            largest = vec[i];
        }
    }

    cout << "largest : " << largest << endl;
}

int main()
{
    vector<int> vec = {2, 6, 7, 1, 2, 8, 5};

    brute_force_method(vec);

    optimal_solution(vec);

    return 0;
}
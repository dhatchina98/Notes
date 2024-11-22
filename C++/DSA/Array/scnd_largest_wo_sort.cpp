#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void brute_force_solution(vector<int> &vec)
{
    // sort the array   // Time complexity : O(N log N)
    sort(vec.begin(), vec.end());

    // return the second largest element  // Time complexity : O(N)
    int largest = vec[vec.size() - 1];

    int second_largest = -1;

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        if (vec[i] != largest)
        {
            second_largest = vec[i];
            cout << "second largest : " << second_largest << endl;
            break;
        }
    }

    if (second_largest == -1)
    {
        cout << "there is no second largest " << endl;
    }

    // Total Time complexity : N log N + N
}

void better_solution(vector<int> &vec)
{
    // find the largest   // Time complexity : O(N)
    int largest = vec[0];

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] > largest)
        {
            largest = vec[i];
        }
    }

    // find the second largest // Time complexity : O (N)
    int second_largest = -1;

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] > second_largest && vec[i] != largest)
        {
            second_largest = vec[i];
        }
    }

    // Total Time complexity : O(2N)

    cout << "second largest : " << second_largest << endl;
}

void optimal_solution(vector<int> &vec)
{
    // Time complexity : O(N)

    int largest = vec[0];
    int second_largest = -1;

    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] > largest)
        {
            second_largest = largest;
            largest = vec[i];
        }
        else if (vec[i] < largest && vec[i] > second_largest)
        {
            second_largest = vec[i];
        }
    }

    cout << "second largest : " << second_largest << endl;
}

void second_smallest_optimal(vector<int> &vec)
{
     // Time complexity : O(N)
     
    int smallest = vec[0];
    int second_smallest = INT_MAX;

    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] < smallest)
        {
            second_smallest = smallest;
            smallest = vec[i];
        }
        else if (vec[i] > smallest && vec[i] < second_smallest)
        {
            second_smallest = vec[i];
        }
    }

    cout << "second smallest : " << second_smallest << endl;
}

int main()
{
    vector<int> vec = {2, 6, 7, 1, 2, 8, 5, 8};

    brute_force_solution(vec);

    better_solution(vec);

    optimal_solution(vec);

    second_smallest_optimal(vec);

    return 0;
}
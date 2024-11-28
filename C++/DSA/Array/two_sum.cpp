#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int better_solution(int *arr, int n, int sum)
{
    int count = 0;

    unordered_map<int, int> mapp;

    for (int i = 0; i < n; i++) // Time complexity : O(N)
    {
        mapp[i] = arr[i];
    }

    for (int i = 0; i < mapp.size(); i++) // Time complexity : O(N)
    {
        if (mapp.find(sum - mapp[i]) != mapp.end())
        {
            cout << mapp[i] << " - " << mapp.find(sum - mapp[i])->first << endl;
            count++;
        }
    }
    return count;
}

int optimal_solution(int *arr, int n, int sum)
{
    int count = 0;

    sort(arr, arr + n); // Time complexity : O(N log N)

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int s = arr[low] + arr[high];
        if (s > sum)
        {
            high--;
        }
        else if (s < sum)
        {
            low++;
        }
        else
        {
            cout << arr[low] << " - " << arr[high] << endl;
            count++;
            low++;
            high--;
        }
    }
    return count;
}

int main()
{
    int arr[] = {1, 4, 7, 3, 2, 8, 9, 5};

    int sum = 11;

    size_t size = (sizeof(arr) / sizeof(int)) - 1;

    cout << better_solution(arr, size, sum) << endl;
    cout << optimal_solution(arr, size, sum) << endl;

    return 0;
}
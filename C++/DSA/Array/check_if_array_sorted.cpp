#include <iostream>
#include <vector>

using namespace std;

void is_sorted(vector<int> &vec)
{
    // Time complexity : O(N)
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] >= vec[i - 1])
        {
        }
        else
        {
            cout << "not sorted" << endl;
            return;
        }
    }
    cout << "sorted" << endl;
}

int main()
{
    vector<int> vec1 = {1, 2, 5, 5, 6, 7, 7, 8};
    vector<int> vec2 = {1, 2, 1, 6, 7, 7, 8, 7};

    is_sorted(vec1);
    is_sorted(vec2);
    return 0;
}
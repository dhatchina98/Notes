#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0};

    int *low = arr;

    int *high = arr + (sizeof(arr) / sizeof(int)) - 1;

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        if (low < high)
        {
            if (*low == 1)
            {
                while (*high != 0)
                {
                    high--;
                }
                int temp = *low;
                *low = *high;
                *high = temp;
            }
        }
        else
        {
            break;
        }
        low++;
    }

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        cout << arr[i] << ",";
    }
    cout << endl;
    return 0;
}
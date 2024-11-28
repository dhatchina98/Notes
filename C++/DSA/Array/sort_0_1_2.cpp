#include <iostream>

using namespace std;

int main()
{
    int arr[] = {2, 1, 0, 2, 1, 0, 1, 1, 2, 0, 0, 1, 1, 2, 0};

    int low = 0;

    int mid = 0;

    int high = (sizeof(arr) / sizeof(int)) - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            int temp = arr[mid];
            arr[mid] = arr[low];
            arr[low] = temp;
            mid++;
            low++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
    }

    for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++)
    {
        cout << arr[i] << ",";
    }
    cout << endl;

    return 0;
}

// int main()
// {
//     int arr[] = {2, 1, 0, 2, 1, 0, 1, 1, 2, 0, 0, 1, 1, 2, 0};

//     int *low = arr;

//     int *mid = arr;

//     int *high = arr + (sizeof(arr) / sizeof(int)) - 1;

//     for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
//     {
//         if (*mid == 0)
//         {
//             int temp = *mid;
//             *mid = *low;
//             *low = temp;
//             mid++;
//             low++;
//         }
//         if (*mid == 1)
//         {
//             mid++;
//         }
//         if (*mid == 2)
//         {
//             int temp = *high;
//             *high = *mid;
//             *mid = temp;
//             high--;
//         }
//         // for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
//         // {
//         //     cout << arr[i] << ",";
//         // }
//         // cout << endl;
//     }

//     for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
//     {
//         cout << arr[i] << ",";
//     }
//     cout << endl;

//     return 0;
// }
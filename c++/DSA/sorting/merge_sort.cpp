#include <iostream>

void merge_sort(int arr[], int length);
void merge_sort_recursion(int arr[], int l, int r);
void merge_sorted_arrays(int arr[], int l, int m, int r);
void practice(int arr[], int length);

void merge_sort(int arr[], int length)
{
    merge_sort_recursion(arr, 0, length - 1);
}

void merge_sort_recursion(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        merge_sort_recursion(arr, l, m);
        merge_sort_recursion(arr, m + 1, r);

        merge_sorted_arrays(arr, l, m, r);
    }
}

void merge_sorted_arrays(int arr[], int l, int m, int r)
{
    int left_length = m - l + 1;
    int right_length = r - m;

    int temp_left[left_length];
    int temp_right[right_length];

    for (int i = 0; i < left_length; i++)
    {
        temp_left[i] = arr[l + i];
    }

    for (int i = 0; i < right_length; i++)
    {
        temp_right[i] = arr[m + i + 1];
    }

    int i, j, k;

    for (i = 0, j = 0, k = l; k <= r; k++)
    {
        if ((i < left_length) && (j >= right_length || temp_left[i] <= temp_right[j]))
        {
            arr[k] = temp_left[i];
            i++;
        }
        else
        {
            arr[k] = temp_right[j];
            j++;
        }
    }
}

int main()
{
    int a[] = {60, 50, 10, 20, 90, 30, 70, 40, 80, 110, 100, 30};
    int b[] = {60, 50, 10, 20, 90, 30, 70, 40, 80, 110, 100, 30};

    int length = 12;

    merge_sort(a, length);
    practice(b, length);

    std::cout << "merge sort\n"
              << std::endl;
    for (int i = 0; i < length; i++)
    {
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
    }

    std::cout << "\npractice\n"
              << std::endl;
    for (int i = 0; i < length; i++)
    {
        std::cout << "b[" << i << "] = " << b[i] << std::endl;
    }

    return 0;
}

// practice purpose

void practice(int arr[], int length)
{
}
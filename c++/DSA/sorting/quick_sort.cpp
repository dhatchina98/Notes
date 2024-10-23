#include <iostream>
#include <utility>
#include <cstdlib>
#include <ctime>

void quick_sort(int arr[], int length);
void quick_sort_recursion(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void practice(int arr[], int length);

void quick_sort(int arr[], int length)
{
    // create new random values by giving current time
    srand(time(NULL));
    // calling recursive function
    quick_sort_recursion(arr, 0, length - 1);
}

void quick_sort_recursion(int arr[], int low, int high)
{
    if (low < high)
    {
        // find pivot index and do partition
        int pivot_index = partition(arr, low, high);
        // calling recursive with two parts based on pivot
        quick_sort_recursion(arr, low, pivot_index - 1);
        quick_sort_recursion(arr, pivot_index + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    // to find random pivot with random values
    int pivot_index = low + (rand() % (high - low + 1));

    // swapping pivot with high for old logic
    if (pivot_index != high)
    {
        std::swap(arr[pivot_index], arr[high]);
    }
    // current pivot value
    int pivot_value = arr[high];

    int i = low;

    // partition the given array based on pivot
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot_value)
        {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }

    std::swap(arr[i], arr[high]);

    return i;
}

int main()
{
    int a[] = {60, 50, 10, 20, 90, 30, 70, 40, 80, 110, 100, 30};
    int b[] = {60, 50, 10, 20, 90, 30, 70, 40, 80, 110, 100, 30};

    int length = 12;

    quick_sort(a, length);
    practice(b, length);

    std::cout << "quick sort\n"
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

int part(int arr[], int low, int high)
{
    int pivot_index = low + (rand() % (high - low + 1));
    if (pivot_index != high)
    {
        std::swap(arr[pivot_index], arr[high]);
    }
    int pivot_value = arr[high];

    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot_value)
        {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }

    std::swap(arr[i], arr[high]);

    return i;
}

void qsort_recur(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot_index = part(arr, low, high);

        qsort_recur(arr, low, pivot_index - 1);
        qsort_recur(arr, pivot_index + 1, high);
    }
}

void practice(int arr[], int length)
{
    srand(time(NULL));
    qsort_recur(arr, 0, length - 1);
}
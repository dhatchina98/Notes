#include <stdio.h>
#include <stdbool.h>

void print(int arr[], int length)
{
    printf("array = {");
    for (int i = 0; i < length; i++)
    {
        printf(" %d", arr[i]);
        if (i < length - 1)
        {
            printf(",");
        }
        else
        {
            printf("}\n");
        }
    }
}

void bubble_sort(int arr[], int length)
{
    /**
     *  it will take O(N^2) time complexity in worst case
     */
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < (length - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void optimized_bubble_sort(int arr[], int length)
{
    /**
     * anyway after first iteration largest element went last so
     * no need to check that again.
     * same like that after every iteration u can skip the sorted values.
     */
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < (length - 1 - i); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void most_optimized_bubble_sort(int arr[], int length)
{
    /**
     * if array sorted in some iteration we can exit immediately,
     * if no value swapped in complete iteration the array is already sorted
     */
    bool swapped = false;
    int i = 0;
    do
    {
        // set false for every iteration
        swapped = false;
        for (int j = 0; j < (length - 1 - i); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        i++;
    } while (swapped);
}


int main()
{

    int arr1[] = {5, 2, 6, 9, 8, 1, 7, 3, 0, 4};
    int arr2[] = {5, 2, 6, 9, 8, 1, 7, 3, 0, 4};
    int arr3[] = {5, 2, 6, 9, 8, 1, 7, 3, 0, 4};

    int length = 10;

    printf("bubble sort\n");
    print(arr1, length);
    bubble_sort(arr1, length);
    print(arr1, length);
    printf("\noptimized\n");
    print(arr2, length);
    optimized_bubble_sort(arr2, length);
    print(arr2, length);
    printf("\nmost optimized\n");
    print(arr3, length);
    most_optimized_bubble_sort(arr3, length);
    print(arr3, length);

    return 0;
}
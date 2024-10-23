#include <iostream>

void insertion_sort(int a[], int length)
{
    /**
     * iterating from the 2nd element
     * checking left sorted array and
     * insert in right position
     */
    for (int i = 1; i < length; i++)
    {
        // storing current value
        int key = a[i];
        int j = i - 1;
        // loop for shifing values
        while (j >= 0 && a[j] > key)
        {
            // shifting valuu to right
            a[j + 1] = a[j];
            // decrement value for next iteration
            j = j - 1;
        }
        // insert key at right position
        a[j + 1] = key;
    }
}

void practice(int a[], int length)
{
    for (int i = 1; i < length; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int a[] = {4, 7, 2, 3, 8, 1, 6, 5};
    int b[] = {4, 7, 2, 3, 8, 1, 6, 5};

    int length = 8;

    insertion_sort(a, length);
    practice(b, length);

    std::cout << "insertion sort\n" << std::endl;
    for (int i = 0; i < length; i++)
    {
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
    }

    std::cout << "\npractice\n" << std::endl;
    for (int i = 0; i < length; i++)
    {
        std::cout << "b[" << i << "] = " << b[i] << std::endl;
    }

    return 0;
}
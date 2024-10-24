#include <iostream>

// given : 6, 2, 1, 5, 4, 3
// step1 : 1, 2, 6, 5, 4, 3
// step2 : 1, 2, 3, 5, 4, 6
// step3 : 1, 2, 3, 4, 5, 6

void selection_sort(int a[], int length)
{
    // outer for loop to iterate
    for (int i = 0; i < length - 1; i++)
    {
        // consider the current position as minimum
        int min_pos = i;

        // iterate the rest array to find minimum
        for (int j = i + 1; j < length; j++)
        {
            // get the minimum value index
            if (a[j] < a[min_pos])
            {
                min_pos = j;
            }
        }

        // swap minimum value with current postion
        if (min_pos != i)
        {
            int temp = a[min_pos];
            a[min_pos] = a[i];
            a[i] = temp;
        }
    }
}

void practice(int a[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int min_pos = i;
        for (int j = i + 1; j < length; j++)
        {
            if (a[min_pos] > a[j])
            {
                min_pos = j;
            }
        }
        if (min_pos != i)
        {
            int temp = a[min_pos];
            a[min_pos] = a[i];
            a[i] = temp;
        }
    }
}

int main()
{
    int a[] = {6, 2, 1, 5, 4, 3};
    int b[] = {6, 2, 1, 5, 4, 3};

    int length = 6;

    selection_sort(a, length);
    practice(b, length);

    std::cout << "selection sort" << std::endl;
    for (int i = 0; i < length; i++)
    {
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
    }

    std::cout << "\npractice" << std::endl;
    for (int i = 0; i < length; i++)
    {
        std::cout << "b[" << i << "] = " << b[i] << std::endl;
    }

    return 0;
}
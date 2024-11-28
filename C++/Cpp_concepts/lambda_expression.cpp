#include <iostream>
#include <vector>

using namespace std;

// function accepting the function pointer as a param
void forEach(vector<int> &vec, void (*func)(int))
{
    for (int n : vec)
    {
        // calling function using its pointers
        func(n);
    }
}

int main()
{
    vector<int> vec = {2, 4, 5, 6, 8};
    // passing lambda as a param to a function pointer
    forEach(vec, [](int n)
            { cout << "value is : " << n << endl; });

    return 0;
}
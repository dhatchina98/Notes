#include <iostream>
#include <vector>

using namespace std;

// function to be passed
void print(int n)
{
    cout << "value is : " << n << endl;
}

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
    // passing function pointer as a param
    forEach(vec, print);
    return 0;
}
#include <iostream>

using namespace std;

class Number
{
public:
    // pointer variable
    int *n;

    // normal constructor to allocate memory dynamically
    Number(int num)
    {
        n = (int *)malloc(sizeof(int));
        *n = num;
    }

    // copy constructor for deep copy
    Number(const Number &num)
    {
        n = (int *)malloc(sizeof(int));
        *n = *(num.n);
    }

    // destructor for deallocate memory
    ~Number()
    {
        free(n);
    }
};

int main()
{
    // create object
    Number num1(10);
    
    // copy object using copy constructor
    Number num2 = num1;

    cout << "num 1 value :" << *(num1.n) << endl;
    cout << "num 2 value :" << *(num2.n) << endl;

    // change the value in first object
    *(num1.n) = 21;

    // verifying both object
    cout << "num 1 value :" << *(num1.n) << endl;
    cout << "num 2 value :" << *(num2.n) << endl;

    return 0;
}
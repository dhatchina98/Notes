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

    // copy assignment operator for deep copy
    Number &operator=(const Number &num)
    {
        if (this != &num)
        {
            n = (int *)malloc(sizeof(int));
            *n = *(num.n);
            return *this;
        }
    }

    // destruvtor for deallocate memory
    ~Number()
    {
        free(n);
    }
};

int main()
{
    // create object
    Number num1(10);

    Number num2(25);

    // copy object using copy assignment operator
    num2 = num1;

    cout << "num 1 value :" << *(num1.n) << endl;
    cout << "num 2 value :" << *(num2.n) << endl;

    // change the value in first object
    *(num1.n) = 21;

    // verifying both object
    cout << "num 1 value :" << *(num1.n) << endl;
    cout << "num 2 value :" << *(num2.n) << endl;

    return 0;
}
#include <iostream>

using namespace std;

struct integer
{
    // member variable of object
    int val;

    // overloading + operator
    integer operator+(const integer &i)
    {
        integer o;
        o.val += this->val + i.val;
        return o;
    }
};

int main()
{
    // object 1
    integer a;
    a.val = 10;
    // object 2
    integer b;
    b.val = 20;
    // using overloaded operator
    integer c = a + b;
    // print all objects
    cout << "integer a :" << a.val << endl;
    cout << "integer b :" << b.val << endl;
    cout << "integer c :" << c.val << endl;
    return 0;
}

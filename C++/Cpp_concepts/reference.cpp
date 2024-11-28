#include <iostream>

using namespace std;

int main()
{
    // initialize variable
    int a = 20;
    // assiging exist variable to a reference
    int &b = a;

    // verify the variable and its reference value and address
    cout << "a : " << a << endl;
    cout << "&a : " << &a << endl;
    cout << "b : " << b << endl;
    cout << "&b : " << &b << endl;

    // changing the reference value
    b = 15;

    // verify the variable and its reference value and address
    cout << "a : " << a << endl;
    cout << "&a : " << &a << endl;
    cout << "b : " << b << endl;
    cout << "&b : " << &b << endl;

    return 0;
}
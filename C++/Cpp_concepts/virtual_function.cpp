#include <iostream>

using namespace std;

// Base class
class Base
{
public:
    virtual void func()
    {
        cout << "Base class function" << endl;
    }
};

// Derived class from Base class
class Derived1 : public Base
{
public:
    // overriding the base class virtual function
    void func() override
    {
        cout << "Derived 1 class function" << endl;
    }
};

// another Derived class from Base class
class Derived2 : public Base
{
public:
    // overriding the base class virtual function
    void func() override
    {
        cout << "Derived 2 class function" << endl;
    }
};

int main()
{
    // calling function using Base class object
    Base *ptr1 = new Base();
    ptr1->func();

    // calling function using Derived 1 class object
    Base *ptr2 = new Derived1();
    ptr2->func();

    // calling function using Derived 2 class object
    Base *ptr3 = new Derived2();
    ptr3->func();
    return 0;
}
#include <iostream>

using namespace std;

class Base
{
public:
    int *data;

    Base(int num)
    {
        data = (int *)malloc(sizeof(int));
        *data = num;
        cout << "Base Constructor" << endl;
    }

    virtual ~Base()
    {
        free(data);
        cout << "Base Destructor" << endl;
    }
};

class Derived : public Base
{
public:
    int *extra_data;

    Derived(int num, int extra_num) : Base(num)
    {
        extra_data = (int *)malloc(sizeof(int));
        *extra_data = extra_num;
        cout << "Derived Constructor" << endl;
    }

    ~Derived()
    {
        free(extra_data);
        cout << "Derived Destructor" << endl;
    }
};

int main()
{
    Base *base = new Base(50); // Base Constructor
    delete base;               // Base Destructor

    cout << "===================" << endl;

    Derived *derived = new Derived(50, 63); // Base Constructor
                                            // Derived Constructor
                                            // Derived Destructor
    delete derived;                         // Base Destructor

    cout << "===================" << endl;

    Base *arr[] = {
        new Base(56),       // Base Constructor
        new Derived(45, 89) // Base Constructor
                            // Derived Constructor
    };

    delete arr[0]; // Base Destructor

    delete arr[1]; // Derived Destructor
                   // Base Destructor

    return 0;
}
#include <iostream>

using namespace std;

class Base
{
    // friend function
    friend void getData(const Base &base);

protected:
    int pro;

private:
    // private data
    int data;

public:
    // constructor
    Base(int num)
    {
        data = num;
        pro = num * 2;
    }
};

// definition for friend function outside of the class
void getData(const Base &base)
{
    cout << " data : " << base.data << endl;
    cout << " pro : " << base.pro << endl;
}

int main()
{
    Base base(10);
    // calling friend function with object
    getData(base);
    return 0;
}
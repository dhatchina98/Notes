#include <iostream>

using namespace std;

class Base
{
public:
    Base() = default;
    Base(int num) : a(num) {}

    Base(const Base &other)
    {
        cout << "copy constructor" << endl;
    }

    Base &operator=(const Base &other)
    {
        cout << "copy assignment operator" << endl;
        return *this;
    }

    Base(Base &&other)
    {
        cout << "move constructor" << endl;
    }

    Base &operator=(Base &&other)
    {
        cout << "move assignment operator" << endl;
        return *this;
    }

private:
    int a;
};

int main()
{
    // default constructor
    Base b1;
    // copy constructor
    Base b2(b1);
    // copy constructor
    Base b3 = b1;
    // copy assignment operator
    b3 = b2;
    // copy assignment operator
    b3.operator=(b2);

    // default constructor
    Base b4;
    // move constructor
    Base b5(std::move(b4));
    // move constructor
    Base b6 = std::move(b4);
    // move assignment operator
    b6 = std::move(b5);
    // move assignment operator
    b6.operator=(std::move(b5));
    return 0;
}
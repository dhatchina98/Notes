#include <iostream>

using namespace std;

class Number
{
public:
    int *n;
    Number(const Number &num)
    {
        cout << "copy constructor" << endl;
        n = (int *)malloc(sizeof(int));
        *n = *(num.n);
    }

    Number(int num)
    {
        n = (int *)malloc(sizeof(int));
        *n = num;
        cout << "default constructor" << endl;
    }

    ~Number()
    {
        free(n);
    }

    int get()
    {
        return *n;
    }
};

int main()
{
    Number n(5);

    cout << n.get() << endl;

    Number n1 = n;

    cout << n1.get() << endl;

    *(n.n) = 10;

    cout << n.get() << endl;
    cout << n1.get() << endl;

    return 0;
}
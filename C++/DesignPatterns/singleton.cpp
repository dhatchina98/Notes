#include <iostream>

using namespace std;

class Singleton
{
protected:
    // making constructor to default
    Singleton() = default;

public:
    int data;
    // static method to get object
    static Singleton &getInstance()
    {
        static Singleton singleton;
        return singleton;
    }

    // delete copy constructor
    Singleton(const Singleton &) = delete;
    // delete move constructor
    Singleton(Singleton &&) = delete;
    // delete copy assignment operator
    Singleton &operator=(const Singleton &) = delete;
    // delete move assignment operator
    Singleton &operator=(Singleton &&) = delete;
};

int main()
{
    Singleton &s1 = Singleton::getInstance();

    cout << " s1 value : " << s1.data << endl;

    s1.data = 10;

    cout << " s1 value : " << s1.data << endl;

    Singleton &s2 = Singleton::getInstance();

    cout << " s2 value : " << s2.data << endl;

    s1.data = 20;

    cout << " s1 value : " << s1.data << endl;
    cout << " s2 value : " << s2.data << endl;

    return 0;
}








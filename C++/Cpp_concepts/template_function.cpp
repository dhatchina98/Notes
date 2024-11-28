#include <iostream>

using namespace std;

// print : simple template function
template <class T>
void print(T val)
{
    cout << "value : " << val << endl;
}

// type 1 : return value using first data type
template <class V, class K>
V add1(V a, K b)
{
    V c = a + b;
    return c;
}

// type 2 : return value by mentioning in <>
template <class T, class V, class K>
T add2(V a, K b)
{
    T c = a + b;
    return c;
}

// type 3 : return value using decltype
template <class T, class V>
auto add3(T a, V b) -> decltype(a + b)
{
    return a + b;
}

int main()
{
    // print
    print(15);
    print(56.23);
    print("Hello");

    // type 1 : return value using first data type
    cout << add1(15.26, 25.56) << endl;

    // type 2 : return value by mentioning in <>
    // we are explicitly telling the return type here
    cout << add2<int>(15, 25) << endl;

    // type 3 : return value using template
    // we are deducing return type using decltype (for more info refer decltype in EXTRAS)
    cout << add3(15, 25.5) << endl;

    return 0;
}
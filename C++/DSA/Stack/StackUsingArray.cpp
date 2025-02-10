#include <iostream>
#include <iomanip>

using namespace std;

class Stack
{
private:
    int arr[10];
    int t = -1;

public:
    void push(int elem)
    {
        t++;
        arr[t] = elem;
    }

    int top()
    {
        return arr[t];
    }

    void pop()
    {
        t--;
    }

    int size()
    {
        return t + 1;
    }

    bool isEmpty()
    {
        if (t == -1)
            return true;
        else
            return false;
    }
};

int main()
{
    Stack s;

    cout << "size : " << s.size() << endl;
    cout << "empty : " << boolalpha << s.isEmpty() << endl;
    s.push(1);
    cout << "top : " << s.top() << endl;
    s.push(2);
    cout << "top : " << s.top() << endl;
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    cout << "top : " << s.top() << endl;
    cout << "size : " << s.size() << endl;
    cout << "empty : " << boolalpha << s.isEmpty() << endl;
    s.pop();
    cout << "top : " << s.top() << endl;
    s.pop();
    cout << "top : " << s.top() << endl;
    s.pop();
    cout << "top : " << s.top() << endl;
    s.pop();
    cout << "top : " << s.top() << endl;
    cout << "size : " << s.size() << endl;
    return 0;
}
#include <iostream>
#include <iomanip>

using namespace std;

class Queue
{
private:
    int cap = 5;
    int arr[5];
    int count = 0;
    int front = 0;
    int rear = 0;

public:
    void push(int elem)
    {
        if (count == cap)
        {
            cout << "Queue is Full" << endl;
            return;
        }

        arr[rear % cap] = elem;
        rear++;
        count++;
    }

    int top()
    {
        if (count == 0)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[front % cap];
    }

    void pop()
    {
        if (count == 0)
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        arr[front % cap] = -1;
        front++;
        count--;
    }

    int size()
    {
        return count;
    }

    bool isEmpty()
    {
        if (count == 0)
            return true;
        else
            return false;
    }

    void print()
    {
        for (int i = front; i < rear; i++)
        {
            cout << arr[i % cap] << ",";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    cout << "empty : " << boolalpha << q.isEmpty() << endl;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.print();
    cout << "size : " << q.size() << endl;
    cout << "top : " << q.top() << endl;
    q.pop();
    cout << "top : " << q.top() << endl;
    q.pop();
    cout << "size : " << q.size() << endl;
    cout << "empty : " << boolalpha << q.isEmpty() << endl;
    q.print();
    q.pop();
    q.pop();
    q.pop();
    q.pop();

    return 0;
}
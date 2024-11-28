#include <iostream>

using namespace std;

template <class T>
class Model
{
public:
    T count;

    Model(T cnt)
    {
        count = cnt;
        cout << "count : " << count << endl;
    }

};

int main()
{
    Model<int> mod1(10);

    Model<double> mod2(10.56);

    return 0;
}
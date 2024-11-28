#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    map<int, int> m;
    m.insert({4, 1});
    m.insert({3, 1});
    m.insert({2, 2});

    vector<pair<int, int>> v(m.rbegin(), m.rend());

    // for (auto it = m.begin(); it != m.end(); it++)
    // {
    //     cout << it->first << " - " << it->second << endl;
    // }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " - " << v[i].second << endl;
    }

    // for (auto it = m.rbegin(); it != m.rend(); it++)
    // {
    //     cout << it->first << " - " << it->second << endl;
    // }
    int step = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        step += v[i].second;
        v[i + 1].second += v[i].second;
    }

    cout << step << endl;

    return 0;
}
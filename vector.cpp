#include <bits/stdc++.h>
using namespace std;

#define fo(k, n) for (i = 0; i < n; i++)

int main()
{
    vector<int> g1;
    int i = 0;
    fo(i, 5)
    {
        g1.push_back(i);
    }

    for (auto i = g1.begin(); i != g1.end(); ++i)
    {
        cout << *i << " ";
    }

    for (auto i = g1.cbegin(); i != g1.cend(); ++i)
        cout << *i << " ";

    for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir) 
        cout << *ir << " "; 
    return 0;
}
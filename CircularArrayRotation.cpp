#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<n;i++)
#define si(x)	scanf("%d",&x)
#define devider() cout << "--------------" << endl;
#define F first
#define S second
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
typedef vector<int>	vi;

vi circularArrayRotation(vi a, int k, vi queries) {
    vi res(queries.size());
    int i;
    int size = queries.size();

    int rotateFac = a.size() - k;

    rotate(a.begin(), a.begin()+ rotateFac, a.end());

    fo(i, size)
    {
        res[i] = a[queries[i]];
    }

    return res;
}

int main()
{
    int i, j, n, k, q;
    si(n);
    si(k);
    si(q);
    vi a(n);
    vi b(q);
    fo(i, n)
    {
        si(a[i]);
    }
    fo(j, q)
    {
        si(b[j]);
    }

    vi res = circularArrayRotation(a, k , b);
    int it;
    for(auto it: res)
    {
        cout << it << endl;
        devider();
    }
    return 0;
}
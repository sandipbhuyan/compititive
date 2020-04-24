#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fib(i,n,m) for(i = n; i <m; i++)
#define si(x)	scanf("%d",&x)
#define pi(x)	printf("%d\n",x)
#define ll long long
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
/*
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

int getTotalX(vector<int> a, vector<int> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = a.size();
    int start = a[i-1];
    int end = b[0];
    int j,k,l;
    int count = 0;
    fib(j,start,end+1)
    {
        bool flag = true;
        for(int x: a)
        {
            if(j % x != 0)
            {
                flag = false;
                break;
            }
        }
        if(flag){
            for(int y: b)
            {
                if(y % j !=0)
                {
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            count++;
            cout << j << endl;
            cout << "-------------" << endl;
        }
    }

    return count;
}

int main()
{
    int i,j,k,l,m,n;
    si(m);
    si(n);
    vi a(m);
    vi b(n);
    fo(i, m)
    {
        si(a[i]); 
    }
    fo(j,n)
    {
        si(b[j]);
    }

    k = getTotalX(a,b);
    pi(k);

    return 0;
}

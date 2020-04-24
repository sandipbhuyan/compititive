#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 3
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    int a[3][3] = {{8,3,4},{1,5,9},{6,7,2}};
    int b[3][3] = {{6,1,8},{7,5,3},{2,9,4}};
    int c[3][3] = {{2,7,6},{9,5,1},{4,3,8}};
    int d[3][3] = {{4,9,2},{3,5,7},{8,1,6}};
    int e[3][3] = {{6,7,2},{1,5,9},{8,3,4}};
    int f[3][3] = {{2,9,4},{7,5,3},{6,1,8}};
    int g[3][3] = {{4,3,8},{9,5,1},{2,7,6}};
    int h[3][3] = {{8,1,6},{3,5,7},{4,9,2}};
    int sum[8] = {0,0,0,0,0,0,0,0};
    int i, j, k;

    fo(i,3) 
    {
        fo(j,3)
        {
            sum[0] += abs(s[i][j] - a[i][j]);
            sum[1] += abs(s[i][j] - b[i][j]);
            sum[2] += abs(s[i][j] - c[i][j]);
            sum[3] += abs(s[i][j] - d[i][j]);
            sum[4] += abs(s[i][j] - e[i][j]);
            sum[5] += abs(s[i][j] - f[i][j]);
            sum[6] += abs(s[i][j] - g[i][j]);
            sum[7] += abs(s[i][j] - h[i][j]);

            cout << "itereation:" << i << " " << j << " " << endl;
            cout << "sum1: " << sum[0] << endl;
            cout << "sum2: " << sum[1] << endl;
            cout << "sum3: " << sum[2] << endl;
            cout << "sum4: " << sum[3] << endl;
            cout << "sum5: " << sum[4] << endl;
            cout << "sum6: " << sum[5] << endl;
            cout << "sum7: " << sum[6] << endl;
            cout << "sum8: " << sum[7] << endl;
            cout << "------------------------------" << endl;
        }
    }
    int small = sum[0];
    fo(k,8)
    {
        if(sum[k] < small)
        {
            small = sum[k];
        }
    }
    return small;
}

int main()
{
    vvi s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }
    }

    int result = formingMagicSquare(s);

    cout << result << "\n";

    return 0;
}
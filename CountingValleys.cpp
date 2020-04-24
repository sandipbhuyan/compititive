#include <bits/stdc++.h>

using namespace std;
#define fo(i,n) for(i=0;i<n;i++)

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int count = 0;
    int i;
    int vally = 0;
    fo(i,n)
    {
        if(s[i] == 'D')
        {
            vally++;
        }
        else
        {
            vally--;
            if(vally == 0)
            {
                count++;
            }
        }
        
    }

    return count;

}

int main()
{

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    cout << result << endl;

    return 0;
}

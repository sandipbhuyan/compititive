#include <bits/stdc++.h>
using namespace std;
bool isLeapYear(int year);

string dayOfProgrammer(int year)
{
    if (year == 1918)
    {
        cout << 26 << endl;
        return "26.09." + to_string(year);
    }

    if (isLeapYear(year))
    {
        cout << 12 << endl;
        return "12.09." + to_string(year);
    }
    else
    {
        cout << 13 << endl;
        return "13.09." + to_string(year);
    }
}

bool isLeapYear(int year)
{
    if (year < 1918)
    {
        if (year % 4 == 0)
        {
            return true;
        }
    }
    else
    {
        if (year % 400 == 0)
        {
            return true;
        }
        else if (year % 4 == 0 && year % 100 != 0)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int year;
    cin >> year;

    cout << dayOfProgrammer(year) << endl;
    return 0;
}

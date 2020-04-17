/**
 * Modifiers In C++
 * signed       int char long short
 * unsigned     int char long short
 * long         int double
 * short        int 
 * 
 * unsigned long and short can be used on int without declaring int type
 * eg: unsigned x => unsigned int x
 */
#include <iostream>
using namespace std;

int main() {
    short int i;
    short unsigned int j;
    j = 50000;
    i = j;

    cout << i << " " << j; 

    return 0;
}
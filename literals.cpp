// Constants refer to fixed values that the program may not alter and they are called literals.

#include <iostream>
using namespace std;

#define LENGTH 10
#define WIDTH 11
#define NEWLINE '\n'

int main() {
    int area;
    
    area = LENGTH * WIDTH;
    cout << area;
    cout << NEWLINE;
    return 0;
}
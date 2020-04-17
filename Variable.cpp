#include <iostream>
using namespace std;

// Will be initialized by the system by its default value
int global;

extern int a, b;
extern int c;
extern float f;

int main() {

    cout << "Global variable value before initialization: " << global << endl;

    global = 10;

    cout << "Global variable value after initialization: " << global << endl;

    int a, b;
    int c;
    float f;

    a = 10;
    b = 20;
    c = a + b;

    cout << c << endl;

    f = 50.0 / 30.0;
    cout << f << endl;

    return 0;
}
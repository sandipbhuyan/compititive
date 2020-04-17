/**
 * Storage Class
 * Storage class defies the scope visibility and life time of variables and or functions within a c++ program.
 * These specifiers precede the type that they modify.
 * There are following storage classes
 * auto     : Default storage class of all local variables 
 * register : Used to define local variables that should be stored in a register instead of RAM
 * static   : Instruct compiler to keep a local variable in existance during the life time of the program instead of creating and destroying it each timeit comes into and goes out of scope
 * extern   : Give a reference of a global variable that is visible to ALL the program files
 * mutable  : Its a secret :P
 * 
 */ 

/**
 * Lets do some operator examples
 * Bit wise shift(left and right shift)
 * Bit wise and and or opperation
 * Address of a variable
 * casting
 */
#include <iostream>
using namespace std;

int main() {
    int a = 15;
    int b = 10;
    a <<= 2;
    int c = a & b;
    cout << "a value: " << a << endl;
    cout << "c value: " << c << endl;
    b >>= 2;
    cout << "b value: " << b << endl;
    cout << "Casting: " << int(2.2) << endl;
    cout << "Address of a: " << &a << endl;
    int d = a | b;
    cout << "d: " <<d << endl;

    return 0;
}

// Write a program where the users enter a decimal number and the code
// prints out the nearest integer. You should use casting as part of
// your solution. Write a second version the easy way by using the cmath
// library.

#include <iostream>
using namespace std;

int main() {
    double input;
    cout << "Gimme a decimal number yo" << endl;
    cin >> input;
    if (input - (int) input < .5) {
        cout << (int) input << endl;
    } else {
        cout << (int) input+1 << endl;
    }
    return 0;
}

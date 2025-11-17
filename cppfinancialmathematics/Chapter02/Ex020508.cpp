// What does the following program output and why?

#include <iostream>
#include <cmath>
using namespace std;

// doesn't that mean that int is being implicitly cast as unsigned here then? 
int main() {
    int a = -1;
    unsigned int b = 0;
    if (a<b) {
        cout << "a is smaller\n";
    } else {
        cout << "a is bigger\n";
    }
    cout << "Because we're interpreting a to equal ";
    unsigned int castValue = (unsigned int) a;
    cout << castValue;
    cout << "\n";
}

// Use a while loop, a for loop and a do while loop to provide different implementations
// for the factorial function.

long whilefactorial(int);
long forfactorial(int);
long dowhilefactorial(int);

#include <iostream>
using namespace std;

int main() {
    cout << whilefactorial(5) 
        << " " << forfactorial(5) 
        << " " << dowhilefactorial(5) << endl;
    return 0;
}

long whilefactorial(int n) {
    long counter = 1;
    long factorial = 1;
    while (counter <= n) {
        factorial *= counter;
        counter++;
    }
    return factorial;
}

long forfactorial(int n) {
    long factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}

long dowhilefactorial(int n) {
    long counter = 1;
    long factorial = 1;
    do {
        factorial *= counter;
        counter++;
    } while (counter<=n);
    return factorial;   
}

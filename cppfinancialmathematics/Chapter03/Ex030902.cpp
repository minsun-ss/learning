// Write a recursive function that takes two integer parameters a and
// b and prints out all the numbers from a to b.

#include <iostream>
using namespace std;

int sumToN(int n);
int printAToB(int, int);

int main() {
    printAToB(1,10);
    cout << "\n";
    return 0;
}


int sumToN(int n) {
    if (n==1) {
        return n;
    } else {
        return n + sumToN(n-1);
    }
}

int printAToB(int a, int b) {
    if (a==b) {
        cout << a << " ";
    } else {
        printAToB(a, b-1);
        cout << b << " ";
    }
    return 0;
}

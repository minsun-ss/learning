// The nth Fibonacci number can be defined by x = xn-1 + xn-2
// if n>=2. We define x0=1 and x1=1. Write a function fibonacci that 
// evaluates the nth Fibonacci number by recursion. How many times
// is the function fibonacci called in order to compute each of x
// x3, x4, and in general, xn? 

#include <iostream>
using namespace std;

int sumToN(int);
int printAToB(int, int);
int fibonacci(int);

int main() {
    cout << "Fibonacci 1, 2, 3, 4 " <<
        fibonacci(1) << " " <<
        fibonacci(2) << " " <<
        fibonacci(3) << " " <<
        fibonacci(4) << endl;
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

int fibonacci(int a) {
    if (a==0) {
        return 0;
    } else if (a==1) {
        return 1;
    } else {
        return fibonacci(a-1)+fibonacci(a-2);
    }
}

// For each n in N define a mathematical function hn as follows
// h(x, a0) = a0
// hn(x, a0, a1...) = a0 + xhn-1(x, a1, a2...)

#include <iostream>
#include <cmath>
using namespace std;

// cursed globals
double SQUAREROOT2PI = pow(2*3.1415926, 0.5);

int sumToN(int);
int printAToB(int, int);
int fibonacci(int);
double normcdf(int);
double hornerFunction(int, int);

int main() {
    cout << "Norm 0,1, 2, 3, " <<
        normcdf(0) << " " <<
        normcdf(1) << " " <<
        normcdf(2) << " " <<
        normcdf(3) << endl;
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

double normcdf(int n) {
    double k = 1 / (1+0.2316519*n);

    double val = 1 - (1/(SQUAREROOT2PI)*std::exp(-1*n*n/2) * k * (
                0.319381530 + k * (
                    -0.356563782 + k * (
                        1.781477937 + k * (
                            -1.81255978 + 1.330274429 * k)
                        )
                    )
                ));

    if (n >= 0) {
        return val;
    } else {
        return 1 - val;
    }
}

double hornerFunction(double k, double a) {
    return a;
}

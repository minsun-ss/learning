// A commonly occuring function in financial mathematics is the cumulative
// normal function defined by
// normcdf(x) = N(x) = 1 / sqrt 2*PI sum of negative infinity to x exp(-t^2/2)dt
// if x>=0 we define
// k = 1 / (1+0.2316419)
// a good approximation for N(x) is given by
// BIG EQUATION WILL NOT REPEAT
// For x<=0 you can use the same frmula to evaluate 1-N(-x).
// Write a function called normcdf to evaluate the cumulative normal function.
// Why would N be a bad name for the function?

#include <iostream>
#include <cmath>
using namespace std;

int sumToN(int);
int printAToB(int, int);
int fibonacci(int);
double normcdf(int);


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

    double val = 1 - (1/(std::pow(2*3.141592, 0.5))*std::exp(-1*n*n/2) * k * (
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

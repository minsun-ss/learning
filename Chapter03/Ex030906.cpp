// For each n in N define a mathematical function hn as follows
// h(x, a0) = a0
// hn(x, a0, a1...) = a0 + xhn-1(x, a1, a2...)

#include <iostream>
#include <cmath>
using namespace std;

// cursed globals
double SQUAREROOT2PI = pow(2*3.1415926, 0.5);
const double root2Pi = sqrt( 2.0 * 3.141592653589793 );

int sumToN(int);
int printAToB(int, int);
int fibonacci(int);
double normcdf(int);
double hornerFunction(double, double, double);
double hornerFunction(double, double, double, double);
double hornerFunction(double, double, double, double, double);
double hornerFunction(double, double, double, double, double, double);
double hornerFunction(double, double, double, double, double, double, double);
double hornerFunction(double, double, double, double, double, double, double, double);
double hornerCDF(int);
double normcdfHorner(double);

int main() {
    cout << "Norm 0,1, 2, 3, " <<
        //hornerCDF(0) << " " <<
        normcdfHorner(1) << " " <<
        normcdfHorner(2) << " " <<
        normcdfHorner(3) << endl;
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


double hornerFunction(double k, double a0, double a1) {
    return a0 + k*a1;
}

double hornerFunction(double k, double a0, double a1, double a2) {
    return a0 + (k * hornerFunction(k, a1, a2));
}

double hornerFunction(double k, double a0, double a1, double a2, double a3) {
    return a0 + (k * hornerFunction(k, a1, a2, a3));
}

double hornerFunction(double k, double a0, double a1, double a2, double a3, double a4) {
    return a0 + (k * hornerFunction(k, a1, a2, a3, a4));
}

double hornerFunction(double k, double a0, double a1, double a2, double a3, double a4, double a5) {
    return a0 + (k * hornerFunction(k, a1, a2, a3, a4, a5));
}

double hornerFunction(double k, double a0, double a1, double a2, double a3, double a4, double a5, double a6) {
    return a0 + (k * hornerFunction(k, a1, a2, a3, a4, a5, a6));
}


double hornerCDF(int n) {
    if (n < 0) {
        return 1-hornerCDF(n*-1);
    }
    double k = 1 / (1+0.2316519*n);
    double poly = hornerFunction(k, 0.0, .319381530, -0.356563782, 1.781477937, -1.821255978, 1.330274429);
    double v = 1 - (1/(SQUAREROOT2PI)*std::exp(-1*n*n/2));
    return v * poly;
}

double normcdfHorner( double x ) {
    if (x<=0) {
        return 1-normcdf(-x);
    }
    double k = 1/(1 + 0.2316419*x);
    double poly = hornerFunction(k,
                                 0.0, 0.319381530, -0.356563782,
                                 1.781477937,-1.821255978,1.330274429);
    double approx = 1.0 - 1.0/root2Pi * exp(-0.5*x*x) * poly;
    return approx;
}

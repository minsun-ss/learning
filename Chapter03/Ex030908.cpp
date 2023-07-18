// write a function called blackScholesCallPrice, which takse five parameters
// strike price, time to maturity, spot price, volatility and risk free interest rate
// and computes the call option price. 


#include <iostream>
#include <cmath>
using namespace std;

// cursed globals
const double SQUAREROOT2PI = pow(2*3.1415926, 0.5);
const double d0 = 2.50662823884;
const double d1 = -18.61500062529;
const double d2 = 41.39119773534;
const double d3 = -25.44106049637;
const double b1 = -8.47351093090;
const double b2 = 23.08336743743;
const double b3 = -21.06224101826;
const double b4 = 3.13082909833;
const double c0 = 0.3374754822726147;
const double c1 = 0.9761690190917186;
const double c2 = 0.1607979714918209;
const double c3 = 0.0276438810333863;
const double c4 = 0.0038405729373609;
const double c5 = 0.0003951896511919;
const double c6 = 0.0000321767881768;
const double c7 = 0.0000002888167364;
const double c8 = 0.0000003960315187;

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
double hornerFunction(double, double, double, double, double, double, double, double, double);
double hornerFunction(double, double, double, double, double, double, double, double, double, double);
double hornerCDF(double);
double norminv(double);

int main() {    
    cout << norminv(0.4) << endl;
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

double hornerFunction(double k, double a0, double a1, double a2, double a3, double a4,
        double a5, double a6, double a7) {
    return a0 + (k * hornerFunction(k, a1, a2, a3, a4, a5, a6, a7));
}

double hornerFunction(double k, double a0, double a1, double a2, double a3, double a4,
        double a5, double a6, double a7, double a8) {
    return a0 + (k * hornerFunction(k, a1, a2, a3, a4, a5, a6, a7, a8));
}

double hornerCDF(double n) {
    if (n < 0) {
        return 1-hornerCDF(n*-1);
    }
    double k = 1 / (1+0.2316419*n);
    double poly = hornerFunction(k, 
            0.0, .319381530, -0.356563782, 
            1.781477937, -1.821255978, 1.330274429);
    double v = 1 - (1/(SQUAREROOT2PI)*std::exp(-.5*n*n)*poly);
    cout << k << " " << poly << " " << v << " " << endl;
    return v * poly;
}

double norminv(double x) {
    double y = x - 0.5;
    if (std::abs(y) < 0.42) {
        double r = y * y;
        return y * hornerFunction(r, d0, d1, d2, d3)
                /hornerFunction(r, 1.0, b1, b2, b3, b4);
    } else {
        double r;
        if (y < 0) {
            r = x;
        } else {
            r = 1-x;
        }

        double s = std::log(-1 * std::log(r));
        double t = hornerFunction(s, c0, c1, c2, c3, c4, c5, c6, c7, c8);
        if (x>0.5) {
            return t;
        } 
            return -1 * t;
    }

}


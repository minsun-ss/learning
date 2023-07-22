// improve the norminv function so that it takes an extra boolean
// parameter that indicates whether or not to throw an exception
// when given anainput outside the range 0 and 1. What would be 
// a good default value for this parameter?

#include <iostream>
#include <stdexcept>
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

double hornerFunction(double, double, double);
double hornerFunction(double, double, double, double);
double hornerFunction(double, double, double, double, double);
double hornerFunction(double, double, double, double, double, double);
double hornerFunction(double, double, double, double, double, double, double);
double hornerFunction(double, double, double, double, double, double, double, double);
double hornerFunction(double, double, double, double, double, double, double, double, double);
double hornerFunction(double, double, double, double, double, double, double, double, double, double);
double hornerCDF(double);
double norminv(double, bool checkRange=true);

int main() {    
    cout << norminv(.75) << endl;
    cout << norminv(1.0, false) << endl;
    return 0;
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


double norminv(double x, bool checkRange) {
    if (checkRange) {
        if ((x<0) | (x>=1)) {
            throw logic_error("Norminv ranges are between 0 and 1");
        }
    }

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



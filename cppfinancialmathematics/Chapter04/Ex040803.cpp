// We would like to compute the integral 
// exp(-t^2///t2)dt.
// By making the susbtitution t = x+1-1/s, we can see that this is equal
// to the integral from 0 to 1 1/s^2 exp(-(1+1-1/s)^2/2 ds
// Write a function that uses a for loop to compute this second integral
// using the rectangle rule.

#include <iostream>
#include <cmath>
using namespace std;

double rectanglerule(double);
double infiniteIntegral(double);

int main() {
    cout << rectanglerule(5) << endl; 
    cout << infiniteIntegral(5) << endl;
    return 0;
}

double rectanglerule(double x) {
    double a = 0;
    double b = 1;
    int n = 1000;
    double rectresult = 0;
    double h = (b-a)/n;
    for (int i=0; i<n; i++) {
        double s = (h*(i+0.5)+a);
        double t = x + 1 - 1/s;
        double f = pow(s, -2) * exp(-0.5*t*t);
        rectresult += f;
    }
    return rectresult/n;
}


double infiniteIntegral( double x ) {
    // we perform the substitution
    // x + 1 - 1/s;
    // to change the infinite integral to an integral between 0 and 1
    double a = 0;
    double b = 1;
    int N = 1000;
    double h = (b-a)/N;
    double total = 0.0;
    for (int i=0; i<N; i++) {
        double s = (i+0.5)*h + a;
        double t = x + 1 - 1/s;
        double f = pow(s,-2) * exp( - 0.5*t*t );
        total +=f;
    }
    return total/N;
}




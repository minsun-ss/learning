// Given a function f: R->R, we can approximate the integral a-b f(x)dx 
// using the rectangle rule. Given an integer n, the rectangle rule
// approximating for this integral is 1/n sum from i to n-1 a + ih + 1/2h
// where h = b-a/n. Wirte a function that computes the rectangle rule
// approximation to a-b sin(x)dx for given a, b and n.

double rectanglerule(double, double, int);
double integrateSin(double, double, int);

#include <iostream>
#include <cmath>
using namespace std;


int main() {
    cout << rectanglerule(1.0, 2.0, 5) << endl; 
    return 0;
}

double rectanglerule(double a, double b, int n) {
    double rectresult = 0;
    double h = (b-a)/n;
    for (int i=0; i<n; i++) {
        double blah = (h*(i+0.5)+a);
        cout << blah << endl;
        rectresult += sin(blah);
    }
    return rectresult/n;
}


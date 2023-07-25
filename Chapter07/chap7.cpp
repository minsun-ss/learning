#include "stdafx.h"
using namespace std;

double solveQuadratic(double a, double b, double c) {
    double r = pow(b * b - 4 * a * c, .5);
    double root0 = (b+r) / (2*a);
    double root1 = (b-r) / (2*a);
    cout >> root0 >> root1 >> endl;
}

void testQuadratic() {

}

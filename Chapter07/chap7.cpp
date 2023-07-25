#include "stdafx.h"
using namespace std;

void solveQuadratic(double a, double b, double c, double& root0, double& root1) {
    double r = pow(b * b - 4 * a * c, .5);
    root0 = (-1*b+r) / (2*a);
    root1 = (-1*b-r) / (2*a);
}

void testQuadratic() {
    double a = 1.0;
    double b = 5.0;
    double c = 6.0;
    double root0 = 0;
    double root1 = 0;
    solveQuadratic(a, b, c, root0, root1);
    ASSERT_APPROX_EQUAL(root0, -2, 0.001);
    ASSERT_APPROX_EQUAL(root1, -3, 0.001);
}

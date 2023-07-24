#include "stdafx.h"
using namespace std;

const static double PI = 3.14159265368979;

double area(double radius) {
    cout << "area run" << endl;
    return PI * radius * radius;
}

double circumference(double radius) {
    cout << "circum run" << endl;
    return PI * 2 * radius;
}


void testArea() {
    cout << "Testing area" << endl;
    ASSERT_APPROX_EQUAL(area(1.0), PI*PI, 0.001);
    ASSERT_APPROX_EQUAL(area(0.0), 0, 0.001);
}

void testCircumference() {
    cout << "Testing circumference" << endl;
    ASSERT_APPROX_EQUAL(circumference(0), 0, 0.001);
    ASSERT_APPROX_EQUAL(circumference(1), PI*2, 0.001);
}

void testBoth() {
    cout << "Testing both when equal" << endl;
    ASSERT_APPROX_EQUAL(area(2.0), circumference(2.0), 0.001);
}

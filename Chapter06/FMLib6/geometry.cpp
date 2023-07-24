#include "stdafx.h"
using namespace std;

const static double PI = 3.14159265368979;

double area(double radius) {
    DEBUG_PRINT("DEBUG area run" << radius << " " << PI);
    return PI * radius * radius;
}

double circumference(double radius) {
    DEBUG_PRINT("DEBUG circum run" << radius << " " << PI);
    return PI * 2 * radius;
}

static void testArea() {
    DEBUG_PRINT("DEBUG Testing area");
    ASSERT_APPROX_EQUAL(area(1.0), (PI), 0.001);
    ASSERT_APPROX_EQUAL(area(0.0), 0, 0.001);
}

static void testCircumference() {
    DEBUG_PRINT("DEBUG test circumference");
    ASSERT_APPROX_EQUAL(circumference(0), 0, 0.001);
    ASSERT_APPROX_EQUAL(circumference(1), PI*2, 0.001);
}

static void testBoth() {
    DEBUG_PRINT("Testing both when equal");
    ASSERT_APPROX_EQUAL(area(2.0), circumference(2.0), 0.001);
}

void testGeometryLib(){
    setDebugEnabled(true);
    TEST(testArea);
    TEST(testCircumference);
    TEST(testBoth);
    setDebugEnabled(false);
}

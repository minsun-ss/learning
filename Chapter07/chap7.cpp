#include "chap7.h"
using namespace std;

void solveQuadratic(double a, double b, double c, double& root0, double& root1) {
    double r = pow(b * b - 4 * a * c, .5);
    root0 = (-1*b+r) / (2*a);
    root1 = (-1*b-r) / (2*a);
}

vector<double> altSolveQuadratic(double a, double b, double c) {
    double r= pow(b*b -4 * a *c, .5);
    double root0 = (-1*b+r) / (2*a);
    double root1 = (-1*b-r) / (2*a);
    vector<double> roots;
    roots.push_back(root0);
    roots.push_back(root1);
    return roots;
}

double mean(vector<double>& nums) {
    /**
     * Lesson to be learned here: fucking initialize to 
     * an actual number lest you get hosed on stupid things
     */
    double sum;
    int c = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        c += 1;
    }
    return sum / c;
}

/**
 * TEST TEST TEST
 */


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

void testAltQuadratic() {
    double a = 1.0;
    double b = 5.0;
    double c = 6.0;
    vector<double> qsolution = altSolveQuadratic(a, b, c);
    ASSERT_APPROX_EQUAL(qsolution[0], -2, 0.001);
    ASSERT_APPROX_EQUAL(qsolution[1], -3, 0.001);
}

void testMean() {
    vector<double> nums;
    nums.push_back(1.0);
    nums.push_back(2.0);
    nums.push_back(3.0);
    double avg = mean(nums);
    ASSERT_APPROX_EQUAL(avg, 2.0, 0.001);
}

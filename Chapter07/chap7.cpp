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

double standardDeviation(vector<double>& nums, bool is_sample) {
    int population = nums.size();
    if (is_sample) {
        population -= 1;
    }
    
    double avg = mean(nums);
    double stddev = 0.0;
    for (int i=0; i < nums.size(); i++) {
        stddev += pow(nums[i] - avg, 2);
    }
    return pow(stddev/population, 0.5);
}

double min(vector<double>& nums) {
    double minnum = nums[0];
    for (int i=1; i < nums.size(); i++) {
        if (nums[i] < minnum) {
            minnum = nums[i];
        }
    }
    return minnum;
}

double max(vector<double>&nums) {
    double maxnum = nums[0];
    for (int i=1; i < nums.size(); i++) {
        if (nums[i] > maxnum) {
            maxnum = nums[i];
            }
    }
    return maxnum;
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

static vector<double> testVector() {
    vector<double> nums;
    nums.push_back(1.0);
    nums.push_back(2.0);
    nums.push_back(3.0);
    return nums;
}

void testMean() {
    vector<double> nums = testVector();
    double avg = mean(nums);
    ASSERT_APPROX_EQUAL(avg, 2.0, 0.001);
}

void testStandardDeviation() {
    vector<double> nums = testVector();
    double stddev_population = standardDeviation(nums, false);
    double stddev_sample = standardDeviation(nums, true);
    ASSERT_APPROX_EQUAL(stddev_population, 0.81649658092773, 0.001);
    ASSERT_APPROX_EQUAL(stddev_sample, 1.0, 0.001);
}

void testMin() {
    vector<double> nums = testVector();
    double minnum = min(nums);
    ASSERT_APPROX_EQUAL(minnum, 1.0, 0.001);
}

void testMax() {
    vector<double> nums = testVector();
    double maxnum = max(nums);
    ASSERT_APPROX_EQUAL(maxnum, 3.0, 0.001);
}

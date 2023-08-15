#include "chap11.h"
using namespace std;

Pair::Pair(double _x, double _y) {
    x = _x;
    y = _y;
}

/**
 * Ex. 11.8.1
 */
double sumDoubles(double doubles[], int length) {
    double sum = 0;
    for (int i=0; i < length; i++) {
        sum += doubles[i];
    }
    return sum;
}


/**
 * Ex. 11.8.2
 */
void reverseDoubles(double doubles[], int length) {
    double reversed[length];
    int j = 0;
    for (int i = length-1; i >= 0; i--) {
        reversed[j] = doubles[i]; 
        j++;
    }

    for (int i = 0; i < length; i ++) {
        doubles[i] = reversed[i];
    }
}
/** 
 * Ex. 11.8.3
 */
double meanDistance(std::vector<Pair>* pairs) {
    std::vector<Pair> p = *pairs;
    double sum;
    for (int i=0; i < p.size(); i++) {
        sum += sqrt(p[i].x * p[i].x + p[i].y * p[i].y);
    }
    return sum / p.size();
}

/**
 * Ex. 11.8.4
 */
void polarToCartesian(double theta, double r, double* x, double* y) {
    *x = r * cos(theta);
    *y = r * sin(theta);
}

/**
 * Ex. 11.8.5
 */
void reverseString(char* chars) {
    int length = strlen(chars)/2;
    for (int i = 0; i < length; i++) {
        char temp = chars[i];
        chars[i] = chars[strlen(chars)-i-1];
        chars[strlen(chars)-i-1] = temp;
    }
}

/**
 * Ex. 11.8.6
 */
std::string concatenate(std::string& a, std::string& b) {
    return a + b;
}


/**
 * TESTS
 */

void testSumDoubles() {
    cout << "Testing sum doubles" << endl;
    double test[] = {1, 2, 3};
    ASSERT_APPROX_EQUAL(sumDoubles(test, 3), 6, .001);
}

void testReverseDoubles() {
    cout << "Testing reversing doubles" << endl;
    double test[] = {1, 2, 3};
    reverseDoubles(test, 3);

    ASSERT(test[0] == 3);
}

void testMeanDistance() {
    Pair pair(3, 4);
    vector<Pair> pairs; 
    pairs.push_back(pair);
    Pair pair2(6, 8);
    pairs.push_back(pair2);
    double md = meanDistance(&pairs);
    ASSERT_APPROX_EQUAL(md, 7.5, .001);
}

void testPolarToCartesian() {
    double x = 0; 
    double y = 0;
    polarToCartesian(.39444, 13, &x, &y);
    ASSERT_APPROX_EQUAL(x, 12.002, .01);
    ASSERT_APPROX_EQUAL(y, 4.996, .01);
}

void testReverseString() {
    char chars[] = "hello";
    reverseString(chars);

    ASSERT(chars[0] == 'o');
    ASSERT(chars[1] == 'l');
    ASSERT(chars[2] == 'l');
    ASSERT(chars[3] == 'e');
    ASSERT(chars[4] == 'h');
}

void testConcatenate() {
    string a = "hello";
    string b = " world";
    string c = concatenate(a, b);
    ASSERT(c == "hello world");
}

void testChapter11() {
    TEST(testSumDoubles);
    TEST(testReverseDoubles);
    TEST(testMeanDistance);
    TEST(testPolarToCartesian);
    TEST(testReverseString);
    TEST(testConcatenate);
}

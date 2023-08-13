#include "chap11.h"
using namespace std;

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

void testChapter11() {
    TEST(testSumDoubles);
    TEST(testReverseDoubles);
}

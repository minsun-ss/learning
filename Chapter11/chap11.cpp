
#include "chap11.h"
#include "testing.h"
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

void testSumDoubles() {
    cout << "Testing sum doubles" << endl;
    double test[] = {1, 2, 3};
    ASSERT_APPROX_EQUAL(sumDoubles(test, 3), 6, .001);
}

void testChapter11() {
    TEST(testSumDoubles);
}

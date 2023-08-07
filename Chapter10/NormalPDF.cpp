#include "NormalPDF.h"
#include "matlib.h"
using namespace std;

const double PI = 3.14159265358979323846;  /* pi */

NormalPDF::NormalPDF() {}

double NormalPDF::normInt(double z) {
    return exp(-z*z/2) / sqrt(2*PI);
}

/**
 * TESTS
 */

void testPDF() {
    NormalPDF npdf;

    ASSERT_APPROX_EQUAL(npdf.normInt(1.96), 0.0584, 0.1);
}

void testNormalPDF() {
    TEST(testPDF);
}

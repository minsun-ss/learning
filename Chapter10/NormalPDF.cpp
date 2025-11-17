#include "NormalPDF.h"
#include "matlib.h"
using namespace std;

const double PI = 3.14159265358979323846;  /* pi */

NormalPDF::NormalPDF() {}

double NormalPDF::evaluate(double z) {
    return exp(-z*z/2) / sqrt(2*PI);
}

/**
 * TESTS
 */

void testPDF() {
    NormalPDF npdf;
    ASSERT_APPROX_EQUAL(npdf.evaluate(1.96), 0.0584, 0.1);
}

void testIntegralNormalPDF() {
    NormalPDF npdf;
    
    double actual = integral(npdf, -1.96, 1.96, 1000);
    ASSERT_APPROX_EQUAL(actual, .95, .001);
}

/**
 * Ex. 10.6.4
 */
void testNormCDF() {
    NormalPDF npdf;
    double pdfrange = integral(npdf, -1.96, 1.96, 1000);
    double normcdfrange = normcdf(1.96) - normcdf(-1.96) ;
    ASSERT_APPROX_EQUAL(pdfrange, normcdfrange, .01);
}

void testNormalPDF() {
    TEST(testPDF);
    TEST(testIntegralNormalPDF);
    TEST(testNormCDF);
}

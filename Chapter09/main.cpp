#include "matlib.h"
#include "geometry.h"
#include "textfunctions.h"
#include "CallOption.h"
#include "PutOption.h"
#include "LineChart.h"
#include "BlackScholesModel.h"
#include "Histogram.h"
#include "MonteCarloPricer.h"
#include "chap9.h"
#include "UpAndOutOption.h"

using namespace std;
 
int main() {
    // TEST(testMonteCarloPricer);
    // pathDistributionChart();
    // TEST(testBarrier);
    // TEST(testUpAndOutOption);
    testPricePaths();
}

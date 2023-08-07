#include "matlib.h"
#include "geometry.h"
#include "textfunctions.h"
#include "CallOption.h"
#include "DigitalCallOption.h"
#include "PutOption.h"
#include "DigitalPutOption.h"
#include "PieChart.h"
#include "LineChart.h"
#include "BlackScholesModel.h"
#include "Histogram.h"
#include "MonteCarloPricer.h"

using namespace std;


int main() {
    testMatlib();
    testGeometry();
    testPieChart();
    testCallOption();
    testDigitalCallOption();
    testPutOption();
    testDigitalPutOption();
    testBlackScholesModel();
    testLineChart();
    testTextFunctions();
    testHistogram();
    testMonteCarloPricer();
    return 0;
}

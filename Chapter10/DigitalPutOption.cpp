#include "DigitalPutOption.h"
#include "matlib.h"
using namespace std;

DigitalPutOption::DigitalPutOption() :
    strike(0.0), 
    maturity(0.0) {
}

double DigitalPutOption::payoff(double stockAtMaturity) const {
    if (stockAtMaturity < strike) {
        return 1.0;
    } else {
        return 0.0;
    }
}

double DigitalPutOption::price(const BlackScholesModel& bsm) const {
    double S = bsm.stockPrice;
    double K = strike;
    double sigma = bsm.volatility;
    double r = bsm.riskFreeRate;
    double T = maturity - bsm.date;

    double numerator = log(S/K) + (r+sigma*sigma*.5)*T;
    double denominator = sigma * sqrt(T);
    double d1 = numerator/denominator;
    double d2 = d1-denominator;
    return -S*normcdf(-d1) + exp(-r*T)*K*normcdf(-d2);
}

double DigitalPutOption::getMaturity() const {
    return maturity;
}

/**
 * Tests
 */

void testDigitalPutOptionPayoff() {
    DigitalPutOption dPutOption;
    dPutOption.strike = 105.0;
    dPutOption.maturity = 2.0;
    ASSERT_APPROX_EQUAL(dPutOption.payoff(101.0), 1, .001);
    ASSERT_APPROX_EQUAL(dPutOption.payoff(106.0), 0, .001);
}

void testDigitalPutOption() {
    TEST(testDigitalPutOptionPayoff);
}

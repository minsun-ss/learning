#include "DigitalCallOption.h"
#include "matlib.h"

DigitalCallOption::DigitalCallOption() : 
    strike(0.0),
    maturity(0.0) {
}

double DigitalCallOption::payoff(double stockAtMaturity) const {
    if (stockAtMaturity > strike) {
        return 1.0;
    } else {
        return 0.0;
    }
}

double DigitalCallOption::price(const BlackScholesModel& bsm) const {
    double S = bsm.stockPrice;
    double K = strike;
    double sigma = bsm.volatility;
    double r = bsm.riskFreeRate;
    double T = maturity - bsm.date;

    double numerator = log(S/K) + (r+sigma*sigma*.5)*T;
    double denominator = sigma * sqrt(T);
    double d1 = numerator/denominator;
    double d2 = d1 - denominator;
    return S*normcdf(d1) - exp(-r*T)*K*normcdf(d2);
}

double DigitalCallOption::getMaturity() const {
    return maturity;
}

/**
 * Tests
 */

static void testDigitalCallOptionPayoff() {
    DigitalCallOption dCallOption;
    dCallOption.strike = 105.0;
    dCallOption.maturity = 2.0;

    ASSERT_APPROX_EQUAL(dCallOption.payoff(106), 1.0, 0.001);
    ASSERT_APPROX_EQUAL(dCallOption.payoff(102), 0.0, 0.001);
}

void testDigitalCallOption() {
    TEST(testDigitalCallOptionPayoff);
}

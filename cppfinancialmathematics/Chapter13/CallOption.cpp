#include "CallOption.h"
 
#include "matlib.h"
 
 
 
double CallOption::payoff( double stockAtMaturity ) const {
    if (stockAtMaturity>getStrike()) {
        return stockAtMaturity-getStrike();
    } else {
        return 0.0;
    }
}
 
double CallOption::price( 
        const BlackScholesModel& bsm ) const {
    double S = bsm.stockPrice;
    double K = getStrike();
    double sigma = bsm.volatility;
    double r = bsm.riskFreeRate;
    double T = getMaturity() - bsm.date;
 
    double numerator = log( S/K ) + ( r + sigma*sigma*0.5)*T;
    double denominator = sigma * sqrt(T );
    double d1 = numerator/denominator;
    double d2 = d1 - denominator;
    return S*normcdf(d1) - exp(-r*T)*K*normcdf(d2);
}

/**
 * Tests
 */

static void testCallOptionPayoff() {
    CallOption co;
    co.setStrike(105.0);
    co.setMaturity(2.0);
    ASSERT_APPROX_EQUAL(co.payoff(110), 5.0, 0.0001);
}

static void testCallOptionPrice() {
}

void testCallOption() {
    TEST(testCallOptionPayoff);
    TEST(testCallOptionPrice);
}

#include "PutOption.h"

double PutOption::payoff(double endStockPrice) const {
    if (endStockPrice<getStrike()) {
        return getStrike()-endStockPrice;
    }
    else return 0.0;
}

double PutOption::price(const BlackScholesModel& bsm) const {
    double S = bsm.stockPrice;
    double K = getStrike();
    double sigma = bsm.volatility;
    double r = bsm.riskFreeRate;
    double T = getMaturity() - bsm.date;

    double numerator = log(S/K) + (r + sigma * sigma * 0.5)*T;
    double denominator = sigma * sqrt(T);
    double d1 = numerator/denominator;
    double d2 = d1 - denominator;
    return -S*normcdf(-d1) + exp(-r*T)*K*normcdf(-d2);
}

/**
 * Tests
 */

static void testPutOptionPayoff() {
    PutOption po;
    po.setStrike(105.0);
    po.setMaturity(2.0);
    std::vector<double> d;
    d.push_back(110.0);
    ASSERT_APPROX_EQUAL(po.payoff(110.0), 0.0, 0.001);
}

static void testPutOptionPrice() {
    PutOption po;
    po.setStrike(105.0);
    po.setMaturity(2.0);
    BlackScholesModel bsm;
    bsm.date = 1.0;
    bsm.volatility = 0.1;
    bsm.riskFreeRate = 0.05;
    bsm.stockPrice = 100.0;

    double price = po.price(bsm);
    ASSERT_APPROX_EQUAL(price, 3.925, 0.01);
}

void testPutOption() {
    TEST(testPutOptionPayoff);
    TEST(testPutOptionPrice);
}

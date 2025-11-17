#include "UpAndOutOption.h"
#include "matlib.h"

/**
 * Ex. 9.3.3
 */

UpAndOutOption::UpAndOutOption() : strike(0.0), maturity(0.0), barrier(0.0) {
}


double UpAndOutOption::computePayoff(const vector<double>& discretePrices) const {
    double finalValue = 0.0;
    for (int i=0; i < discretePrices.size(); i++) {
        if (discretePrices[i] >= barrier) {
            return 0;
        }
    }
    // if iterated, then just return the last payoff
    return payoff(discretePrices.back());
}

double UpAndOutOption::payoff(double stockAtMaturity) const {
    if (stockAtMaturity>strike) {
        return stockAtMaturity - strike;
    } else {
        return 0;
    }
}

double UpAndOutOption::price(const BlackScholesModel& bsm) const {
    double S = bsm.stockPrice;
    double K = strike;
    double sigma = bsm.volatility;
    double r = bsm.riskFreeRate;
    double T = maturity - bsm.date;

    double numerator = log(S/K) + (r+sigma*sigma*0.5)*T;
    double denominator = sigma * sqrt(T);
    double d1 = numerator/denominator;
    double d2 = d1 - denominator;
    return S*normcdf(d1) - exp(-r*T)*K*normcdf(d2);
}

/**
 * Tests
 */

void testBarrier() {
    UpAndOutOption upo = UpAndOutOption();
    upo.strike = 105.0;
    upo.maturity = 2;
    upo.barrier = 110.0;
    vector<double> dp;
    dp.push_back(101);
    dp.push_back(102);
    
    double payoff = upo.computePayoff(dp);
    ASSERT_APPROX_EQUAL(payoff, 0, 0.01);
    dp.push_back(106);
    payoff = upo.computePayoff(dp);
    ASSERT_APPROX_EQUAL(payoff, 1.0, 0.01);
    dp.push_back(111.0);
    dp.push_back(109.0);
    payoff = upo.computePayoff(dp);
    ASSERT_APPROX_EQUAL(payoff, 0.0, 0.01);
}

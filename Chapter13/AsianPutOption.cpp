#include "AsianPutOption.h"


double AsianPutOption::payoff(const std::vector<double>& stockPrices) const {
    if (avgPrice(stockPrices) < getStrike()) {
        return getStrike() - avgPrice(stockPrices);
    } else {
        return 0;
    }
}

/**
 * Tests
 */


static void testAsianPutOptionPayoff() {
    AsianPutOption apo;
    apo.setStrike(105.0);
    apo.setMaturity(2.0);
    std::vector<double> px;
    px.push_back(99.0);
    px.push_back(100.0);
    px.push_back(101.0);
    ASSERT_APPROX_EQUAL(apo.payoff(px), 5.0, .001);
}

void testAsianPutOption() {
    TEST(testAsianPutOptionPayoff);
}

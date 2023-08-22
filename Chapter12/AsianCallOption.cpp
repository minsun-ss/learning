#include "AsianCallOption.h"

double AsianCallOption::payoff(const std::vector<double>& stockPrices) const {
    if (avgPrice(stockPrices) > getStrike()) {
        return avgPrice(stockPrices) - getStrike();
    } else {
        return 0;
    }
}

/**
 * Tests
 */

static void testAsianOptionPayoff() {
    AsianCallOption aco;
    aco.setStrike(105.0);
    aco.setMaturity(2.0);
    std::vector<double> px;
    px.push_back(109.0);
    px.push_back(110.0);
    px.push_back(111.0);
    ASSERT_APPROX_EQUAL(aco.payoff(px), 5.0, .001);
}

static void testAsianOptionPrice() {
}

static void testAvg() {
    AsianCallOption aco;
    std::vector<double> px;
    px.push_back(1.0);
    px.push_back(2.0);
    px.push_back(3.0);
    ASSERT_APPROX_EQUAL(aco.avgPrice(px), 2.0, .001);
}

void testAsianCallOption() {
    TEST(testAsianOptionPayoff);
    TEST(testAvg);
}

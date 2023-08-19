#include "PutOption.h"

double PutOption::payoff(double endStockPrice) const {
    return 0;
}

/**
 * Tests
 */

static void testPayoff() {
    PutOption po;
    po.setStrike(105.0);
    po.setMaturity(2.0);
    std::vector<double> d;
    d.push_back(110.0);
    ASSERT_APPROX_EQUAL(110.0, 0.0, 0.001);
}

void testPutOption() {
    TEST(testPayoff);
}

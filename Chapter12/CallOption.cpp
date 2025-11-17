#include "CallOption.h"

double CallOption::payoff(double stockAtMaturity) const {
    if (stockAtMaturity > getStrike()) {
        return stockAtMaturity - getStrike();
    } else {
        return 0;
    }
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

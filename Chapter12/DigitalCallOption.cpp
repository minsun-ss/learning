#include "DigitalCallOption.h"

double DigitalCallOption::payoff(double stockAtMaturity) const {
    if (stockAtMaturity > getStrike()) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * Tests
 */

static void testDigitalCallOptionPayoff() {
    DigitalCallOption dco;
    dco.setStrike(105.0);
    dco.setMaturity(2.0);
    double px = 110.0;
    ASSERT_APPROX_EQUAL(dco.payoff(px), 1, .001);
    px = 100.0;
    ASSERT_APPROX_EQUAL(dco.payoff(px), 0, .001);
}

static void testDigitalCallOptionPrice() {
}

void testDigitalCallOption() {
    TEST(testDigitalCallOptionPayoff);
}

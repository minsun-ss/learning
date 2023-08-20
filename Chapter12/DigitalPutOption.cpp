#include "DigitalPutOption.h"

double DigitalPutOption::payoff(double stockAtMaturity) const {
    return 0;
}

double DigitalPutOption::price(const BlackScholesModel& bsm) const {
    return 0;
}

/**
 * Tests
 */

static void testDigitalPutOptionPayoff() {
}

static void testDigitalPutOptionPrice() {
}

void testDigitalPutOption() {
    TEST(testDigitalPutOptionPayoff);
    TEST(testDigitalPutOptionPrice);
}

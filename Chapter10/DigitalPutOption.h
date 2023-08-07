#pragma once

#include "stdafx.h"
#include "PathIndependentOption.h"
#include "BlackScholesModel.h"

/**
 * Ex. 10.6.1
 */

class DigitalPutOption: public PathIndependentOption {
public:
    DigitalPutOption();
    double strike;
    double maturity;

    double payoff (double stockAtMaturity) const;

    double price(const BlackScholesModel& bsm) const;

    double getMaturity() const;
};

void testDigitalPutOption();

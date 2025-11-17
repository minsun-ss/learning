#pragma once

#include "stdafx.h"
#include "BlackScholesModel.h"
#include "PathIndependentOption.h"

/**
 * Ex. 10.6.1
 */
class DigitalCallOption : public PathIndependentOption {
public:
    DigitalCallOption();
    double strike;
    double maturity;

    double payoff (double stockAtMaturity) const;
    
    double price(const BlackScholesModel& bsm) const;

    double getMaturity() const;
};

void testDigitalCallOption();

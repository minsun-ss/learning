#pragma once
#include "stdafx.h"
#include "BlackScholesModel.h"
using namespace std;

class UpAndOutOption {
public:
    UpAndOutOption();
    double strike;
    double maturity;
    double barrier;

    double computePayoff(const vector<double>& px) const;
    double payoff(double stockAtMaturity) const;

    double price(const BlackScholesModel& bsm) const;
};

void testBarrier();

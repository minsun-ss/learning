#pragma once
#include "stadfx.h"

class ContinuousTimeOption {
public:
    virtual ~ContinuousTimeOption() {}
    virtual double payoff(vector<double> pricePath) const = 0;
    virtual double getMaturity() const = 0;
}

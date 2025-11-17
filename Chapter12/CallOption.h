#include "stdafx.h"
#include "BlackScholesModel.h"
#include "PathIndependentOption.h"

class CallOption: public PathIndependentOption {
public:
    double payoff(double stockAtMaturity) const;
    double price(const BlackScholesModel& bsm) const;

    bool isPathDependent() const {
        return false;
    }
};

void testCallOption();

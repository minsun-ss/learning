#include "stdafx.h"
#include "BlackScholesModel.h"
#include "PathIndependentOption.h"

class PutOption: public PathIndependentOption {
public:
    double payoff(
            const std::vector<double>& stockPrices) const;

    double price(
            const BlackScholesModel& bsm) const;
    
    bool isPathDependent() const {
        return false;
    }
};

void testPutOption();

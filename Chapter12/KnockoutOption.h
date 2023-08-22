#include "stdafx.h"
#include "ContinuousTimeOptionBase.h"

class KnockoutOption: public ContinuousTimeOptionBase {
public:
    virtual ~KnockoutOption() {}
    virtual double payoff(const std::vector<double>& stockPrices) const = 0;

    bool isPathDependent() const {
        return true;
    }
};

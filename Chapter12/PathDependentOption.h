#include "stdafx.h"
#include "ContinuousTimeOptionBase.h"

class PathDependentOption: public ContinuousTimeOptionBase {
public:
    virtual ~PathDependentOption() {}
    virtual double payoff(const std::vector<double>& stockPrices) const = 0;

    bool isPathDependent() const {
        return true;
    }
};

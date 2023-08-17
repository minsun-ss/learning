#pragma once

#include "ContinuousTimeOption.h"
#include "BlackScholesModel.h"
#include "MonteCarloPricer.h"

class ContinuousTimeOptionBase: public ContinuousTimeOption {
public:
    virtual ~ContinuousTimeOptionBase() {}
    double getMaturity() const {
        return maturity;
    }
    void setMaturity(double maturity) {
        this->maturity = maturity;
    }
    double getStrike() const {
        return strike;
    }
    void setStrike(double strike) {
        this->strike = strike;
    }
    double price(const BlackScholesModel& model) const;
private:
    double maturity;
    double strike;
};

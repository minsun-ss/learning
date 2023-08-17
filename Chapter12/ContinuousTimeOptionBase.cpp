#include "ContinuousTimeOptionBase.h"

double ContinuousTimeOptionBase::price(
        const BlackScholesModel& model) const {
    MonteCarloPricer pricer;
    return pricer.price(*this, model);
}

#pragma once
#include "BlackScholesModel.h"

class Priceable {
public:
    virtual double price(const BlackScholesModel& model) const = 0;        
};

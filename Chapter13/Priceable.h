#include "stdafx.h"
#include "BlackScholesModel.h"

class Priceable {
public:
    virtual double price(const BlackScholesModel& model) const = 0;        
};

#include "stdafx.h"
#include "Priceable.h"

class Portfolio: public Priceable {
public:
    virtual ~Portfolio() {} ;
    virtual int size() const = 0;
    virtual int add(double quantity, std::shared_ptr<Priceable> security) = 0;
};

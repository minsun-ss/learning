#include "chap8.h"

/* 
 * Ex. 8.6.1
 */
class BlackScholesModel {
public:
    double stockPrice;
    double volatility;
    double riskFreeRate;
    double date;
};

class PutOption {
public:
    double strike;
    double maturity;
    double payoff(double stockAtMaturity) const;
    double price (const BlackScholesModel& bsm) const;
};

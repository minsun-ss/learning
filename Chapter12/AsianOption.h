#include "stdafx.h"
#include "KnockoutOption.h"

/**
 * Asian option with maturity T and strike K. Payoff is determined by
 * max avg(S) - K where avg(S) is the average stock price from time 0 up to 
 * maturity. 
 */

class AsianOption: public KnockoutOption {
public:
    double payoff(const std::vector<double> stockPrices) const;
};

void testAsianOption();

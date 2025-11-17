#pragma once
#include "stdafx.h"
#include "KnockoutOption.h"

class AsianPutOption: public KnockoutOption {
public:
    double payoff(const std::vector<double>& stockPrices) const;
    double avgPrice(const std::vector<double>& stockPrices) const {
        double s = 0;
        for (int i = 0; i < stockPrices.size(); i++) {
            s += stockPrices[i];
        }
        return s/stockPrices.size();
    }
};

void testAsianPutOption();

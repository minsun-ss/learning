
#include "matlib.h"
using namespace std;

/*
 * Ex. 8.6.3
 */
class CartesianPoint {
public:
    double x;
    double y;
    double distanceTo(CartesianPoint& p);
};

double CartesianPoint::distanceTo(CartesianPoint& p) {
    double x_dist = p.x - x;
    double y_dist = p.y - y;
    return sqrt((x_dist * x_dist) + (y_dist * y_dist));
}

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

double PutOption::payoff(double stockAtMaturity) const {
    if (stockAtMaturity<strike) {
        return strike-stockAtMaturity;
    } else {
        return 0.0;
    }
}

double PutOption::price(const BlackScholesModel& bsm) const {
    double S = bsm.stockPrice;
    double K = strike;
    double sigma = bsm.volatility;
    double r = bsm.riskFreeRate;
    double T = maturity - bsm.date;

    double numerator = log(S/K) + (r + sigma * sigma * 0.5)*T;
    double denominator = sigma * sqrt(T);
    double d1 = numerator/denominator;
    double d2 = d1 - denominator;
    return K*normcdf(-d2)*exp(-r*T) - normcdf(-d1)*S;
}

/** 
 * Test functions
 */

void testDistanceTo() {
    CartesianPoint p1;
    p1.x = 1;
    p1.y = 1;
    CartesianPoint p2;
    p2.x = 4;
    p2.y = 5;
    double d= p1.distanceTo(p2);
    ASSERT_APPROX_EQUAL(d, 5.0, 0.0001);
}

void testPutOptionPrice() {
    PutOption putOption;
    putOption.strike = 105.0;
    putOption.maturity = 2.0;

    BlackScholesModel bsm;
    bsm.date = 1.0;
    bsm.volatility = 0.1;
    bsm.riskFreeRate = 0.05;
    bsm.stockPrice = 100.0;

    double price = putOption.price(bsm);
    ASSERT_APPROX_EQUAL(price, 3.92252, 0.01);
}

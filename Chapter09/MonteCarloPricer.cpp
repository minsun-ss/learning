#include "MonteCarloPricer.h"
#include "matlib.h"
 
using namespace std;
 
MonteCarloPricer::MonteCarloPricer() :
    nScenarios(10000) {
}

double MonteCarloPricer::price(
        const CallOption& callOption,
        const BlackScholesModel& model ) {
    double total = 0.0;
    vector<double> payoffs;
    for (int i=0; i<nScenarios; i++) {
        vector<double> path= model.generateRiskNeutralPricePath(callOption.maturity,1);
        double stockPrice = path.back();
        double payoff=callOption.payoff(stockPrice);
        payoffs.push_back(payoff);
        total+= (double) payoff;
    }
    double mean = total/nScenarios;
    // calculate the standard dev 
    double s = standardDeviation(payoffs, true);
    cout << s << endl;
    double optionstd = s * pow(nScenarios, -1.2);
    cout << optionstd << endl;
    double r = model.riskFreeRate;
    double T = callOption.maturity - model.date;
    return exp(-r*T)*mean;
}

/**
 * Ex. 9.3.7
 */
double MonteCarloPricer::priceRV(const CallOption& callOption, const BlackScholesModel& model) {
    double total = 0.0;
    for (int i =0; i < nScenarios; i++) {
        vector<double> path = model.generateRiskNeutralPricePath(callOption.maturity,1);
        double stockPrice = path.back();
        double payoff = callOption.payoff(stockPrice);
        total += (double) payoff;

        vector<double> path2 = model.generateRiskNeutralPricePathReducedVariance(callOption.maturity,1);
        stockPrice = path.back();
        payoff = callOption.payoff(stockPrice);
        total += (double) payoff;
    }
    double mean = total/nScenarios/2;
    double r = model.riskFreeRate;
    double T = callOption.maturity - model.date;
    return exp(-r*T)*mean;
}

/**
 * Ex. 9.3.6
 */
double MonteCarloPricer::std95(const CallOption& callOption, BlackScholesModel& model) {
    vector<double> payoffs;
    for (int i = 0; i < nScenarios; i++) {
        vector<double> path = model.generateRiskNeutralPricePath(callOption.maturity,1);
        double stockPrice = path.back();
        double payoff = callOption.payoff(stockPrice);
        payoffs.push_back(payoff);
    }
    double s = standardDeviation(payoffs, true);
    double optionstd = s * pow(nScenarios, -1.2);
    return optionstd * 1.96;
}

/**
 * Ex. 9.3.1.
 */
double MonteCarloPricer::price(const PutOption& putOption, const BlackScholesModel& model) {
    double total = 0.0;
    for (int i = 0; i < nScenarios; i++) {
        vector<double> path = model.generateRiskNeutralPricePath(putOption.maturity, 1);
        double stockPrice = path.back();
        double payoff = putOption.payoff(stockPrice);
        total += payoff;
    }
    double mean = total/nScenarios;
    double r = model.riskFreeRate;
    double T = putOption.maturity - model.date;
    return exp(-r*T)*mean;
}

/**
 * Ex. 9.3.3
 */
double MonteCarloPricer::price(const UpAndOutOption& upoOption, 
        const BlackScholesModel& model, int nSteps) {
    double total = 0.0;
    for (int i=0; i < nScenarios; i++) {
        vector<double> path = model.generateRiskNeutralPricePath(upoOption.maturity, nSteps);
        double payoff = upoOption.computePayoff(path);
        total += payoff;
    }
    double mean = total/nScenarios;
    double r = model.riskFreeRate;
    double T = upoOption.maturity - model.date;
    return exp(-r*T)*mean;
}


//////////////////////////////////////
//
//   Tests
//
//////////////////////////////////////
 
static void testPriceCallOption() {
    rng("default");
 
    CallOption c;
    c.strike = 110;
    c.maturity = 2;
 
    BlackScholesModel m;
    m.volatility = 0.1;
    m.riskFreeRate = 0.05;
    m.stockPrice = 100.0;
    m.drift = 0.1;
    m.date = 1;
 
    MonteCarloPricer pricer;
    double price = pricer.price( c, m );
    double expected = c.price( m );
    ASSERT_APPROX_EQUAL( price, expected, 0.1 );
}

void testPriceCallOptionRV() {
    rng("default");
    CallOption c;
    c.strike = 110;
    c.maturity = 2;

    BlackScholesModel m;
    m.volatility = 0.1;
    m.riskFreeRate = 0.05;
    m.stockPrice = 100.0;
    m.drift = 0.1;
    m.date = 1;

    MonteCarloPricer pricer;
    double price = pricer.price(c, m);
    double price2 = pricer.priceRV(c, m);
    double expected = c.price(m);

    cout << price << " " << price2 << endl;
}

static void testPricePutOption() {
    rng("default");

    PutOption p;
    p.strike = 110;
    p.maturity = 2;

    BlackScholesModel m;
    m.volatility = 0.1;
    m.riskFreeRate = 0.05;
    m.stockPrice = 100.0;
    m.drift = 0.1;
    m.date = 1;

    MonteCarloPricer pricer;
    double price = pricer.price(p, m);
    double expected = p.price(m);
    ASSERT_APPROX_EQUAL(price, expected, 0.1);
}

void testUpAndOutOption() {
    rng("default");

    UpAndOutOption uo;
    uo.strike = 110;
    uo.maturity = 2;
    uo.barrier = 120;
    BlackScholesModel m;
    m.volatility = 0.1;
    m.riskFreeRate = 0.05;
    m.stockPrice = 100.0;
    m.drift = 0.1;
    m.date = 1;

    MonteCarloPricer pricer;
    double price = pricer.price(uo, m, 20);
    double expected = uo.price(m);

    // functionally a knock out should have a lower expected value
    // to that of a call option, albeit that approaching that of the 
    // call option value as the barrier becomes more difficult to reach
    // expected is priced like a call option; a barrier option
    // should be less than expected however given the knock out
    ASSERT(price < expected);
    cout << price << " " << expected << endl;

    // I believe the higher the barrier, the px should rise closer
    // to the expected value until they equate each other
    uo.barrier = 130;
    double price2 = pricer.price(uo, m, 20);
    ASSERT(price<price2);
    cout << price << " " << price2 << " " << expected << endl;
}

void testCLT() {
    rng("default");

    CallOption c;
    c.strike = 110;
    c.maturity = 2;
 
    BlackScholesModel m;
    m.volatility = 0.1;
    m.riskFreeRate = 0.05;
    m.stockPrice = 100.0;
    m.drift = 0.1;
    m.date = 1;
 
    MonteCarloPricer pricer;
    double std95 = pricer.std95( c, m );
    ASSERT_APPROX_EQUAL(std95, 0.0001, .001);
}


void testMonteCarloPricer() {
    // testPriceCallOption();
    // testPricePutOption();
    testCLT();
}

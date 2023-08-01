#include "chap9.h"
#include "MonteCarloPricer.h"
#include "matlib.h"
#include "Histogram.h"
using namespace std;

/**
 * Ex. 9.3.2
 */
void pathDistributionChart() {
    rng("default");

    BlackScholesModel m;
    m.volatility = 0.1;
    m.riskFreeRate = 0.05;
    m.stockPrice = 100.0;
    m.drift = 0.1;
    m.date = 1;

    vector<double> finalPrices;
    for (int i = 0; i < 30000; i++) {
        vector<double> val = m.generateRiskNeutralPricePath(2, 1);
        finalPrices.push_back(val.back());
    }

    
    // now let's just dump this to chart
    Histogram hist = Histogram();
    hist.setData(finalPrices);
    hist.setNumBuckets(20);
    hist.writeAsHTML("test932.html");
}

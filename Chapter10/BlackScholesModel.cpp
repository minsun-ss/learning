#include "BlackScholesModel.h"
#include "LineChart.h"
#include "matlib.h"
using namespace std;
 
 
BlackScholesModel::BlackScholesModel() :
    drift(0.0),
    stockPrice(0.0),
    volatility(0.0),
    riskFreeRate(0.0),
    date(0.0) {
}
 
/**
 *  Creates a price path according to the model parameters
 */
vector<double> BlackScholesModel::
    generateRiskNeutralPricePath(
        double toDate,
        int nSteps ) const {
    return generatePricePath(
        toDate, nSteps, riskFreeRate );
}

vector<vector<double>> BlackScholesModel::generateRiskNeutralPricePaths(int nPaths, double toDate, 
        int nSteps) {
    vector<vector<double>> pricePaths;
    for (int i=0; i < nPaths; i++) {
        vector<double> v = generateRiskNeutralPricePath(toDate, nSteps);
        pricePaths.push_back(v);
    }
    return pricePaths;
}

/**
 *  Creates a price path according to the model parameters
 */
vector<double> BlackScholesModel::generatePricePath(
        double toDate,
        int nSteps ) const {
    return generatePricePath(toDate, nSteps, drift );
}


 
/**
 *  Creates a price path according to the model parameters
 */
vector<double> BlackScholesModel::generatePricePath(
        double toDate,
        int nSteps,
        double drift ) const {
    vector<double> path(nSteps,0.0);
    vector<double> epsilon = randn( nSteps );
    double dt = (toDate-date)/nSteps;
    double a = (drift-volatility*volatility*0.5)*dt;
    double b = volatility*sqrt(dt);
    double currentLogS = log( stockPrice );
    for (int i=0; i<nSteps; i++) {
        double dLogS = a + b*epsilon[i];
        double logS = currentLogS + dLogS;
        path[i] = exp( logS );
        currentLogS = logS;
    }
    return path;
}

/**
 * Ex. 9.3.7
 */
vector<double> BlackScholesModel::generatePricePathReducedVariance(
        double toDate, int nSteps, double drift) const {
    vector<double> path(nSteps,0.0);
    return path;
}


////////////////////////////////
//
//   TESTS
//
////////////////////////////////
 
void testRiskNeutralPricePath() {
    rng("default");
 
    BlackScholesModel bsm;
    bsm.riskFreeRate = 0.05;
    bsm.volatility = 0.1;
    bsm.stockPrice = 100.0;
    bsm.date = 2.0;
 
    int nPaths = 10000;
    int nsteps = 5;
    double maturity = 4.0;
    vector<double> finalPrices(nPaths,0.0);
    for (int i=0; i<nPaths; i++) {
        vector<double> path =
            bsm.generateRiskNeutralPricePath(
                maturity, nsteps );
        finalPrices[i] = path.back();
    }
    ASSERT_APPROX_EQUAL( mean( finalPrices ),
        exp( bsm.riskFreeRate*2.0)*bsm.stockPrice,
             0.5);
}
void testVisually() {
    BlackScholesModel bsm;
    bsm.riskFreeRate = 0.05;
    bsm.volatility = 0.1;
    bsm.stockPrice = 100.0;
    bsm.date = 2.0;
 
    int nSteps = 1000;
    double maturity = 4.0;
 
    vector<double> path =
        bsm.generatePricePath( maturity, nSteps );
    double dt = (maturity-bsm.date)/nSteps;
    vector<double> times =
        linspace(dt,maturity,nSteps);
    LineChart lineChart;
    lineChart.setTitle("Stock price path");
    lineChart.setSeries(times, path);
    lineChart.writeAsHTML("examplePricePath.html");
}
 
void testBlackScholesModel() {
    TEST( testRiskNeutralPricePath );
    TEST( testVisually );
    TEST( testPricePaths );
}

void testPricePaths() {
    cout << "testing pricepaths" << endl;
    BlackScholesModel bsm;
    bsm.riskFreeRate = 0.05;
    bsm.volatility = 0.1;
    bsm.stockPrice = 100.0;
    bsm.date = 2.0;
    int nSteps = 2;
    double maturity = 4.0;

    vector<vector<double>> pp = bsm.generateRiskNeutralPricePaths(10, maturity, nSteps);

    ASSERT(pp.size() == 10);
    ASSERT(pp[0].size() == 2);
}

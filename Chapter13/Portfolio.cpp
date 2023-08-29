#include "Portfolio.h"
#include "CallOption.h"
#include "PutOption.h"

using namespace std;


class PortfolioImpl: public Portfolio {
public:
    int size() const;
    int add(double quantity, shared_ptr<Priceable> security);
    void setQuantity(int index, double quantity);
    double price(const BlackScholesModel& model) const;

    vector<double> quantities;
    vector< shared_ptr<Priceable> > securities;
};

int PortfolioImpl::size() const {
    return quantities.size();
}

int PortfolioImpl::add(double quantity, shared_ptr<Priceable> security) {
    quantities.push_back(quantity);
    securities.push_back(security);
    return quantities.size();
}

void PortfolioImpl::setQuantity(int index, double quantity) {
    quantities[index] = quantity;
}

double PortfolioImpl::price(const BlackScholesModel& model) const {
    double ret = 0.0;
    int n = size();
    for (int i=0; i<n; i++) {
        ret += quantities[i] * securities[i] -> price(model);
    }
    return ret;
}

shared_ptr<Portfolio> Portfolio::newInstance() {
    shared_ptr<Portfolio> ret = make_shared<PortfolioImpl>();
    return ret;
}

/** 
 * Tests
 */

static void testPutCallParity() {
    shared_ptr<Portfolio> portfolio = Portfolio::newInstance();
    shared_ptr<CallOption> c = make_shared<CallOption>();
    c->setStrike(110);
    c->setMaturity(1.0);

    shared_ptr<PutOption> p = make_shared<PutOption>();
    p->setStrike(110);
    p->setMaturity(1.0);

    portfolio->add(100,c);
    /** portfolio->add(-100,p);

    BlackScholesModel bsm;
    bsm.volatility = 0.1;
    bsm.stockPrice = 100;
    bsm.riskFreeRate = 0;

    double expected = bsm.stockPrice - c->getStrike();
    double portfolioPrice = portfolio->price(bsm);

    ASSERT_APPROX_EQUAL(100*expected, portfolioPrice, 0.0001);
    */
}

void testPortfolio() {
    testPutCallParity();
}

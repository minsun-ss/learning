#include "Portfolio.h"
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
    return 0;
}

void PortfolioImpl::setQuantity(int index, double quantity) {
}

double PortfolioImpl::price(const BlackScholesModel& model) const {
    return 0.0;
}

shared_ptr<Portfolio> Portfolio::newInstance() {
    shared_ptr<Portfolio> ret = make_shared<PortfolioImpl>();
    return ret;
}

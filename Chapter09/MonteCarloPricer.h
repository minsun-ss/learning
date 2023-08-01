#pragma once
 
#include "stdafx.h"
#include "CallOption.h"
#include "PutOption.h"
#include "UpAndOutOption.h"
#include "BlackScholesModel.h"
 
class MonteCarloPricer {
public:
    /*  Constructor */
    MonteCarloPricer();
    /*  Number of scenarios */
    int nScenarios;
    /*  Price a call option */
    double price( const CallOption& option,
                  const BlackScholesModel& model );
    double price(const PutOption& option, 
            const BlackScholesModel& model);
    double price(const UpAndOutOption& option, 
            const BlackScholesModel& model, int nSteps);
};

void testUpAndOutOption();
void testMonteCarloPricer();

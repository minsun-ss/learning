#pragma once

#include "stdafx.h"
#include "RealFunction.h"

/**
 * Ex. 10.6.2.
 * Write a class NormalPDF and compute its integral from -1.96 to 1.96
 */

class NormalPDF: public RealFunction {
public:
    NormalPDF();
    double evaluate(double z);
    
};

void testNormalPDF();

#pragma once

#include "stdafx.h"

/**
 * Ex. 10.6.2.
 * Write a class NormalPDF and compute its integral from -1.96 to 1.96
 */

class NormalPDF {
public:
    NormalPDF();
    double normInt(double z);
    
};

void testNormalPDF();

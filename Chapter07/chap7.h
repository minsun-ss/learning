#pragma once

#include "stdafx.h"
using namespace std;

void solveQuadratic(double, double, double, double&, double&);
vector<double> altSolveQuadratic(double, double, double);
double mean(vector<double>&);
double standardDeviation(vector<double>&, bool = true);

void testQuadratic();
void testAltQuadratic();
void testMean();
void testStandardDeviation();

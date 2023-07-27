#pragma once

#include "stdafx.h"
using namespace std;

void solveQuadratic(double, double, double, double&, double&);
vector<double> altSolveQuadratic(double, double, double);
double mean(vector<double>&);
double standardDeviation(vector<double>&, bool = true);
double min(vector<double>&);
double max(vector<double>&);

void testQuadratic();
void testAltQuadratic();
void testMean();
void testStandardDeviation();
void testMin();
void testMax();

#pragma once

#include "stdafx.h"
using namespace std;

void solveQuadratic(double, double, double, double&, double&);
vector<double> altSolveQuadratic(double, double, double);
double mean(vector<double>&);
double standardDeviation(vector<double>&, bool = true);
double min(vector<double>&);
double max(vector<double>&);
vector<double> randUniform(int);
vector<double> randint(int);
void randBoxMuller(int, vector<double>&, vector<double>&);
double prctile(const vector<double>&, double);

void testQuadratic();
void testAltQuadratic();
void testMean();
void testStandardDeviation();
void testMin();
void testMax();
void testRanduniform();
void testNormal();
void testBoxMuller();
void testPrctile();

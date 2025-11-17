#pragma once
 
#include "stdafx.h"
 
const double PI = 3.14159265358979;
 
/**
 *  Computes the cumulative
 *  distribution function of the
 *  normal distribution
 */
double normcdf( double x );
 
/**
 *  Computes the inverse of normcdf
 */
double norminv( double x ); 

double blackScholesCallPut(double strike, double ttm, double spot, double vol, double r);

/**
 *  Test function
 */
void testMatlib();

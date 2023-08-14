#include <iostream>
#include "stdafx.h"

class Pair {
public:
    double x;
    double y;
    Pair();
    Pair(double _x, double _y);
};

double sumDoubles(double doubles[], int length);
void reverseDoubles(double doubles[], int length);
double meanDistance(std::vector<Pair>* pairs);
void polarToCartesian(double theta, double r, double* x, double* y);

void testChapter11();

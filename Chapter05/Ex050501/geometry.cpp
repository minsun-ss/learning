#include "stdafx.h"
using namespace std;

const static double PI = 3.14159265368979;

double area(double radius) {
    cout << "area run" << endl;
    return PI * radius * radius;
}

double circumference(double radius) {
    cout << "circum run" << endl;
    return PI * 2 * radius;
}

/**
 * Ex 5.5.1
 * These functions should not be marked as static,
 * as they are not hidden in the header file.
 */

/**
 * Ex 5.5.2
 * The header file gives a better view of our
 * matlib functions, as items to be accessed 
 * internally.
 */

/**
 * Ex 5.5.3.
 * If you mark normcdf as static in header file,
 * what are the consequences? Doesn't that mean
 * that you can't access it externally? Edit:
 * yeah you can't as it turns out. If you don't
 * mark hornerFunction as static you should be 
 * able to reach into it and use the function.
 * So.... isn't static in some sense a private
 * function? 
 */

/**
 * Which file do you think should contain the 
 * definition for PI?
 * geometry.cpp, if there is only one file.
 * Think if you put it in .h you end up with
 * a circular reference; that is, geometry.cpp
 * needs it from geometry.h and geometry.h needs
 * it from geometry.cpp
 * In the case of many files reaching for it, 
 * wouldn't it make more sense to reference a
 * master constant file list instead....
 */



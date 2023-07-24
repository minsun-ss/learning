#include "matlib.h"
#include "geometry.h"

using namespace std;
/*
 * In order to test this and have the
 * stupid DEBUG MODE work
 * g++ -D _DEBUG *.cpp -o output
 * is the correct command as you need to
 * set the flags for this correctly.
 * I have no idea what the enabled yes/no
 * thing does as it's done in the linking/
 * compiling phase...
 */
int main() {
    testGeometryLib();
}

/** 
 * Ex 6.6.3
 * Unit test function testNormcdf is marked as static
 * void. Why? Cos it's hidden and returns nothing.
 * Test function testMatlib is marked as void
 * but not static. Why not. Void cos it returns
 * nothing but not static because it's being run in main.
 */



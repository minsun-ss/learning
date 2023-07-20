// Given a function f: R->R, we can approximate the integral a-b f(x)dx 
// using the rectangle rule. Given an integer n, the rectangle rule
// approximating for this integral is 1/n sum from i to n-1 a + ih + 1/2h
// where h = b-a/n. Wirte a function that computes the rectangle rule
// approximation to a-b sin(x)dx for given a, b and n.

double rectanglerule(int, int, int);

#include <iostream>
using namespace std;

int main() {
    cout << rectanglerule(1, 2, 5) << endl;
    return 0;
}

int rectanglerule(int a, int b, int n) {

}
    

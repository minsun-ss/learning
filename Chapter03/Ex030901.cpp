// Write a recursive function to compute the sum of numbers between 1 and n.

#include <iostream>
using namespace std;

int sumToN(int n) {
    if (n==1) {
        return n;
    } else {
        return n + sumToN(n-1);
    }
}

int main() {
    cout << "Sum to N 1, then 2 then 3 "
        << sumToN(1) << " " 
        << sumToN(2) << " " << sumToN(3) << endl;
    return 0;
}

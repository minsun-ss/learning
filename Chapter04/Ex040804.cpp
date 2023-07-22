// Use the looping method of your choice to compute the nth fibonacci 
// number. Explain why this is more efficient than the method using 
// recursion in Exercise 3.9.3.


#include <iostream>
using namespace std;

int fibonacci(int n);

int main() {
    cout << fibonacci(1) << " " <<
        fibonacci(2) << " " <<
        fibonacci(3) << " " <<
        fibonacci(4) << " " <<
        fibonacci(5) << endl;
}

int fibonacci(int n) {
    if (n==1) {
        return 1;
    } else {
        int result;
        int x0 = 0;
        int x1 = 1;
        for (int i=1; i<n; i++) {
            result = x0 + x1;
            x0 = x1;
            x1 = result;
        }
        return result;
    }
}

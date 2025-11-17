// Write down, or compute, the values of 
// true || false
// (true && false) || true
// true && (false || true)
// true && false && true
// 3*5==15 && (7*8==21 || true!=false)

#include <iostream>

int main() {
    // think this is 1
    bool check1 = true || false;
    std::cout << check1 << std::endl;
    
    // think this is 1
    bool check2 = (true && false) || true;
    std::cout << check2 << std::endl;

    // think this is 1
    bool check3 = true && (false || true);
    std::cout << check3 << std::endl;

    // think this is 1
    bool check4 = true && false || true;
    std::cout << check4 << std::endl;

    // think this is also 1
    bool check5 = 3*5==15 && (7*8==21 || true!=false);
    std::cout << check5 << std::endl;
    return 0; 
}

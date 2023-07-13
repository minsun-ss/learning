// write a function to compute the kinetic energy of a body
// given mass and velocity using the formula E = 1/2mv^2

#include <iostream>

double kineticEnergy(double mass, double velocity) {
    return .5 * mass * velocity* velocity;
}

int main() {
    std::cout << "mass 10, velocity 1 " << kineticEnergy(10.0, 1.0) << std::endl;
    return 0;
}

#pragma once

#include "Star.h"
#include<vector>

namespace nbody{

class Universe{
private:
    std::vector<Star> stars;
    const double G = 1.0;    // Simplified gravitational constant for testing

public:
    Universe() = default;
    ~Universe() = default;

    // Add a star with initial position, velocity, and mass
    void add_star(double x, double y, double z, double vx, double vy, double vz, double mass);

    // Perform one simulation step of the core physics
    void step(double dt);

    // Safely expose positions for external rendering
    std::vector<std::vector<double>> get_positions() const;
};
}
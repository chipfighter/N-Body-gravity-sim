#include "../include/nbody/Universe.h"
#include <cmath> 

namespace nbody {

void Universe::add_star(double x, double y, double z, double vx, double vy, double vz, double mass){
    stars.push_back({x, y, z, vx, vy, vz, mass});
}

void Universe::step(double dt){
    int n = stars.size();

    // Arrays for store the accumulated force for each star in this step
    std::vector<double> fx(n, 0.0);
    std::vector<double> fy(n, 0.0);
    std::vector<double> fz(n, 0.0);

    // 1. Calculate Gravity
    for(int i = 0; i < n; ++i){
        for(int j = i + 1 ; j < n; ++j){
            double dx = stars[j].x - stars[i].x;
            double dy = stars[j].y - stars[i].y;
            double dz = stars[j].z - stars[i].z;

            // Calculate the distance 
            // Note: 1e-9 is a softening factor to prevent infinite gravity when stars are too close
            double dist_sq = dx*dx + dy*dy + dz*dz + 1e-9;
            double dist = std::sqrt(dist_sq);
            
            // F = G * (m1 * m2) / r^2
            double F = (G * stars[i].mass * stars[j].mass) / dist_sq;
            
            // Decompose the scalar force into 3D vector components
            double fx_ij = F * (dx / dist);
            double fy_ij = F * (dy / dist);
            double fz_ij = F * (dz / dist);

            // Apply Newton's Third Law
            fx[i] += fx_ij; fy[i] += fy_ij; fz[i] += fz_ij;
            fx[j] -= fx_ij; fy[j] -= fy_ij; fz[j] -= fz_ij;
        }
    }

            // 2 & 3. Calculate Acceleration and Apply Numerical Integration (Semi-implicit Euler)
            for (int i = 0; i < n; ++i) {
            // a = F / m. Update velocity first
                stars[i].vx += (fx[i] / stars[i].mass) * dt;
                stars[i].vy += (fy[i] / stars[i].mass) * dt;
                stars[i].vz += (fz[i] / stars[i].mass) * dt;

            // Update position using the NEW velocity
            stars[i].x += stars[i].vx * dt;
            stars[i].y += stars[i].vy * dt;
            stars[i].z += stars[i].vz * dt;
            }
}

std::vector<std::vector<double>> Universe::get_positions() const{
    std::vector<std::vector<double>> positions;
    positions.reserve(stars.size());
    for (const auto& star : stars){
        positions.push_back({star.x, star.y, star.z});
    }
    return positions;
}


} // namespace nbody
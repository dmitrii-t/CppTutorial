#pragma once

#include <cassert>
#include <cmath>

// Define PI
#define PI 3.1415927

// Declare abstract class VehicleModel
class VehicleModel {
public:
  // Declare virtual function Move()
  virtual void Move(double, double) = 0;
};

// Derive class BicycleModel from VehicleModel
class BicycleModel : public VehicleModel {
public:
  // Override the Move() function
  void Move(double v, double phi) override {
    theta += v / L * std::tan(phi);
    x += v * std::cos(theta);
    y += v * std::sin(theta);
  }

  // Define x, y, and theta
  double x{.0};
  double y{.0};
  double theta{.0};

  // Define L
  // Initialize to 1.0 as it is a divider
  double L{1.0};
};

// Derive class ParticleModel from VehicleModel
class ParticleModel : public VehicleModel {
public:
  // Override the Move() function
  void Move(double v, double phi) override {
    theta += phi;
    x += v * std::cos(theta);
    y += v * std::sin(theta);
  }

  // Define x, y, and theta
  double x{.0};
  double y{.0};
  double theta{.0};
};

inline void TestVehicleModelMoves() {
  ParticleModel particle;
  BicycleModel bicycle;

  particle.Move(10, PI / 9);
  bicycle.Move(10, PI / 9);

  assert(particle.x != bicycle.x);
  assert(particle.y != bicycle.y);
  assert(particle.theta != bicycle.theta);
}

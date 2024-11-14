#pragma once

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

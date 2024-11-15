#include <iostream>
#include <string>

using namespace std;

class Car {
public:
  int GetHorsepower() const;
  void SetHorsepower(int value);

  int GetWeight() const;
  void SetWeight(int value);

  string GetBrand() const;
  void SetBrand(string value);

private:
  int horsepower{0};
  int weight{0};
  char brand[255]{};
};

int Car::GetHorsepower() const { return horsepower; }
void Car::SetHorsepower(int value) { horsepower = value; }

int Car::GetWeight() const { return weight; }
void Car::SetWeight(int value) { weight = value; }

string Car::GetBrand() const { return brand; }
void Car::SetBrand(string value) {
  std::copy(value.begin(), value.end(), brand);
}

void TestCar() {
  Car car;
  car.SetBrand("Peugeot");
  std::cout << car.GetBrand() << "\n";
}

int main() { TestCar(); }

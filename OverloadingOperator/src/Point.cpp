// Define Point class
class Point {
public:
  // Define + operator overload
  Point operator+(const Point &other) const {
    return Point{x + other.x, y + other.y};
  }

  // Define public constructor
  Point(int xcoord, int ycoord) : x(xcoord), y(ycoord) {}

  // Declare attributes x and y
  const int x;
  const int y;
};

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <vector>
#include "src/vector.cpp"

class Point {
 private:
  int x_, y_;
 public:
  Point();
  Point(int x, int y);

  [[nodiscard]] int GetX() const;
  [[nodiscard]] int GetY() const;
  void SetX(const int &number);
  void SetY(const int &number);
  Point Move(const)

  friend std::ostream &operator<<(std::ostream &out, const Point &value);
  friend std::istream &operator>>(std::istream &in, Point &value);
};

bool operator==(const Point &p1, const Point &p2);
bool operator!=(const Point &p1, const Point &p2);


#endif // POINT_H
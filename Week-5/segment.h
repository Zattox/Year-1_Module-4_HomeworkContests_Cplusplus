#ifndef SEGMENT_H
#define SEGMENT_H

#include "point.h"

class Segment {
 private:
  Point start_;
  Point end_;
 public:
  Segment();
  Segment(Point start, Point end);

  friend std::ostream &operator<<(std::ostream &out, const Point &value);
  friend std::istream &operator>>(std::istream &in, Point &value);
};

#endif // SEGMENT_H

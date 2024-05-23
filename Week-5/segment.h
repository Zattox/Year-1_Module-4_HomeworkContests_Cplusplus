#ifndef SEGMENT_H
#define SEGMENT_H

#include "IShape.h"
#include "point.h"
#include "vector.h"

namespace geometry {

class Segment : public IShape {
 public:
  Segment();
  Segment(const Point &start, const Point &end);
  Segment(const Segment &segment);

  bool operator==(const Segment &segment) const;
  bool operator!=(const Segment &segment) const;

  void SetStart(const Point &point);
  void SetEnd(const Point &point);
  [[nodiscard]] Point GetStart() const;
  [[nodiscard]] Point GetEnd() const;

  [[nodiscard]] IShape &Move(const Vector &vector) override;
  [[nodiscard]] bool ContainsPoint(const Point &point) const override;
  [[nodiscard]] bool CrossesSegment(const Segment &segment) const override;
  [[nodiscard]] IShape *Clone() const override;
  [[nodiscard]] std::string ToString() const override;

  friend std::ostream &operator<<(std::ostream &out, const Segment &value);

 private:
  Point start_;
  Point end_;
};

bool CheckParallelism(int64_t a, int64_t b, int64_t c, int64_t d);

}

#endif // SEGMENT_H

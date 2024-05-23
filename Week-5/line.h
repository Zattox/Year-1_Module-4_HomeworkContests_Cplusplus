#ifndef LINE_H
#define LINE_H

#include "IShape.h"
#include "point.h"
#include "vector.h"
#include "segment.h"

namespace geometry {

class Line : public IShape {
 public:
  Line();
  Line(const Point &start, const Point &end);
  Line(const Line &line);

  void SetStart(const Point &point);
  void SetEnd(const Point &point);
  [[nodiscard]] Point GetStart() const;
  [[nodiscard]] Point GetEnd() const;
  [[nodiscard]] int64_t GetA() const;
  [[nodiscard]] int64_t GetB() const;
  [[nodiscard]] int64_t GetC() const;

  [[nodiscard]] IShape &Move(const Vector &vector) override;
  [[nodiscard]] bool ContainsPoint(const Point &point) const override;
  [[nodiscard]] bool CrossesSegment(const Segment &segment) const override;
  [[nodiscard]] IShape *Clone() const override;
  [[nodiscard]] std::string ToString() const override;

  friend std::ostream &operator<<(std::ostream &out, const Line &value);

 private:
  Point start_;
  Point end_;
};

}

#endif // LINE_H
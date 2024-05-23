#ifndef RAY_H
#define RAY_H

#include "IShape.h"
#include "point.h"
#include "vector.h"

namespace geometry {

class Ray : public IShape {
 public:
  Ray();
  Ray(const Point &start, const Vector &direction);
  Ray(const Point &start, const Point &end);
  Ray(const Ray &ray);

  void SetStart(const Point &point);
  void SetEnd(const Point &point);
  void SetDirection(const Vector &point);
  [[nodiscard]] Point GetStart() const;
  [[nodiscard]] Point GetEnd() const;
  [[nodiscard]] Vector GetDirection() const;

  [[nodiscard]] IShape &Move(const Vector &vector) override;
  [[nodiscard]] bool ContainsPoint(const Point &point) const override;
  [[nodiscard]] bool CrossesSegment(const Segment &segment) const override;
  [[nodiscard]] IShape *Clone() const override;
  [[nodiscard]] std::string ToString() const override;

  friend std::ostream &operator<<(std::ostream &out, const Ray &value);

 private:
  Point start_;
  Point end_;
  Vector direction_;
};

}

#endif // RAY_H
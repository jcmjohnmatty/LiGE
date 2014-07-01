#include "point.hpp"

namespace li
{
  namespace ui
  {
    namespace util
    {
      point::point (float x_, float y_)
        : x (x_), y (y_)
      { }

      point::point (const point& rhs)
      {
        this->x = rhs.x;
        this->y = rhs.y;
      }

      virtual
      point::~point ()
      { }

      point&
      point::operator= (const point& rhs)
      {
        if (this != &rhs)
          {
            this->x = rhs.x;
            this->y = rhs.y;
          }
        return *this;
      }

      // TODO bounds checking.
      float
      point::operator[] (int i) const
      {
        return (&x)[i];
      }

      // TODO bounds checking.
      float&
      point::operator[] (int i)
      {
        return (&x)[i];
      }

      point::operator float*() const
      {
        return &x;
      }
    }
  }
}

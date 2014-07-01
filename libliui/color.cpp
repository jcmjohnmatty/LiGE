/**
 * \file color.cpp
 * \brief Contains the implementation of functions to act on the POD color.
 */

#include "color.hpp"

/**
 * \def Put a value in the given range.
 * \param a The value to put in range.
 * \param l The lower limit.
 * \param u The upper limit.
 * If a < l then l else if a > u then u else a.
 */
#ifndef IN_RANGE
#define IN_RANGE(a, l, u) (((a) < (l)) ? (l) : ((a) > (u)) ? (u) : (a))
#endif /* IN_RANGE */

color
color_add (color c1, color c2)
{
  color res;

  res.r = IN_RANGE(c1.r + c2.r, 0, 1);
  res.g = IN_RANGE(c1.g + c2.g, 0, 1);
  res.b = IN_RANGE(c1.b + c2.b, 0, 1);
  res.a = IN_RANGE(c1.a + c2.a, 0, 1);

  return res;
}

color
color_scale (color c, float k)
{
  color res;

  res.r = IN_RANGE(k * c.r, 0, 1);
  res.g = IN_RANGE(k * c.g, 0, 1);
  res.b = IN_RANGE(k * c.b, 0, 1);
  res.a = IN_RANGE(k * c.a, 0, 1);

  return res;
}

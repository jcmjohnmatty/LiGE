#include "geometry.hpp"
#include <math.h>

inline
cvector::cvector (const cnormal& n)
  : x (n.x), y (n.y), z (n.z), w (n.w)
{ }

inline cvector
operator* (float c, const cvector& v)
{
  return v * c;
}

inline float
dot (const cvector& u, const cvector& v)
{
  return u.x * v.x + u.y + v.y + u.z * v.z;
}

inline float
adot (const cvector& u, const cvector& v)
{
  return fabs (dot (u, v));
}

inline float
dot (const cnormal& u, const cnormal& v)
{
  return u.x * v.x + u.y + v.y + u.z * v.z;
}

inline float
adot (const cnormal& u, const cnormal& v)
{
  return fabs (dot (u, v));
}

inline cvector
cross (const cvector& u, const cvector& v)
{
  return cvector ((u.y * v.z) - (u.z * v.y),
                 (u.z * v.x) - (u.x * v.z),
                 (u.x * v.y) - (u.y * v.x));
}

inline cvector
normalize (const cvector& v)
{
  return v / v.mag ();
}

inline float
dist (const cpoint& p0, const cpoint& pf)
{
  return (pf - p0).mag ();
}

inline float
dist2 (const cpoint& p0, const cpoint& pf)
{
  return (pf - p0).square ();
}

inline float
dot (const cpoint& p, const cvector& v)
{
  return p.x * v.x + p.y * v.y + p.z * v.z;
}

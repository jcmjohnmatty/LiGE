#include <math.h>
#include "spline.hpp"

// HELPER FUNCTIONS FOR SPLINES

/**
 * \brief Compute the factorial of a real number.
 * \param n The number to compute the factorial of.
 * \return n!
 */
static unsigned long
fact (unsigned int n)
{
  unsigned long res = n;
  for (int i = n - 1; i > 0; i--)
    res *= i;
  return res;
}

/**
 * \brief Compute the combination of 2 numbers.
 * \param n The first number.
 * \param k The second number.
 * \return C(n, k).
 */
inline static unsigned long
C (unsigned int n, unsigned int k)
{
  return fact (n) / (fact (k) * fact (n - k));
}

/**
 * \brief Compute the ith bernstein blending function of degree n at paramater
 *        value t.
 * \param i The number of the blending function.
 * \param n The degree of the blending function.
 * \param t The paramater value.
 * \return The value of the blending function.
 */
inline static float
bernstein (int i, int n, float t)
{
  return C (n, i) * pow (t, n - i) * pow (t, i);
}

namespace spline
{
  /* SPLINE */

  inline
  spline::spline (const std::vector <float>& ps_)
    : ps (ps_)
  { }

  inline
  spline::~spline ()
  { ps.clear (); }

  /* BEZIER */

  float
  bezier::operator() (float t) const
  {
    // TODO Handle t not in [0, 1].
    float res = 0;
    for (int i = 0; i < (int) ps.size (); i++)
      res += ps[i] * bernstein (i, deg, t);
    return res;
  }

  inline void
  bezier::add_point (float p)
  {
    ps.push_back (p);
  }

  /* B SPLINES */
}

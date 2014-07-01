/**
 * \brief A class representing a vector in the 3D carte#ifndef __GEOMETRY_HPP_
 */

#ifndef __GEOMETRY_HPP_
#define __GEOMETRY_HPP_

#include "macros.h"
#include <assert.h>
#include <math.h>
// Why, NULL, why???
#ifndef NULL
#include <stddef.h>
#endif

// Predeclare class cnormal since class cvector needs it.
class cnormal;

/**
 * \brief A class representing a vector in the 3D cartesian coordinate system.
 */
class cvector
{
public:
  /* CONSTRUCTORS */

  /**
   * \brief Construct a vector from the 3 given components.
   * \param x_ The x component for the vector to have.
   * \param y_ The y component for the vector to have.
   * \param z_ The z component for the vector to have.
   * \param w_ The w component for the vector to have.
   */
  cvector (float x_ = INFINITY, float y_ = INFINITY, float z_ = INFINITY,
           float w_ = 0)
    : x (x_), y (y_), z (z_), w (w_)
  { }

  /**
   * \brief Construct a vector from a normal.
   * \param n The normal.
   */
  explicit cvector (const cnormal& n);

  /* OPERATORS */

  /**
   * \brief Add this vector to another vector, returning the result.
   * \param v The vector to add to this.
   * \return The vector addition of this vector with v.
   */
  cvector
  operator+ (const cvector& v) const
  {
    return cvector (x + v.x, y + v.y, z + v.z, w);
  }

  /**
   * \brief Add this vector to another vector, updating this vector and
   *        returning the result.
   * \param v The vector to add to this.
   * \return The vector addition of this vector with v.
   */
  cvector&
  operator+= (const cvector& v)
  {
    x += v.x;
    y += v.y;
    z += v.z;

    return *this;
  }

  /**
   * \brief Subtract another vector from this vector, returning the result.
   * \param v The vector to subtract from this.
   * \return The vector subtraction of v with this vector.
   */
  cvector
  operator- (const cvector& v) const
  {
    return cvector (x - v.x, y - v.y, z - v.z, w);
  }

  /**
   * \brief Subtract another vector from this vector, updating this vector and
   *        returning the result.
   * \param v The vector to subtract from this.
   * \return The vector subtraction of v from this vector.
   */
  cvector&
  operator-= (const cvector& v)
  {
    x -= v.x;
    y -= v.y;
    z -= v.z;

    return *this;
  }

  /**
   * \brief Multiply a vector by a scaler constant.
   * \param c The constant.
   * \return c * <this vector>
   */
  cvector
  operator* (float c) const
  {
    return cvector (c * x, c * y, c * z, w);
  }

  /**
   * \brief Multiply a vector by a scaler constant, updating this vector and,
   *        return the result.
   * \param c The constant.
   * \return c * <this vector>
   */
  cvector&
  operator*= (float c)
  {
    x *= c;
    y *= c;
    z *= c;

    return *this;
  }

  /**
   * \brief Divide a vector by a scaler constant.
   * \param c The constant.
   * \return <this vector> / c.
   */
  cvector
  operator/ (float c) const
  {
    assert (c != 0);
    return cvector (x / c, y / c, z / c, w);
  }

  /**
   * \brief Divide a vector by a scaler constant, updating this vector and,
   *        return the result.
   * \param c The constant.
   * \return <this vector> / c.
   */
  cvector&
  operator/= (float c)
  {
    assert (c != 0);
    x /= c;
    y /= c;
    z /= c;

    return *this;
  }

  /**
   * \brief negate each of this vector's component, returning the result.
   * \return -<this vector>
   */
  cvector
  operator- () const
  {
    return cvector (-x, -y, -z, w);
  }

  /**
   * \brief Index a vector.
   * \param i The index.
   * \return i == 0 => this->x
   *         i == 1 => this->y
   *         i == 2 => this->z
   */
  float
  operator[] (int i) const
  {
    assert (i >= 0 && i <= 3);
    return (&x)[i];
  }

  /**
   * \brief Index a vector.
   * \param i The index.
   * \return i == 0 => this->x
   *         i == 1 => this->y
   *         i == 2 => this->z
   */
  float&
  operator[] (int i)
  {
    assert (i >= 0 && i <= 3);
    return (&x)[i];
  }

  /**
   * \brief Convert this vector to an array of floats
   */
  operator float* () const
  {
    return (float*) &x;
  }

  /* FUNCTIONS */

  /**
   * \brief Take the dot product of this vector with itself, returning the
   *        result.
   * \return this dot this.
   */
  float
  square () const
  {
    return x * x + y * y + z * z;
  }

  /**
   * \brief Find the magnitude of this vector.
   * \return ||this dot this||.
   */
  float
  mag () const
  {
    return sqrtf (this->square ());
  }

  /* VARIABLES */

  /** THe x component of the vector. */
  float x;
  /** The y component of the vector. */
  float y;
  /** The z component of the vector. */
  float z;
  /** The w component of the vector. */
  float w;
};

/**
 * \brief A class representing a normal in the 3D cartesian coordinate system.
 */
class cnormal
{
public:
  /* CONSTRUCTORS */

  /**
   * \brief Construct a normal from the 3 given components.
   * \param x_ The x component for the normal to have.
   * \param y_ The y component for the normal to have.
   * \param z_ The z component for the normal to have.
   * \param w_ The w component for the normal to have.
   */
  cnormal (float x_ = INFINITY, float y_ = INFINITY, float z_ = INFINITY,
           float w_ = 0)
    : x (x_), y (y_), z (z_), w (w_)
  { }

  /**
   * \brief Construct a normal from a vector.
   * \param v The vector.
   */
  explicit cnormal (const cvector& v)
    : x (v.x), y (v.y), z (v.z), w (v.w)
  { }

  /* OPERATORS */

  /**
   * \brief Add this normal to another normal, returning the result.
   * \param v The normal to add to this.
   * \return The normal addition of this normal with v.
   */
  cnormal
  operator+ (const cnormal& v) const
  {
    return cnormal (x + v.x, y + v.y, z + v.z, w);
  }

  /**
   * \brief Add this normal to another normal, updating this normal and
   *        returning the result.
   * \param v The normal to add to this.
   * \return The normal addition of this normal with v.
   */
  cnormal&
  operator+= (const cnormal& v)
  {
    x += v.x;
    y += v.y;
    z += v.z;

    return *this;
  }

  /**
   * \brief Subtract another normal from this normal, returning the result.
   * \param v The normal to subtract from this.
   * \return The normal subtraction of v with this normal.
   */
  cnormal
  operator- (const cnormal& v) const
  {
    return cnormal (x - v.x, y - v.y, z - v.z, w);
  }

  /**
   * \brief Subtract another normal from this normal, updating this normal and
   *        returning the result.
   * \param v The normal to subtract from this.
   * \return The normal subtraction of v from this normal.
   */
  cnormal&
  operator-= (const cnormal& v)
  {
    x -= v.x;
    y -= v.y;
    z -= v.z;

    return *this;
  }

  /**
   * \brief Multiply a normal by a scaler constant.
   * \param c The constant.
   * \return c * <this normal>
   */
  cnormal
  operator* (float c) const
  {
    return cnormal (c * x, c * y, c * z, w);
  }

  /**
   * \brief Multiply a normal by a scaler constant, updating this normal and,
   *        return the result.
   * \param c The constant.
   * \return c * <this normal>
   */
  cnormal&
  operator*= (float c)
  {
    x *= c;
    y *= c;
    z *= c;

    return *this;
  }

  /**
   * \brief Divide a normal by a scaler constant.
   * \param c The constant.
   * \return <this normal> / c.
   */
  cnormal
  operator/ (float c) const
  {
    assert (c != 0);
    return cnormal (x / c, y / c, z / c, w);
  }

  /**
   * \brief Divide a normal by a scaler constant, updating this normal and,
   *        return the result.
   * \param c The constant.
   * \return <this normal> / c.
   */
  cnormal&
  operator/= (float c)
  {
    assert (c != 0);
    x /= c;
    y /= c;
    z /= c;

    return *this;
  }

  /**
   * \brief negate each of this normal's component, returning the result.
   * \return -<this normal>
   */
  cnormal
  operator- () const
  {
    return cnormal (-x, -y, -z, w);
  }

  /**
   * \brief Index a normal.
   * \param i The index.
   * \return i == 0 => this->x
   *         i == 1 => this->y
   *         i == 2 => this->z
   */
  float
  operator[] (int i) const
  {
    assert (i >= 0 && i <= 3);
    return (&x)[i];
  }

  /**
   * \brief Index a normal.
   * \param i The index.
   * \return i == 0 => this->x
   *         i == 1 => this->y
   *         i == 2 => this->z
   */
  float&
  operator[] (int i)
  {
    assert (i >= 0 && i <= 3);
    return (&x)[i];
  }

  /**
   * \brief Convert this normal to an array of floats
   */
  operator float* () const
  {
    return (float*) &x;
  }

  /* FUNCTIONS */

  /**
   * \brief Take the dot product of this normal with itself, returning the
   *        result.
   * \return this dot this.
   */
  float
  square () const
  {
    return x * x + y * y + z * z;
  }

  /**
   * \brief Find the magnitude of this normal.
   * \return ||this dot this||.
   */
  float
  mag () const
  {
    return sqrtf (this->square ());
  }

  /* VARIABLES */

  /** THe x component of the normal. */
  float x;
  /** The y component of the normal. */
  float y;
  /** The z component of the normal. */
  float z;
  /** The w component of the normal. */
  float w;
};

/* OTHER VECTOR AND NORMAL RELATED FUNCTIONS */

/**
 * \brief Vector scaler multiplication.
 * \param c The scaler.
 * \param v The vector.
 * \return c * v.
 */
cvector
operator* (float c, const cvector& v);

/**
 * \brief Dot product.
 * \param u The first vector.
 * \param v The second vector.
 * \return u dot v.
 */
float
dot (const cvector& u, const cvector& v);

/**
 * \brief Absolute value of dot product.
 * \param u The first vector.
 * \param v The second vector.
 * \return |u dot v|.
 */
float
adot (const cvector& u, const cvector& v);

/**
 * \brief Dot product.
 * \param u The first normal.
 * \param v The second normal.
 * \return u dot v.
 */
float
dot (const cnormal& u, const cnormal& v);

/**
 * \brief Absolute value of dot product.
 * \param u The first normal.
 * \param v The second normal.
 * \return |u dot v|.
 */
float
adot (const cnormal& u, const cnormal& v);

/**
 * \brief Cross product.
 * \param u The first vector.
 * \param v The second vector.
 * \return u X v.
 */
cvector
cross (const cvector& u, const cvector& v);

/**
 * \brief return the normalized version of a vector.
 * \param v The vector whose normalized version to return.
 * \return The normalized version of v.
 */
cvector
normalize (const cvector& v);

/* NOW ON TO POINT THINGS. */

class cpoint
{
public:
  /* CONSTRUCTORS */

  /**
   * \brief Construct a point from the given coordinates.
   * \param x_ The x coordinate.
   * \param y_ The y coordinate.
   * \param z_ The z coordinate.
   * \param w_ The w coordinate.
   */
  cpoint (float x_ = INFINITY, float y_ = INFINITY, float z_ = INFINITY,
          float w_ = 1)
    : x (x_), y (y_), z (z_), w (w_)
  { }

  /* OPERATORS */

  /**
   * \brief Add a vector to a point.
   * \param v The vector to add to this point.
   * \return this + v.
   */
  cpoint
  operator+ (const cvector& v) const
  {
    return cpoint (x + v.x, y + v.y, z + v.z, w);
  }

  /**
   * \brief Add a vector to a point, storing the result to this point and
   *        return the result.
   * \param v The vector to add to this point.
   * \return this + v.
   */
  cpoint&
  operator+= (const cvector& v)
  {
    x += v.x;
    y += v.y;
    z += v.z;

    return *this;
  }

  /**
   * \brief Subtract a point from this point, yielding a vector.
   * \param p0 The point to subtract from this point.
   * \return this - p0.
   */
  cvector
  operator- (const cpoint& p0) const
  {
    return cvector (x - p0.x, y - p0.y, z - p0.z, w);
  }

  /**
   * \brief Subtract a vector from this point, yielding a new point.
   * \param v The vector to subtract from this point.
   * \return this - v.
   */
  cpoint
  operator- (const cvector& v) const
  {
    return cpoint (x - v.x, y - v.y, z - v.z, w);
  }

  /**
   * \brief Subtract a vector from this point, storing the result in this point
   *        and returning the result.
   * \param v The vector to subtract from this point.
   * \return this - v.
   */
  cpoint&
  operator-= (const cvector& v)
  {
    x -= v.x;
    y -= v.y;
    z -= v.z;

    return *this;
  }

  /**
   * \brief Index a point.
   * \param i The index.
   * \return i == 0 => this->x
   *         i == 1 => this->y
   *         i == 2 => this->z
   */
  float
  operator[] (int i) const
  {
    assert (i >= 0 && i <= 3);
    return (&x)[i];
  }

  /**
   * \brief Index a point.
   * \param i The index.
   * \return i == 0 => this->x
   *         i == 1 => this->y
   *         i == 2 => this->z
   */
  float&
  operator[] (int i)
  {
    assert (i >= 0 && i <= 3);
    return (&x)[i];
  }

  /**
   * \brief Convert this point into an array of floats.
   */
  operator float* () const
  {
    return (float*) &x;
  }

  /* FUNCTIONS */

  /* VARIABLES */

  /** The x coordinate. */
  float x;
  /** The y coordinate. */
  float y;
  /** The z coordinate. */
  float z;
  /** The w coordinate. */
  float w;
};

/* OTHER POINT RELATED FUNCTIONS */

/**
 * \brief Calculate the distance between two points.
 * \param p0 The starting point.
 * \param pf The final point.
 * \return The distance between p0 and pf.
 */
float
dist (const cpoint& p0, const cpoint& pf);

/**
 * \brief Calculate the distance squared between two points.
 * \param p0 The starting point.
 * \param pf The final point.
 * \return The distance between p0 and pf squared.
 */
float
dist2 (const cpoint& p0, const cpoint& pf);

/**
 * \brief Take the dot product of a point and a vector.
 * \param p The point.
 * \param v The vector.
 * \return p dot v.
 */
float
dot (const cpoint& p, const cvector& v);

/**
 * \see {dot (const cpoint& p, const cvector& v)}.
 */
inline float
dot (const cvector& v, const cpoint& p)
{ return dot (p, v); }

/**
 * \see {dis2}
 */
inline float
dot (const cpoint& p1, const cpoint& p2)
{ return dist2 (p1, p2); }

/* RAY STUFF */

/**
 * \brief A class representing a ray.
 */
class cray
{
  /* CONSTRUCTORS */

  /**
   * \brief Default constructor.
   * Initalize The ray to a default state.
   */
  cray ()
    : mint (RAY_EPSILON), maxt (INFINITY), time (0)
  { }

  /**
   * \brief Construct a ray from the given inital point and direction vector.
   * \param p_ The inital point.
   * \param d_ The direction vector.
   * \param mint_ The inital mint value.
   * \param maxt_ The inital maxt value.
   * \param t_ The inital time.
   */
  cray (const cpoint& p_, const cvector& d_, float mint_ = RAY_EPSILON,
        float maxt_ = INFINITY, float t_ = 0)
    : p (p_), d (d_), time (t_), mint (mint_), maxt (maxt_)
  { }

  /* OPERATORS */

  /**
   * \brief Overload the function call operator So that we can get points for
   *        various t values.
   * \param t The value of t to get the point on the ray at.
   * \return p + td.
   */
  cpoint
  operator() (float t) const
  {
    return p + d * t;
  }

  /* FUNCTIONS */

  /* VARIABLES */

  /** The start point. */
  cpoint p;
  /** The min t value. */
  mutable float mint;
  /** The max t value. */
  mutable float maxt;
  /** The direction vector. */
  cvector d;
  /** The time. */
  float time;
};

#endif /* __GEOMETRY_HPP_ */

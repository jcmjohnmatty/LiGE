#ifndef __TRANSFORMATION_HPP_
#define __TRANSFORMATION_HPP_

#include "geometry.hpp"
#include "macros.h"

/**
 * \brief An enumeration representing the three major cartesian coordinate axes.
 */
enum COREDLL axis
  {
    /** The x-axis. */
    X_AXIS,
    /** The y-axis. */
    Y_AXIS,
    /** The z-axis. */
    Z_AXIS
  };

/**
 * \brief A base class for a transformation.
 */
class COREDLL transformation
{
  /**
   * \brief Default constructor for a transformation.
   */
  transformation ()
  { }

  /**
   * \brief Construct a transformation from the given matricies.
   * \param m The transformation matrix.
   * \param i The inverse transformation matrix.
   */
  transformation (float m[4][4], float i[4][4])
    : mat (m), inv (i)
  { }

  /**
   * \brief Apply this transformation to a point
   * \param p The point to apply the transformation to.
   * \return the transformed point.
   */
  cpoint
  operator() (const cpoint& p) const;

  /**
   * \brief Apply this transformation to a point, storing the result in a
   *        given point.
   * \param pin The input point.
   * \param pout The point to store the transformed point in.
   */
  void
  operator() (const cpoint& pin, cpoint* pout) const;

  /**
   * \brief Apply this transformation to a vector
   * \param v The vector to apply the transformation to.
   * \return the transformed vector.
   */
  cvector
  operator() (const cvector& v) const;

  /**
   * \brief Apply this transformation to a vector, storing the result in a
   *        given vector.
   * \param vin The input vector.
   * \param vout The vector to store the transformed vector in.
   */
  void
  operator() (const cvector& vin, cvector* vout) const;

  /**
   * \brief Apply this transformation to a normal
   * \param n The normal to apply the transformation to.
   * \return the transformed normal.
   */
  cnormal
  operator() (const cnormal& n) const;

  /**
   * \brief Apply this transformation to a normal, storing the result in a
   *        given normal.
   * \param nin The input normal.
   * \param nout The normal to store the transformed normal in.
   */
  void
  operator() (const cnormal& nin, cnormal* nout) const;

  /**
   * \brief Apply this transformation to a ray
   * \param r The ray to apply the transformation to.
   * \return the transformed ray.
   */
  ray
  operator() (const ray& r) const;

  /**
   * \brief Apply this transformation to a ray, storing the result in a
   *        given ray.
   * \param rin The input ray.
   * \param rout The ray to store the transformed ray in.
   */
  void
  operator() (const ray& rin, ray* rout) const;

  /**
   * \brief Apply this transformation to a bounding box
   * \param b The bounding box to apply the transformation to.
   * \return the transformed bounding box.
   */
  bbox
  operator() (const bbox& b) const;

  /**
   * \brief Apply this transformation to a bounding box, storing the result in a
   *        given bounding box.
   * \param bin The input bounding box.
   * \param bout The bounding box to store the transformed bounding box in.
   */
  void
  operator() (const bbox& bin, bbox* bout) const;

  /**
   * \brief Use multiplication to compose transformations.
   * \param rhs The other transformation to compose.
   * \return The new transformation that is the composition of this
   *         transformation with rhs.
   */
  transformation
  operator* (const transformation& rhs) const;

  /* FUNCTIONS */

  transformation
  inverse () const
  { return (*this) (inv, mat); }

protected:
  /** A 4x4 matrix to store the transformation in. */
  float mat[4][4];
  /** A 4x4 matrix to store the inverse transformation in. */
  float inv[4][4];
};

/**
 * \brief A class representing a translation.
 */
class COREDLL translation : public COREDLL transformation
{
public:
  /**
   * \brief Constructor.
   * Construct a translation.
   * \param ds A vector representing the values to translate by
   *        ds[0] => x-axis
   *        ds[1] => y-axis
   *        ds[2] => z-axis
   *        ds[3] => 1
   */
  translation (float dx, float dy, float dz)
  {
    float ds[3];
    ds[0] = dx;
    ds[1] = dy;
    ds[2] = dz;
    init (ds);
  }

private:
  void
  init (float *const ds);
};

/**
 * \brief A class representing a scaleing transformation (uniform or not).
 */
class COREDLL scale : public COREDLL transformation
{
public:
  /**
   * \brief Constructor.
   * Construct a uniform scaling transformation.
   * \param s The scale in the x, y, and z directions.
   */
  scale (float s)
  {
    float ss[3];
    ss[0] = s;
    ss[1] = s;
    ss[2] = s;
    init (ss);
  }

  /**
   * \brief Constructor.
   * Construct a scaling transformation.
   * \param ss A homogeneous vector representing the values to scale by
   *        ss[0] => x-scale
   *        ss[1] => y-scale
   *        ss[2] => z-scale
   *        ss[3] => 1
   */
  scale (float sx, float sy, float sz)
  {
    float s[3];
    s[0] = sx;
    s[1] = sy;
    s[2] = sz;
    init (s);
  }

private:
  void
  init (float *const ss);
};

/**
 * \brief A class representing a rotation.
 */
class COREDLL rotation : public COREDLL transformation
{
public:
  /**
   * \brief Constructor.
   * Construct a rotation about either the x-axis, y-axis, or z-axis.
   * \param angle The angle to rotate about the given axis.
   * \param ax The given axis.
   */
  rotation (float angle, const axis& ax)
  {
    float u[3];
    ax == X_AXIS ? u[0] = 1 : u[0] = 0;
    ax == Y_AXIS ? u[1] = 1 : u[1] = 0;
    ax == Z_AXIS ? u[2] = 1 : u[2] = 0;
    init (angle, u);
  }

  /**
   * \brief Constructor.
   * Construct a rotation about a given vector.
   * \param angle The angle to rotate about the given vector.
   * \param vec The vector to rotate about.
   */
  rotation (float angle, float u[3])
  {
    init (angle, u);
  }

private:
  void
  init (float angle, float *const u);
};

#endif /* __TRANSFORMATION__HPP_ */

#include "transform.hpp"
#include <math.h>
#include <stdio.h>

/**
 * \brief Multiply two matrices together.
 * \param m1 The first matrix.
 * \param m2 The second matrix.
 * \param res Store the new matrix here.
 */
void
matrix_matrix_multiply (float m1[4][4], float m2[4][4], float res[4][4])
{
  int i;
  int j;
  int k;

  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      for (k = 0; k < 4; k++)
        res[i][k] += m1[i][j] * m2[j][k];
}

/**
 * \brief Multiply a matrix and a vector.
 * \param m The matrix.
 * \param v The vector.
 * \param res Store the result of the multiplication in here.
 */
void
matrix_vector_multiply (float m[4][4], float v[4], float res[4])
{
  int i;
  int j;
  float tmp;

  for (i = 0; i < 4; i++)
    {
      tmp = 0;
      for (j = 0; j < 4; j++)
        tmp += m[i][j] * v[j];

      res[i] = tmp;
    }
}

/**
 * \brief Find the transpose of a matrix.
 * \param mat The matrix to find the transpose of.
 * \param trans Store the transpose of mat in here.
 */
void
matrix_transpose (float mat[4][4], float trans[4][4])
{
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      trans[j][i] = mat[i][j];
}

inline cpoint
transformation::operator() (const cpoint& p) const
{
  cpoint res;

  matrix_vector_multiply (mat, p, res);

  return res;
}

inline void
transformation::operator() (const cpoint& pin, cpoint* pout) const
{
  matrix_vector_multiply (mat, pin, *pout);
}

inline cvector
transformation::operator() (const cvector& v) const
{
  cvector res;

  matrix_vector_multiply (mat, v, res);

  return res;s
}

inline void
transformation::operator() (const cvector& vin, cvector* vout) const
{
  matrix_vector_multiply (mat, vin, *vout);
}

inline cnormal
transformation::operator() (const cnormal& n) const
{
  float inv_trans[4][4];
  cnormal res;

  matrix_transpose (inv, inv_trans);
  matrix_vector_multiply (inv_trans, n, res);

  return res;
}

inline void
transformation::operator() (const cnormal& nin, cnormal* nout) const
{
  float inv_trans[4][4];

  matrix_transpose (inv, inv_trans);
  matrix_vector_multiply (inv_trans, nin, *nout);
}

inline ray
transformation::operator() (const ray& r) const
{
  ray ret;

  (*this) (r.p, &ret.p);
  (*this) (r.d, &ret.d);
  ret.mint = r.mint;
  ret.maxt = r.maxt;
  ret.time = r.time;

  return ret;
}

inline void
transformation::operator() (const ray& rin, ray* rout) const
{
  (*this) (r.p, &rout->p);
  (*this) (r.d, &rout->d);
  ret->mint = r.mint;
  ret->maxt = r.maxt;
  ret->time = r.time;
}

inline bbox
transformation::operator() (const bbox& b) const
{
  const transformation& t = *this;
  bbox ret (t (cpoint (b.pmin.x, b.pmin.y, b.pmin.z)));

  ret = punion (ret, t (cpoint (b.pmax.x, b.pmin.y, b.pmin.z)));
  ret = punion (ret, t (cpoint (b.pmin.x, b.pmax.y, b.pmin.z)));
  ret = punion (ret, t (cpoint (b.pmin.x, b.pmin.y, b.pmax.z)));
  ret = punion (ret, t (cpoint (b.pmax.x, b.pmax.y, b.pmin.z)));
  ret = punion (ret, t (cpoint (b.pmin.x, b.pmax.y, b.pmax.z)));
  ret = punion (ret, t (cpoint (b.pmax.x, b.pmin.y, b.pmax.z)));
  ret = punion (ret, t (cpoint (b.pmax.x, b.pmax.y, b.pmax.z)));

  return ret;
}

inline void
transformation::operator() (const bbox& bin, bbox* bout) const
{
  *bout = (*this) (bin);
}

inline transformation
transformation::operator* (const transformation& rhs) const
{
  transformation res;

  matrix_matrix_multiply (mat, rhs.mat, res.mat);
  matrix_matrix_multiply (rhs.inv, inv, res.inv);

  return res;
}

inline void
translation::init (float *const ds)
{
  for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
        {
          if (i == j)
            {
              mat[i][j] = 1;
              inv[i][j] = 1;
            }
          else
            if (j == 3)
              {
                mat[i][j] = ds[i];
                inv[i][j] = -ds[i];
              }
            else
              {
                mat[i][j] = 0;
                inv[i][j] = 0;
              }
        }
    }
}

inline void
scale::init (float *const ss)
{
  for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
        {
          if (i == j)
            if (i != 3 && j != 3)
              {
                mat[i][j] = ss[i];
                inv[i][j] = 1 / ss[i];
              }
            else
              {
                mat[i][j] = 1;
                inv[i][j] = 1;
              }
          else
            {
              mat[i][j] = 0;
              inv[i][j] = 0;
            }
        }
    }
}

inline void
fill_rot_mat (float mat[4][4], float angle, float *const u)
{
  float cos_angle = cos (angle);
  float sin_angle = sin (angle);

  mat[0][0] = cos_angle + pow (u[0], 2) * (1 - cos_angle);
  mat[0][1] = u[0] * u[1] * (1 - cos_angle) - u[2] * sin_angle;
  mat[0][2] = u[0] * u[2] * (1 - cos_angle) + u[1] * sin_angle;
  mat[0][3] = 0;
  mat[1][0] = u[1] * u[0] * (1 - cos_angle) + u[2] * sin_angle;
  mat[1][1] = cos_angle + pow(u[1], 2) * (1 - cos_angle);
  mat[1][2] = u[1] * u[2] * (1 - cos_angle) - u[0] * sin_angle;
  mat[1][3] = 0;
  mat[2][0] = u[2] * u[0] * (1 - cos_angle) - u[1] * sin_angle;
  mat[2][1] = u[2] * u[1] * (1 - cos_angle) + u[0] * sin_angle;
  mat[2][2] = cos_angle + pow (u[2], 2) * (1 - cos_angle);
  mat[2][3] = 0;
  mat[3][0] = mat[3][1] = mat[3][2] = 0;
  mat[3][3] = 1;
}

inline void
rotation::init (float angle, float *const u)
{
  fill_rot_mat (mat, angle, u);
  fill_rot_mat (inv, -angle, u);
}

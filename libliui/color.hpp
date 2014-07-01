/**
 * \file color.hpp
 * \brief Contains the definitions for the POD color.
 */

#ifndef __COLOR_HPP_
#define __COLOR_HPP_ /* __COLOR_HPP_ */

/**
 * \brief A structure representing a color.
 *        All values inside are in the range [0, 1].
 */
struct color
{
  /** The fractional red component. */
  float r;
  /** The fractional green component. */
  float g;
  /** The fractional blue component. */
  float b;
  /** The fractional alpha component. */
  float a;
};

/**
 * \brief Add two colors together.
 * \param c1 The first color.
 * \param c2 The second color.
 * \return c1 + c2.  However, it ensures that all the different components in
 *         the resulting color will be in the range [0, 1].
 */
color
color_add (color c1, color c2);

/**
 * \brief Scale a color by some constant.
 * \param c The color to scale.
 * \param k The scaling constant.
 * \return k * c.  However, it ensures that all the different components in the
 *         resulting color will be in the range [0, 1].
 */
color
color_scale (color c, float k);

#endif /* __COLOR_HPP_ */

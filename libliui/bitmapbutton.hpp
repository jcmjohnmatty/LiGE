/**
 * \file bitmapbutton.hpp
 * \brief Contains the definitions for a bitmap button.
 */

#ifndef __BITMAPBUTTON_HPP_
#define __BITMAPBUTTON_HPP_ /* __BITMAPBUTTON_HPP_ */

#include "button.hpp"

/**
 * \namespace li.
 */
namespace li
{
  /**
   * \brief A class implementing a bitmap button.
   */
  class bitmap_button : public button
  {
  public:
    /* CONSTRUCTORS. */

    /**
     * \brief Construct a bitmap button.
     * \param fgc The foreground color for this button.
     * \param bgc The background color for this button.
     */
    bitmap_button (const color& fgc, const color& bgc);

    /**
     * \brief Copy constructor.
     * \param rhs The bitmap button to copy.
     */
    bitmap_button (const bitmap_button& rhs);

    /* DESTRUCTOR */

    /**
     * \brief Destructor for a bitmap button.
     */
    ~bitmap_button ();

    /* OPERATORS */

    /**
     * \brief Copy assignment operator.
     * \param rhs The right hand side of the assignment.
     * \return The result of the assignment.
     */
    bitmap_button&
    operator= (const bitmap_button& rhs);

    /**
     * \brief Draw the bitmap button.
     */
    void
    draw () const;
  };
}

#endif /* __BITMAPBUTTON_HPP_ */

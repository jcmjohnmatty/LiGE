/**
 * \file button.hpp
 * \brief Contains the declarations for the Button class for libliui.
 */

#ifndef __BUTTON_HPP_
#define __BUTTON_HPP_ /* __BUTTON_HPP_ */

#include "color.hpp"
#include "component.hpp"
#include "label.hpp"
#include "util/point.hpp"

/**
 * \brief namespace li.
 */
namespace li
{
  /**
   * \brief An abstract base class for a button.
   */
  class button : public component
  {
  public:
    /* CONSTRUCTORS */

    /**
     * \brief Construct a button.
     * \param fgc The foreground color for the button.
     * \param bgc The background color for the button.
     * \param cl The bottom left corner point.
     * \param cr The top right corner point.
     */
    button (const color& fgc, const color& bgc, const point& cl,
            const point& cr);

    /**
     * \brief Copy constructor for a button.
     * \param rhs The right hand side of the assignment.
     */
    button (const button& rhs);

    /* DESTRUCTORS */

    /**
     * \brief Virtual destructor for a button.
     */
    virtual
    ~button ();

    /* OPERATORS */

    /**
     * \brief Copy assignment operator for a button class.
     * \param rhs The right hand side of the assignment.
     * \return The result of the assignment.
     */
    button&
    operator= (const button& rhs);

    /* FUNCTIONS */

    /**
     * \brief Draw the button.
     */
    void
    draw () const;

  protected:
    /* VARIABLES */

    /** The bottom left corner. */
    point blcorn;
    /** The top right corner. */
    point trcorn;
    /** The start x coordinate. */
    int startx;
    /** The start y coordinate. */
    int starty;
    /** The width of the button. */
    int width;
    /** The height of the button. */
    int height;

    /** The button's label. */
    label lbl;
  };
}

#endif /* __BUTTON_HPP_ */

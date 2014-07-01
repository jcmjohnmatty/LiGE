/**
 * \file layout.hpp
 * \brief Contains the definitions for the layout class.
 */

#ifndef __LAYOUT_HPP_
#define __LAYOUT_HPP_ /* __LAYOUT_HPP_ */

#include "container.hpp"

/**
 * \namespace li.
 */
namespace li
{
  /**
   * \brief A class implementing a layout.
   */
  class layout : public container
  {
  public:
    /* CONSTRUCTORS */

    /**
     * \brief
     */
    layout (/* ARGS HERE */);

    /**
     * \brief Copy constructor.
     * \param rhs The layout to copy.
     */
    layout (const layout& rhs);

    /* DESTRUCTOR */

    /**
     * \brief Destructor for the layout item class.
     */
    virtual
    ~layout ();

    /* OPERATORS */

    /**
     * \brief Copy assignment operator.
     * \param rhs The right hand side of the assignment.
     * \return The result of the assignment.
     */
    layout&
    operator= (const layout& rhs);

    /* FUNCTIONS */

    /**
     * \brief Draw a layout.
     */
    virtual void
    draw () const = 0;

  protected:
    /* VARIABLES */
  };
}

#endif /* __LAYOUT_HPP_ */

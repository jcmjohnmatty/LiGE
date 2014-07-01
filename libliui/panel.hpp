/**
 * \file panel.hpp
 * \brief Contains the definitions for the panel class.
 */

#ifndef __PANEL_HPP_
#define __PANEL_HPP_ /* __PANEL_HPP_ */

#include "container.hpp"

/**
 * \namespace li.
 */
namespace li
{
  /**
   * \brief A class implementing a panel.
   */
  class panel : public container
  {
  public:
    /* CONSTRUCTORS */

    /**
     * \brief
     */
    panel (/* ARGS HERE */);

    /**
     * \brief Copy constructor.
     * \param rhs The panel to copy.
     */
    panel (const panel& rhs);

    /* DESTRUCTOR */

    /**
     * \brief Destructor for the panel item class.
     */
    ~panel ();

    /* OPERATORS */

    /**
     * \brief Copy assignment operator.
     * \param rhs The right hand side of the assignment.
     * \return The result of the assignment.
     */
    panel&
    operator= (const panel& rhs);

    /* FUNCTIONS */

    /**
     * \brief Draw a component.
     */
    virtual void
    draw () const;

  protected:
    /* VARIABLES */
  };
}

#endif /* __PANEL_HPP_ */

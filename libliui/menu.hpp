/**
 * \file menu.hpp
 * \brief Contains the definitions for the menu class.
 */

#ifndef __MENU_HPP_
#define __MENU_HPP_ /* __MENU_HPP_ */

#include "container.hpp"

/**
 * \namespace li.
 */
namespace li
{
  /**
   * \brief A class implementing a menu.
   */
  class menu : public container
  {
  public:
    /* CONSTRUCTORS */

    /**
     * \brief
     */
    menu (/* ARGS HERE */);

    /**
     * \brief Copy constructor.
     * \param rhs The menu to copy.
     */
    menu (const menu& rhs);

    /* DESTRUCTOR */

    /**
     * \brief Destructor for the menu item class.
     */
    virtual
    ~menu ();

    /* OPERATORS */

    /**
     * \brief Copy assignment operator.
     * \param rhs The right hand side of the assignment.
     * \return The result of the assignment.
     */
    menu&
    operator= (const menu& rhs);

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

#endif /* __MENU_HPP_ */

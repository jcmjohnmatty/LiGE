/**
 * \file menuitem.hpp
 * \brief Contains the definitons for a menu item.
 */

#ifndef __MENUITEM_HPP_
#define __MENUITEM_HPP_ /* __MENUITEM_HPP_ */

#include "button.hpp"

/**
 * \namespace li.
 */
namespace li
{
  /**
   * \brief A class implementing a menu item.
   */
  class menu_item : public button
  {
  public:
    /* CONSTRUCTORS */

    /**
     * \brief
     */
    menu_item (const color& fgc, const color& bgc);

    /**
     * \brief Copy constructor.
     * \param rhs The menu_item to copy.
     */
    menu_item (const menu_item& rhs);

    /* DESTRUCTOR */

    /**
     * Destructor for a menu_item.
     */
    ~menu_item ();

    /* OPERATORS */

    /**
     * \brief Copy assignment operator for a menu_item.
     * \param rhs The right hand side of the assignment.
     * \return The result of the assignment.
     */
    menu_item&
    operator= (const menu_item& rhs);

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

#endif /* __MENUITEM_HPP_ */

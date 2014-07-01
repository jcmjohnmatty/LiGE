/**
 * \file menuitem.cpp
 * \brief Contains the implementation of the menu item class.
 */

#include "menuitem.hpp"

namespace li
{
  menu_item::menu_item (const color& fgc, const color& bgc)
    : button (fgc, bgc)
  {
    /* Menu item specific stuff. */
  }

  menu_item::menu_item (const menu_item& rhs)
    : button (rhs)
  {
    /* Menu item specific stuff. */
  }

  menu_item::~menu_item ()
  {
  }

  menu_item&
  menu_item::operator= (const menu_item& rhs)
  {
    if (this != &rhs)
      {
        button::operator= (rhs);

        /* Menu item specific stuff. */
      }

    return *this;
  }

  void
  menu_item::draw () const
  {
  }
}

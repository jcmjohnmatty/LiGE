/**
 * \file menu.cpp
 * \brief Contains the implementation of the menu class.
 */

#include "menu.hpp"

namespace li
{
  menu::menu (/* ARGS HERE */)
    : container (/* ARGS HERE */)
  {
  }

  menu::menu (const menu& rhs)
    : container (rhs)
  {
  }

  menu::~menu ()
  {
  }

  menu&
  menu::operator= (const menu& rhs)
  {
    if (this != &rhs)
      {
        container::operator= (rhs);

        /* Menu specific stuff. */
      }

    return *this;
  }

  void
  menu::draw () const
  {
  }
}

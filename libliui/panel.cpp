/**
 * \file panel.cpp
 * \brief Contains the implementation of the panel class.
 */

#include "panel.hpp"

namespace li
{
  panel::panel (/* ARGS HERE */)
    : container (/* ARGS HERE */)
  {
    /* Panel specific stuff. */
  }

  panel::panel (const panel& rhs)
    : container (rhs)
  {
    /* Panel specific stuff. */
  }

  panel::~panel ()
  {
  }

  panel&
  panel::operator= (const panel& rhs)
  {
    if (this != &rhs)
      {
        container::operator= (rhs);

        /* Panel specific stuff. */
      }

    return *this;
  }

  void
  panel::draw () const
  {
  }
}

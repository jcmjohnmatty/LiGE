/**
 * \file layout.cpp
 * \brief Contains the implementation of the layout class.
 */

#include "container.hpp"
#include "layout.hpp"

namespace li
{
  layout::layout (/* ARGS HERE */)
    : container (/* ARGS HERE */)
  {
  }

  layout::layout (const layout& rhs)
    : container (rhs)
  {
    /* Layout specific stuff. */
  }

  layout::~layout ()
  {
  }

  layout&
  layout::operator= (const layout& rhs)
  {
    if (this != &rhs)
      {
        container::operator= (rhs);

        /* Layout specific stuff. */
      }

    return *this;
  }
}

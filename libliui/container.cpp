/**
 * \file container.cpp
 * \brief Contains the implementation of the container class.
 */

#include "container.hpp"

namespace li
{
  container::container (/* ARGS HERE */)
  {
  }

  container::container (const container& rhs)
  {
  }

  container::~container ()
  {
  }

  container&
  container::operator= (const container& rhs)
  {
    if (this != &rhs)
      {
        /* Copy stuff. */
      }

    return *this;
  }
}

/**
 * \file component.cpp
 * \brief Contains the implementation for the component class of libliui.
 */
#include "component.hpp"

namespace li
{
  component::component (const color& fgc, const color& bgc)
  {
    this->fgc = fgc;
    this->bgc = bgc;
  }

  component::component (const component& rhs)
  {
    this->fgc = rhs.fgc;
    this->bgc = rhs.bgc;
  }

  component::~component ()
  {
  }

  component&
  component::operator= (const component& rhs)
  {
    if (this != &rhs)
      {
        this->fgc = rhs.fgc;
        this->bgc = rhs.bgc;
      }

    return *this;
  }
}

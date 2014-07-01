/**
 * \file label.cpp
 * \brief Contains the implementation of the label class.
 */

#include "label.hpp"
#include <string>

namespace li
{
  label::label (const std::string& txt)
    : component (), text(txt)
  {
  }

  label::label (const label& rhs)
    : component (rhs)
  {
    /* Label specific stuff. */
    this->text = rhs.text;
  }

  label::~label ()
  {
  }

  label&
  label::operator= (const label& rhs)
  {
    if (this != &rhs)
      {
        component::operator= (rhs);

        /* Label specific stuff. */
        this->text = rhs.text;
      }

    return *this;
  }

  void
  label::draw () const
  {
  }
}

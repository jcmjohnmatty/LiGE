/**
 * \file bitmapbutton.cpp
 * \brief Contains the implementations of the bitmap button class.
 */

#include "bitmapbutton.hpp"

namespace li
{
  bitmap_button::bitmap_button (const color& fgc, const color& bgc)
    : button (fgc, bgc)
  {
  }

  bitmap_button::bitmap_button (const bitmap_button& rhs)
    : button (rhs)
  {
  }

  bitmap_button::~bitmap_button ()
  {
  }

  bitmap_button&
  bitmap_button::operator= (const bitmap_button& rhs)
  {
    if (this != &rhs)
      {
        button::operator= (rhs);

        /* Bitmap button specific stuff. */
      }

    return *this;
  }

  void
  bitmap_button::draw () const
  {
  }
}

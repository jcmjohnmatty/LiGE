/**
 * \file button.cpp
 * \brief Contains the implementation of the button class.
 */

#include <GL/gl.h>

#include "button.hpp"
#include "color.hpp"
#include "component.hpp"
#include "label.hpp"

namespace li
{
  button::button (const color& fgc, const color& bgc, const point& cl,
                  const point& cr)
    : component (fgc, bgc), blcorn (cl), trcorn (cr)
  {
    this->startx = blcorn.x;
    this->starty = blcorn.y;
    this->width = trcorn.x - brcorn.x;
    this->height = trcorn.y - brcorn.y;
  }

  button::button (const button& rhs)
   : component (rhs)
  {
    /* Button Specific. */
    this->brcorn = rhs.brcorn;
    this->trcorn = rhs.trcorn;
    this->startx = rhs.startx;
    this->starty = rhs.starty;
    this->width = rhs.width;
    this->height = rhs.height;
  }

  button::~button ()
  {
  }

  button&
  button::operator= (const button& rhs)
  {
    if (this != &rhs)
      {
        component::operator= (rhs);

        /* Button specific. */
        this->brcorn = rhs.brcorn;
        this->trcorn = rhs.trcorn;
        this->startx = rhs.startx;
        this->starty = rhs.starty;
        this->width = rhs.width;
        this->height = rhs.height;
      }

    return *this;
  }

  void
  button::draw () const
  {
    glColor4fv ((float*) &this->bgc);
    glRectf (this->startx, this->starty, this->startx + this->width,
             this->starty + this->height);
  }
}

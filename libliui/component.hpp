/**
 * \file component.hpp
 * \brief Contains the definitions for the component class of libliui.
 */

#ifndef __COMPONENT_HPP_
#define __COMPONENT_HPP_ /* __COMPONENT_HPP_ */

#include "color.hpp"

/**
 * \namespace li
 */
namespace li
{
  /**
   * \brief The base class for all libliui objects.
   */
  class component
  {
  public:
    /* CONSTRUCTORS */

    /**
     * \brief Default constructor.
     */
    component ()
    { }

    /**
     * \brief Component constructor.
     * \param fgc The foreground color for this component.
     * \param bgc The background color for this component.
     */
    component (const color& fgc, const color& bgc);

    /**
     * \brief Component copy constructor.
     * \param rhs The component to copy.
     */
    component (const component& rhs);

    /* DESTRUCTORS */

    /**
     * \brief Virtual destructor for the component class.
     */
    virtual
    ~component ();

    /* OPERATORS */

    /**
     * \brief Copy assignment operator.
     * \param rhs The component to assign to this.
     */
    component&
    operator= (const component& rhs);

    /* FUNCTIONS */

    /**
     * \brief Draw a component.
     */
    virtual void
    draw () const = 0;

  protected:
    /* VARIABLES */

    /** The foreground color. */
    color fgc;
    /** The background color. */
    color bgc;
  };
}

#endif /* __COMPONENT_HPP_ */

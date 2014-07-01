/**
 * \file container.hpp
 * \brief Contains the definitions for the container class.
 */

#ifndef __CONTAINER_HPP_
#define __CONTAINER_HPP_ /* __CONTAINER_HPP_ */

#include "component.hpp"

/**
 * \namespace li
 */
namespace li
{
  /**
   * \brief The container class.
   * This class is the base class for all classes such as layouts, panels, ...
   */
  class container : public component
  {
  public:
    /* CONSTRUCTORS */

    /**
     * \brief
     */
    container (/* ARGS HERE */);

    /**
     * \brief Copy constructor.
     * \param rhs The object to copy.
     */
    container (const container& rhs);

    /* DESTRUCTOR */

    /**
     * \brief Virtual destructor.
     */
    virtual
    ~container ();

    /* OPERATORS */

    /**
     * \brief Copy assignment operator.
     * \param rhs The right hand side of the assignment.
     * \return The result of the assignment.
     */
    container&
    operator= (const container& rhs);

    /* FUNCTIONS */

    /**
     * \brief Draw a container.
     */
    virtual void
    draw () const = 0;

  protected:
    /* VARIABLES */
  };
}

#endif /* __CONTAINER_HPP_ */

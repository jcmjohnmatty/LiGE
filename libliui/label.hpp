/**
 * \file label.hpp
 * \brief Contains the definitions for the label class.
 */

#ifndef __LABEL_HPP_
#define __LABEL_HPP_ /* __LABEL_HPP_ */

#include <string>
#include "component.hpp"

/**
 * \namespace li
 */
namespace li
{
  /**
   * \brief The label class.
   * This class is the base class for all labels.
   */
  class label : public component
  {
  public:
    /* CONSTRUCTORS */

    /**
     * \brief Construct a label from the given string.
     * \param txt The text for this label to have.
     */
    label (const std::string& txt = "");

    /**
     * \brief Copy constructor.
     * \param rhs The object to copy.
     */
    label (const label& rhs);

    /* DESTRUCTOR */

    /**
     * \brief Virtual destructor.
     */
    virtual
    ~label ();

    /* OPERATORS */

    /**
     * \brief Copy assignment operator.
     * \param rhs The right hand side of the assignment.
     * \return The result of the assignment.
     */
    label&
    operator= (const label& rhs);

    /**
     * \brief Cast this label to it's text.
     */
    operator std::string ()
    {
      return this->text;
    }

    /* FUNCTIONS */

    /**
     * \brief Draw the label.
     */
    void
    draw () const;

  protected:
    /* VARIABLES */

    /** The text for this label. */
    std::string text;
  };
}

#endif /* __LABEL_HPP_ */

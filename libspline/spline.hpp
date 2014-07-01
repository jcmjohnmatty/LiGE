#ifndef __SPLINE_HPP_
#define __SPLINE_HPP_

#include <vector>

/**
 * \namespace spline
 * \brief Implementation of various splines.
 * This namespace contains implementations of various types of splines, such as
 * Bezier splines (arbitrary degree) and B splines.
 */
namespace spline
{
  /**
   * \brief The class is the base class for all spline classes.
   * Note that all spline classes assume that they are 1 dimensional, however
   * storing 2 for 2d, 3 for 3d, etc... is perfectly reasonable to ask the user
   * to do, so I did it!
   */
  class spline
  {
  public:
    /* CONSTRUCTOR */
    spline ()
    { }

    /* DESTRUCTOR */
    virtual
    ~spline ();

    /* OPERATORS */

    /**
     * \brief Obtain the value of a spline at a given value of its paramater in
     *        the range [0, 1].
     * \param t The value of the paramater for this spline.
     * \return The value of the spline at this point.
     */
    virtual float
    operator() (float t) const = 0;

  protected:
    /* SHARED DATA */

    /**
     * \brief Construct a spline from given points.
     * \param ps_ The points.
     */
    spline (const std::vector <float>& ps_);

    /** The control "points" (1d). */
    std::vector <float> ps;
  };

  /**
   * \brief This class implements arbitrary degree Bezier splines.
   */
  class bezier : public spline
  {
  public:
    /* CONSTRUCTORS */

    /**
     * \brief Construct a bezier spline given the degree.
     * \param d_ The degree (default is 3 since people seem to like that).
     */
    bezier (unsigned int d_ = 3)
      : deg (d_)
    { }

    /**
     * \brief Construct a bezier spline given the "points" and degree.
     * \param ps_ The points to use.
     * \param d_ The degree (default 3 since people like that).
     */
    bezier (const std::vector <float>& ps_, unsigned int d_ = 3)
      : spline (ps_), deg (d_)
    { }

    /* DESTRUCTOR */
    ~bezier ()
    { }

    /* OPERATORS */

    /**
     * \see {spline::operator()}
     */
    float
    operator() (float t) const;

    /* FUNCTIONS */

    /**
     * \brief Add a control "point".
     * \param p The "point" to add.
     */
    void
    add_point (float p);

  private:
    /* VARIABLES */

    /** The degree. */
    unsigned int deg;
  };

  /**
   * \brief This class implements B splines.
   */
  /*class bspline : public spline
  {
  };*/
}

#endif // __SPLINE_HPP_

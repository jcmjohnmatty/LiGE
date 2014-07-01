#ifndef __POINT_HPP_
#define __POINT_HPP_

namespace li
{
  namespace ui
  {
    namespace util
    {
      /**
       * \brief A point.
       * These points are scaled, that is their coordinates are always \in
       * [0, 1].  This allows the proportions of things to look nice even when
       * size changes.
       */
      class point
      {
      public:
        /* CONSTRUCTORS */

        /**
         * \brief Construct a point given default coordinates.
         * \param x The x_ coordinate (default 0).
         * \param y The y_ coordinate (default 0).
         */
        point (float x_ = 0.0f, float y_ = 0.0f); 

        /**
         * \brief Copy constructor.
         * \param rhs The point to copy the data to this point of.
         */
        point (const point& rhs);

        /* DESTRUCTOR */
        virtual
        ~point ();

        /* OPERATORS */

        /**
         * \brief Copy assignment.
         * \param rhs The button to assign the data to this button of.
         * \return *this.
         */
        point&
        operator= (const point& rhs);

        /**
         * \brief Index this point.
         * \param i This index (0 is x, 1 is y).
         * \return x if i == 0 else if i == 1 y else fail horribly somehow.
         */
        float
        operator[] (int i) const;

        /**
         * \brief Index this point (allows for assignment).
         * \param i This index (0 is x, 1 is y).
         * \return x if i == 0 else if i == 1 y else fail horribly somehow.
         */
        float&
        operator[] (int i);

        /**
         * \brief Convert this point to an array of floats.
         * \return This point as an array of floats.
         *         this[0] == this.x.
         *         this[1] == this.y.
         */
        operator float* () const;

        //protected:
        /* VARIABLES */

        /** The x coordinate. */
        float x;
        /** The y coordinate. */
        float y;
      };
    }
  }
}

#endif // __POINT_HPP_

#ifndef __MESH_HPP_
#define __MESH_HPP_

#include <vector>

/**
 * \namespace mesh
 * \brief Contains all classes and functions related to mesh parsing and loading.
 */
namespace mesh
{
  /**
   * \brief A class storing all mesh data and providing some general mesh
   *        operations.
   */
  class mesh
  {
  public:
    /* CONSTRUCTORS */

    /**
     * \brief Default constructor (does nothing).
     */
    mesh ()
    { }

    /**
     * \brief Construct a mesh from the given filename.
     * \param fname The name of the file to construct the mesh from.
     */
    mesh (const char* fname)
    { read_mesh (fname); }

    /* DESTRUCTOR */
    ~mesh ();

    /* OPERATORS */

    /* FUNCTIONS */

    /**
     * \brief Render the mesh using OpenGL.
     */
    void
    draw () const;

  private:
    /* VARIABLES */

    /* MESH STORAGE */

    /** The verticies for this mesh. */
    std::vector <float> verts;
    /** The normals for this mesh. */
    std::vector <float> norms;
    /** The texture coordinates for this mesh. */
    std::vector <float> texcoords;
    /** The indices into the vertex array. */
    std::vector <unsigned short> vert_ind;
    /** The indicies into the normal array. */
    std::vector <unsigned short> norm_ind;
    /** The indicies into the texture coordinate array. */
    std::vector <unsigned short> texc_ind;

    /* GEOMETRIC PROPERTIES */

    /* FUNCTIONS */

    /**
     * \brief Helper function to construct a mesh from a given file.
     * \param fname The name of the file to read from.
     */
    void
    read_mesh (const char* fname);
  };
}

#endif // __MESH_HPP_

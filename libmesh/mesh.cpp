#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#include "mesh.hpp"

namespace mesh
{
  void
  mesh::read_mesh (const char* fname)
  {
    // File pointer.
    FILE *fp;
    // Size of obj file.
    long size = 0;
    // Amount of file read in.
    long result = 0;
    // Mesh contents.
    char* mesh;
    // The current line.
    char* line;
    // Temporary floats.
    float x;
    float y;
    float z;
    // Temp indicies.
    int vind[3];
    int tind[3];
    int nind[3];

    fp = fopen(fname, "r+");

    // If file is not valid.
    if (fp == NULL)
      {
        perror ("Error opening file");
        goto RMESH_EXIT;
        //return 1;
      }

    // If file is valid.
    else
      {
        /* Seek to the end of the file, read the size, seek to beginning and
           read. */
        fseek (fp, 0, SEEK_END);
        size = ftell (fp);
        fseek (fp, 0, SEEK_SET);

        /* Allocate memory for mesh string then read it into memory. */
        mesh = new char[size];
        result = fread (mesh, 1, size, fp);

        // Close file.
        fclose (fp);

        // Failure, return error.
        if (result != size)
          {
            fputs ("Reading error", stderr);
            goto RMESH_EXIT;
            //return 1;
          }
      }

    /* Create a tokenizer on the string, parsing line by line. */
    line = strtok (mesh, "\n\r");
    while (line != NULL)
      {
        switch (line[0])
          {

          // Comment.
          case '#':
            //printf ("%s\n", line);
            break;

          // Ignore groups.
          case 'g':
            break;

          // Ignore smoothing groups.
          case 's':
            break;

          // Per-vertex attributes.
          case 'v':
            // Vertex normal (f,f,f).
            if(line[1] == 'n')
              {
                /* Parse the float from ths string and create a vertex. */
                sscanf (line, "%*s %f %f %f", &x, &y, &z);
                norms.push_back (x);
                norms.push_back (y);
                norms.push_back (z);
                break;
              }

            // Vertex texture (f,f,f).
            else if (line[1] == 't')
              {
                /* Parse the float from ths string and create a vertex. */
                sscanf (line, "%*s %f %f %f", &x, &y, &z);
				texcoords.push_back (x);
				texcoords.push_back (y);
				texcoords.push_back (z);
                break;
              }

            // Vertex (f,f,f).
            else
              {
                /* Parse the float from ths string and create a vertex. */
                sscanf (line, "%*s %f %f %f", &x, &y, &z);
                verts.push_back (x);
                verts.push_back (y);
                verts.push_back (z);
				printf ("%f %f %f", x, y, z);
                break;
              }
            break;

          case 'f':

            /* Parse the index data for each triangle, its normal, and textrue
               coordinate (d,d,d d,d,d d,d,d). */

            // TODO I need to check which form to parse somehow.
            sscanf (line, "%*s %d/%d/%d %d/%d/%d %d/%d/%d\n",
                    &vind[0], &tind[0], &nind[0],
					&vind[1], &tind[1], &nind[1],
                    &vind[2], &tind[2], &nind[2]);

            /* Add each index to its temporary vector. */

            // TODO I need to find out how to support negative indicies.
            vert_ind.push_back (vind[0] - 1);
            vert_ind.push_back (vind[1] - 1);
            vert_ind.push_back (vind[2] - 1);

			texc_ind.push_back(tind[0]);
			texc_ind.push_back(tind[1]);
			texc_ind.push_back(tind[2]);

            norm_ind.push_back (nind[0]);
            norm_ind.push_back (nind[1]);
            norm_ind.push_back (nind[2]);

            break;
          }

        // Next line.
        line = strtok (NULL, "\n\r");
      }

  RMESH_EXIT:
    // Free the mesh's temporary data.
    delete mesh;

    //return 0;
  }

  mesh::~mesh ()
  {
    unsigned int i;
    // Clean up all the memories!!!

    /*for (i = 0; i < verts.size (); i++)
      {
        delete verts[i];
      }*/
    verts.clear ();

    /*for (i = 0; i < norms.size (); i++)
      {
        delete norms[i];
      }*/
    norms.clear ();

    /*for (i = 0; i < texcoords.size (); i++)
      {
        delete texcoords[i];
      }*/
    texcoords.clear ();

    vert_ind.clear ();
    norm_ind.clear ();
    texc_ind.clear ();
  }

  void
  mesh::draw () const
  {
    glEnableClientState (GL_VERTEX_ARRAY);
    glVertexPointer (3, GL_FLOAT, 0, &verts[0]);

    //glPushMatrix ();

    glPolygonMode (GL_FRONT, GL_LINE);
    glPolygonMode (GL_BACK, GL_LINE);

    glColor4f (1.0,0.0,0.0,1.0);

    glDrawElements (GL_TRIANGLES, vert_ind.size (), GL_UNSIGNED_SHORT,
                    &vert_ind[0]);

    glPolygonMode (GL_FRONT, GL_FILL);
    glPolygonMode (GL_BACK, GL_FILL);

    //glPopMatrix ();

    glDisableClientState (GL_VERTEX_ARRAY);
  }
}

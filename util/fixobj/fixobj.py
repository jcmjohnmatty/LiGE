# This scripy will take two passes.  Although it will take longer that way, it
# will also save memory since all of the verticies for a possibly very complex
# mesh will not need to be stored.
#
# read in the mesh, finding the verticies with the minimum z values (these make
# up th lowest "slice" in the mesh".  If you find a vertex with a z value within
# a given tolerance of the current minumum(s), then add it to that list.
#
# If you find a vertex whose z value is less than those of the current minimum,
# replace that set with the new vertex and keep on looking.
#
# After this, we hae all of the verticies that make up the lowest slice of the
# mesh.  We then average the x and y coordinates, giving us the center of the
# lowest slice in the mesh.  This gives us the minimum point that is in the
# center of te bottom of the mesh.  This completes the first pass.
#
# On the second pass, subtract the x,y,z values of the minimum point found above
# from those of the current vertex being read.  This moves the mesh so that the
# center of its bottom will be centered on the origin.  This is a *nice* way for
# a mesh to be stored, however since not all programs do this I wrote a script
# to do that preprocessing on the mesh in case it has not been done already.

import argparse
import sys

minvs = []

# create arugment parser
parser = argparse.ArgumentParser(prog="__CHANGETASK__",
                                 description="center the bottom of an obj mesh"
                                 + " on the origin")
parser.add_argument("-f", "--file", nargs=1, help="the mesh whose bottom to"
                    + " center on the origin")

# @brief Main function for the fixobj utility.
def main():
    args = vars(parser.parse_args(sys.argv))
    fname = None
    if "-f" in args:
        fname = args["-f"]
    elif "--file" in args:
        fname = args["--file"]
    else:
        return

# Run it!!!
if __name__ == '__main__':
    main()

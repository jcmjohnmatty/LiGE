CXX       = g++
CXXFLAGS  = -fPIC -O3 -Wall -Wextra -g
INC       = -I/usr/local/include -I/usr/local/lib/include -I. -I../core
LIBS      = -L/usr/local/lib -lm
GLLIBS    = -lGL -lGLU -lglut
PROGRAM   = test
OBJS      = spline.o test.o

$(PROGRAM): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(PROGRAM) $(LIBS) $(GLLIBS)

spline.o: spline.cpp spline.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c spline.cpp -o spline.o $(LIBS) $(GLLIBS)

test.o: test.cpp spline.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c test.cpp -o test.o $(LIBS) $(GLLIBS)

.PHONY:
clean:
	/bin/rm -f $(OBJS)
	/bin/rm -f $(PROGRAM)
	/bin/rm -f core

CXX       = g++
CXXFLAGS  = -g -O0 -Wall
INC      = -I/usr/local/include -I/usr/local/lib/include
LIBS     = -L/usr/local/lib -lm
GLLIBS   = -lGL -lGLU -lglut
PROGRAM  = test
LIBLIUI  = ../libliui-0.0.0.a
OBJS     = glmain.o $(LIBLIUI)

$(PROGRAM): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(PROGRAM) $(LIBS) $(GLLIBS) $(LIBLIUI)

$(LIBLIUI):
	$(MAKE) -C ..

glmain.o: glmain.cpp ../button.hpp glmain.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c glmain.cpp -o glmain.o $(LIBS) $(GLLIBS)

.PHONY:
clean:
	/bin/rm -f $(OBJS)
	/bin/rm -f $(PROGRAM)
	/bin/rm -f core

AR        = ar
ARFLAGS   = rcs
CXX       = g++
CXXFLAGS  = -fPIC -O3 -Wall -Wextra
INC       = -I/usr/local/include -I/usr/local/lib/include
LIBS      = -L/usr/local/lib
GLLIBS    = -lGL -lGLU -lglut
STATICL  = libliui-0.0.0.a
STATICLL  = libliui.a
SHAREDL   = libliui.so.0.0.0
SHAREDLL  = libliui.so
OBJS      = bitmapbutton.o button.o color.o component.o container.o label.o \
			layout.o menu.o menuitem.o panel.o

# Build the libraries.

.PHONY:
all: $(STATICLL) $(SHAREDLL)

$(STATICLL): $(STATICL)

$(STATICL): $(OBJS)
	$(AR) $(ARFLAGS) $(STATICL) $(OBJS)

$(SHAREDLL): $(SHAREDL)

$(SHAREDL): $(OBJS)
	$(CXX) -shared -Wl,-soname,$(SHAREDL) -o $(SHAREDL) $(OBJS)

# Now build the actual object files.

bitmapbutton.o: bitmapbutton.cpp bitmapbutton.hpp button.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c bitmapbutton.cpp -o bitmapbutton.o $(LIBS) \
	$(GLLIBS)

button.o: button.cpp button.hpp color.hpp component.hpp label.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c button.cpp -o button.o $(LIBS) $(GLLIBS)

color.o: color.cpp color.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c color.cpp -o color.o $(LIBS) $(GLLIBS)

component.o: component.cpp color.hpp component.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c component.cpp -o component.o $(LIBS) $(GLLIBS)

container.o: container.cpp component.hpp container.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c container.cpp -o container.o $(LIBS) $(GLLIBS)

label.o: label.cpp component.hpp label.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c label.cpp -o label.o $(LIBS) $(GLLIBS)

layout.o: layout.cpp container.hpp layout.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c layout.cpp -o layout.o $(LIBS) $(GLLIBS)

menu.o: menu.cpp container.hpp menu.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c menu.cpp -o menu.o $(LIBS) $(GLLIBS)

menuitem.o: menuitem.cpp button.hpp menuitem.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c menuitem.cpp -o menuitem.o $(LIBS) $(GLLIBS)

panel.o: panel.cpp container.hpp panel.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c panel.cpp -o panel.o $(LIBS) $(GLLIBS)

.PHONY:
clean:
	/bin/rm -f $(OBJS)
	/bin/rm -f $(PROGRAM)
	/bin/rm -f core

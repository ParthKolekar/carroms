OBJ = carrom
override CFLAGS += -Ofast -funroll-loops -flto -Wall -std=c++11 -static
override DEVEL_FLAGS += -g -Wall -Wextra -pedantic-errors -std=c++11 
override DEBUG_FLAGS += -DDEBUG
override LFLAGS += -lglut -lGL -lGLU -lpthread
CXX ?= g++
PREFIX ?= /usr/local
BINDIR = $(PREFIX)/bin
CXXFILES = BoundingBoard.cpp Coin.cpp GenericCollidingChip.cpp GenericObject.cpp main.cpp Particles.cpp Player.cpp Pocket.cpp Striker.cpp
OBJFILES = $(patsubst %.cpp,%.o,$(CXXFILES))

$(OBJ) : $(OBJFILES)
	$(CXX) $(DEVEL_FLAGS) $^ -o $@ $(LFLAGS)

%.o : %.cpp
	$(CXX) $(DEVEL_FLAGS) -c $^

clean :
	rm -f *.o $(OBJ)

clear : clean

debug: clear
	$(CXX) $(DEVEL_FLAGS) $(DEBUG_FLAGS) -c $(CXXFILES)
	$(CXX) $(DEVEL_FLAGS) $(DEBUG_FLAGS) -o $(OBJ) $(OBJFILES) $(LFLAGS)

ofast : clear
	$(CXX) $(CFLAGS) -c $(CXXFILES)
	$(CXX) $(CFLAGS) -o $(OBJ) $(OBJFILES) $(LFLAGS)

install : $(OBJ)
	@echo "Installing program to $(DESTDIR)$(BINDIR) ..."
	@mkdir -p $(DESTDIR)$(BINDIR)
	@install -pm0755 $(OBJ) $(DESTDIR)$(BINDIR)/$(TARGET) || \
		echo "Failed. Try "make PREFIX=~ install" ?"

all : install

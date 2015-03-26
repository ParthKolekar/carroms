OBJ = carrom
override CFLAGS += -Ofast -funroll-loops -flto -Wall -std=c++11
override DEVEL_FLAGS += -g -Wall -Wextra -pedantic-errors -std=c++11 
override DEBUG_FLAGS += -DDEBUG
override LFLAGS += -lglut -lGL -lGLU
CXX ?= g++
PREFIX ?= /usr/local
BINDIR = $(PREFIX)/bin

%.o : %.cpp
	$(CXX) $(DEVEL_FLAGS) -c $^

$(OBJ) : *.o
	$(CXX) $(DEVEL_FLAGS) $^ -o $@ $(LFLAGS)

clean :
	rm -f *.o $(OBJ)

clear : clean

debug: clear
	$(CXX) $(DEVEL_FLAGS) $(DEBUG_FLAGS) -c *.cpp
	$(CXX) $(DEVEL_FLAGS) $(DEBUG_FLAGS) -o $(OBJ) *.o $(LFLAGS)

ofast : clear
	$(CXX) $(CFLAGS) -c *.cpp
	$(CXX) $(CFLAGS) -o $(OBJ) *.o $(LFLAGS)

install : $(OBJ)
	@echo "Installing program to $(DESTDIR)$(BINDIR) ..."
	@mkdir -p $(DESTDIR)$(BINDIR)
	@install -pm0755 $(OBJ) $(DESTDIR)$(BINDIR)/$(TARGET) || \
		echo "Failed. Try "make PREFIX=~ install" ?"

all : install

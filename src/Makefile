OBJ = carrom
MAN = carrom.1
override CFLAGS += -Ofast -funroll-loops -flto -Wall -std=c++11
override DEVEL_FLAGS += -g -Wall -Wextra -pedantic-errors -std=c++11 
override DEBUG_FLAGS += -DDEBUG
override LFLAGS += -lglut -lGL -lGLU
CC = g++
PREFIX ?= /usr/local
BINDIR = $(PREFIX)/bin
MANDIR = $(PREFIX)/share/man/man1

$(OBJ) : *.o
	$(CC) $(DEVEL_FLAGS) $^ -o $@ $(LFLAGS)

%.o : %.cpp
	$(CC) $(DEVEL_FLAGS) -c $^

clean :
	rm -f *.o $(OBJ)

clear : clean

debug: clear
	$(CC) $(DEVEL_FLAGS) $(DEBUG_FLAGS) -c *.cpp
	$(CC) $(DEVEL_FLAGS) $(DEBUG_FLAGS) -o $(OBJ) *.o $(LFLAGS)

ofast : clear
	$(CC) $(CFLAGS) -c *.cpp
	$(CC) $(CFLAGS) -o $(OBJ) *.o $(LFLAGS)

install : $(OBJ)
	@echo "Installing program to $(DESTDIR)$(BINDIR) ..."
	@mkdir -p $(DESTDIR)$(BINDIR)
	@install -pm0755 $(OBJ) $(DESTDIR)$(BINDIR)/$(TARGET) || \
		echo "Failed. Try "make PREFIX=~ install" ?"
	@echo "Installing manpage to $(DESTDIR)$(MANDIR) ..."
	@mkdir -p $(DESTDIR)$(MANDIR)
	@install -pm0644 $(MAN) $(DESTDIR)$(MANDIR)/ || \
		echo "Failed. Try "make PREFIX=~ install" ?"

all : install

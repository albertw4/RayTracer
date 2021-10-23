# This is an example Makefile for a program with
# the following structure:
# h1.hpp   h1.cpp   h2.hpp   h2.cpp   main.cpp
# - main.cpp defines a main function
# - h1.cpp includes h1.hpp
# - h2.cpp includes h2.hpp
# - main.cpp includes both h1.hpp and h2.hpp 

CC			= g++					# Designates the compiler	
CFLAGS		= -std=c++17			# Flag for C++ version
LDFLAGS 	=						# Area for other flags (we will not use this)
OBJFILES 	= main.o Point.o Vector.o Ray.o Sphere.o PGMOut.o Raytracer.o		# List of .o files (for linking)
TARGET 		= a.out					# Name of compiled executable					

all: $(TARGET)						# Main rule to compile
									# invoked by typing "make"
$(TARGET): $(OBJFILES)			
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:								# Rule for removing temporary files
	rm $(OBJFILES) $(TARGET)		# invoked by typing "make clean"
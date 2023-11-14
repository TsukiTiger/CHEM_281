# Makefile for hw3.1 and hw3.2

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -I. -std=c++11

# Executable names
EXEC1 = hw3.1
EXEC2 = hw3.2

# Source files for each executable
SOURCES1 = hw3.1_impl.cpp hw3.1_main.cpp
SOURCES2 = hw3.2.cpp

# Object files for each executable
OBJECTS1 = $(SOURCES1:.cpp=.o)
OBJECTS2 = $(SOURCES2:.cpp=.o)

# Default target
all: $(EXEC1) $(EXEC2)

# Build hw3.1
$(EXEC1): $(OBJECTS1)
	$(CXX) -o $(EXEC1) $(OBJECTS1)

# Build hw3.2
$(EXEC2): $(OBJECTS2)
	$(CXX) -o $(EXEC2) $(OBJECTS2)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJECTS1) $(OBJECTS2) $(EXEC1) $(EXEC2)

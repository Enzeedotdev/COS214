# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Target executable
TARGET = eventflow

# Source files
SRCS = main.cpp \
       FestivalComponent.cpp \
       FestivalObserver.cpp \
       FestivalGroup.cpp

# Header files (for dependency tracking)
HDRS = FestivalComponent.h \
       FestivalObserver.h \
       FestivalGroup.h

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile each .cpp file into .o
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -f $(OBJS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Phony targets (not real files)
.PHONY: all clean run docs
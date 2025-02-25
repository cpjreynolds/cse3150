CXXFLAGS=-Wall -g --std=c++17

TARGET=ex1.out

SOURCES:=$(wildcard *.cpp)
OBJECTS:=$(SOURCES:.cpp=.o)

.PHONY: all clean check

all: $(TARGET)

check: all
	./$(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@


clean:
	rm -f \
		$(OBJECTS)	\
		$(TARGET)

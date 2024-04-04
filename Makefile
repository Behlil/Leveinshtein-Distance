CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

SRCS := $(wildcard src/*.cpp)
OBJS := $(SRCS:.cpp=.o)

TEST_SRCS := $(wildcard tests/*.cpp)
TEST_OBJS := $(TEST_SRCS:.cpp=.o)

INCLUDES := -Iinclude

EXEC = main_program
TEST_EXEC = unit_tests

.PHONY: all clean test

all: $(EXEC)

$(EXEC): $(OBJS)
    $(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

test: $(TEST_EXEC)
    ./$<

$(TEST_EXEC): $(filter-out src/main_code.o, $(OBJS)) $(TEST_OBJS)
    $(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

%.o: %.cpp
    $(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

clean:
    rm -f $(EXEC) $(OBJS) $(TEST_EXEC) $(TEST_OBJS)

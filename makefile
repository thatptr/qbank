CXX = clang++
CXXFLAGS = -std=c++14 -Wall -Wextra -Werror
LDFLAGS = -lgtest -lgtest_main -pthread

SRCDIR = src
TESTDIR = test
BUILDDIR = build
BINDIR = bin

SRC = $(wildcard $(SRCDIR)/*.cpp)
TESTSRC = $(wildcard $(TESTDIR)/*.cpp)
OBJ = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRC))
TESTOBJ = $(patsubst $(TESTDIR)/%.cpp,$(BUILDDIR)/%.o,$(TESTSRC))

TARGET = $(BINDIR)/unittest

all: $(TARGET)

$(TARGET): $(OBJ) $(TESTOBJ)
	$(CXX) $^ -o $@ $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(BUILDDIR)/%.o: $(TESTDIR)/%.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

.PHONY: clean

clean:
	rm -rf $(BUILDDIR)/* $(BINDIR)/*

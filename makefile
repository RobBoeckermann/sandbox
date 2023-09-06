CC = g++
CPPFLAGS = -g -Wall
SRCDIR = cpp


SRCS = $(wildcard $(SRCDIR)/*.cpp)
EXECS = $(patsubst $(SRCDIR)/%.cpp,%,$(SRCS))

all: $(EXECS)

$(EXECS): %: $(SRCDIR)/%.cpp
	$(CC) $(CPPFLAGS) -o $(SRCDIR)/$@ $<

clean:
	$(RM) $(SRCDIR)/$(EXECS)

LEX = flex
YACC = bison

CXXFLAGS = -Wall -Wextra -Wpedantic

ifeq ($(DEBUG),1)
 YFLAGS = --debug
 CXXFLAGS += -Og -g -fsanitize=address -fsanitize=undefined
else
 CXXFLAGS += -O3
endif

ifeq ($(COUNTEREXAMPLES),1)
 YFLAGS += -Wcounterexamples
endif

all: lexical.cpp lexical.h syntactic.cpp syntactic.h

lexical.cpp: lexical.l syntactic.h
	$(LEX) --outfile=lexical.cpp $<

syntactic.cpp syntactic.h: syntactic.y
	$(YACC) --output=syntactic.cpp --defines=syntactic.h $(YFLAGS) $<

test: main.cpp code-reader.cpp lexical.cpp syntactic.cpp ../dynamic-pattern-load-cue.cpp ../sprite-frame.cpp ../sprite-piece.cpp ../common.cpp
	$(CXX) -std=c++17 -Iflex $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LIBS) $^ -o $@

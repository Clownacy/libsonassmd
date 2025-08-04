LEX = flex
YACC = bison

CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++20

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

lexical.cpp lexical.h: lexical.l syntactic.h
	$(LEX) --outfile=lexical.cpp --header-file=lexical.h $<

syntactic.cpp syntactic.h: syntactic.y
	$(YACC) --output=syntactic.cpp --defines=syntactic.h $(YFLAGS) $<

test: main.cpp lexical.cpp syntactic.cpp ../sprite-frame.cpp ../sprite-piece.cpp ../common.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LIBS) $^ -o $@

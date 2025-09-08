.PHONY : all run clean 

CXX = g++
CXXFLAGS = -Wall -Wextra

NAMEEXE := main
OBJFILES := build/main.o build/HashlineClass.o

all: $(NAMEEXE)

run: $(NAMEEXE)
	./$(NAMEEXE)

$(NAMEEXE) : $(OBJFILES)
	$(CXX) $(OBJFILES) -o $@  $(LFLAGS) 

build/%.o : src/%.cpp
	@mkdir -p build
	$(CXX) $< -c -o $@ $(CXXFLAGS)

clean: 
	rm -f $(NAMEEXE) build/*.o

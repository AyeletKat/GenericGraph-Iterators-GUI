
#Email adress: ayeletk03@gmail.com
#ID: 325408409

CXX = g++
CXXFLAGS = -std=c++11 -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = tree

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

valgrind: tree #test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./tree 2>&1 | { egrep "lost| at " || true; }
	
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f %.o $(EXEC)

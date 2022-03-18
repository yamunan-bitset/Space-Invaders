CXX        = g++
LINKERLIBS = -lSDL
CXXFLAGS   = -std=c++17 -g
OBJS       = quickcg.o main.o
OUT        = space-invaders

all: $(OBJS)
	$(CXX) $(LINKERLIBS) $(CXXFLAGS) -o $(OUT) $(OBJS)

clean:
	rm -rf $(OBJS) $(OUT)
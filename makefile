CXX=g++
CPPFLAGS=-g -Wall
LDFLAGS=-g

PROGRAM_NAME=game
SRCS=main.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

$(PROGRAM_NAME): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(PROGRAM_NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $<

clean:
	rm $(PROGRAM_NAME)
	rm $(OBJS)

run: $(PROGRAM_NAME)
	./$(PROGRAM_NAME)

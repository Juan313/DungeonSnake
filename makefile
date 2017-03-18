CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors 
CXXFLAGS += -g
LDFLAGS = -lboost_date_time


OBJS = kbhit.o snake.o space.o game.o main.o

SRCS = kbhit.cpp snake.cpp space.cpp game.cpp main.cpp

HEADERS = kbhit.hpp snake.hpp space.hpp game.hpp 

final: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o final

${OBJS}:${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
clean:
	rm *o final

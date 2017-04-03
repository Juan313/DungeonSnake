CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors 
CXXFLAGS += -g
LDFLAGS = -lboost_date_time


OBJS = kbhit.o snake.o space.o game.o main.o ldungeon.o cdungeon.o sdungeon.o menu.o input.o

SRCS = kbhit.cpp snake.cpp space.cpp game.cpp main.cpp ldungeon.cpp cdungeon.cpp sdungeon.cpp menu.cpp input.cpp

HEADERS = kbhit.hpp snake.hpp space.hpp game.hpp ldungeon.hpp cdungeon.hpp sdungeon.hpp menu.hpp input.hpp 

final: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o final

${OBJS}:${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
clean:
	rm *o final

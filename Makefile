PROJECT = project1
CC = g++

OBJS = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
LFLAGS = -g -o $(PROJECT)

$(PROJECT) : $(OBJS)
	$(CC) $(OBJS) $(LFLAGS)

clean:
	rm *.o
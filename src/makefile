CC = g++
CFLAGS = -Wall -g -std=c++11


INCLUDES = -I../include
LFLAGS = 
LIBS = 
#-lmylib -lm

SRCS = main.cpp deck.cpp


OBJS = $(SRCS:.c=.o)

MAIN = probabiltyProgram

.PHONY: depend clean

all:    $(MAIN)
		$(MESSAGE)

$(MESSAGE):
		  @echo  Done!\n	

$(MAIN): $(OBJS) 
		$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
		$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
		$(RM) *.o *~ $(MAIN)
		$(RM) -r *.dSYM
		$(RM) *.exe 

depend: $(SRCS)
		makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it

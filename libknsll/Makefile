CFLAGS += -c -W -Wall

ifdef debug
	CFLAGS += -DDEBUG -ggdb
else
	CFLAGS += -Werror -O3
endif

knsll.o: knsllnode.o knsll.c
	${CC} ${CFLAGS} knsll.c -o $@

knsllnode.o: knsllnode.c 
	${CC} ${CFLAGS} $< -o $@

clean:
	${RM} *.o *.out

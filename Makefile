CFLAGS += -W -Wall

ifdef debug
	CFLAGS += -DDEBUG -ggdb
else
	CFLAGS += -Werror -O3
endif

EXE = sll-test
listdir = libknsll
list = ${listdir}/knsll.o ${listdir}/knsllnode.o

${EXE}: knsll.o testfuncs.o ${EXE}.o
	${CC} ${CFLAGS} ${list} ${EXE}.o testfuncs.o ${OUTPUT_OPTION}

knsll.o:  
	cd ${listdir}; ${MAKE} $@ "debug=${debug}"

run: ${EXE}
	./$<

gdbrun: ${EXE}
	gdb ./$<

clean:
	${RM} *.o *.out ${EXE}; cd ${incdir}; ${MAKE} clean

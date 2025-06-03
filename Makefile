VERSION_ = "1.0"
VERLANG_LOGS_ = 1

VERSION_ ?= "UNDEFINED"
VERLANG_LOGS_ ?= 0

all: verl

types.o: types.c types.h
	gcc -c types.c -o bin/types.o

vnode.o: vnode.c vnode.h
	gcc -c vnode.c -o bin/vnode.o

lexer.o: lexer.c lexer.h
	gcc -c lexer.c -o bin/lexer.o

parser.o: parser.c parser.h
	gcc -c parser.c -o bin/parser.o

verl.o: verl.c
	gcc -c verl.c -o bin/verl.o -D'VERSION=$(VERSION_)' -D'VERLANG_LOGS=$(VERLANG_LOGS_)'

verl: types.o vnode.o lexer.o verl.o parser.o
	gcc -o verl bin/types.o bin/vnode.o bin/lexer.o bin/parser.o bin/verl.o

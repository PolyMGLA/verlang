VERSION_ = "1.3"
VERLANG_LOGS_ = 1

VERSION_ ?= "UNDEFINED"
VERLANG_LOGS_ ?= 0

all: prepare verl

prepare:
	mkdir -p bin

types.o: types.c types.h
	gcc -c types.c -o bin/types.o -D'VERLANG_LOGS=$(VERLANG_LOGS_)'

exceptions.o: exceptions.c exceptions.h
	gcc -c exceptions.c -o bin/exceptions.o -D'VERLANG_LOGS=$(VERLANG_LOGS_)'

vnode.o: vnode.c vnode.h
	gcc -c vnode.c -o bin/vnode.o -D'VERLANG_LOGS=$(VERLANG_LOGS_)'

lexer.o: lexer.c lexer.h
	gcc -c lexer.c -o bin/lexer.o -D'VERLANG_LOGS=$(VERLANG_LOGS_)'

parser.o: parser.c parser.h
	gcc -c parser.c -o bin/parser.o -D'VERLANG_LOGS=$(VERLANG_LOGS_)'

verl.o: verl.c
	gcc -c verl.c -o bin/verl.o -D'VERSION=$(VERSION_)' -D'VERLANG_LOGS=$(VERLANG_LOGS_)'

verl: types.o exceptions.o vnode.o lexer.o verl.o parser.o
	gcc -o verl bin/types.o bin/exceptions.o bin/vnode.o bin/lexer.o bin/parser.o bin/verl.o

# Definiciones Macro para una aplicación "estándar".
#
# Definición de flags de compilación
FLAGS=-g -DDEBUG -std=c++11 
#
# comandos para la compilación
.SUFFIXES: .cpp .c .h .o
.c.o: ; cc $(FLAGS) -c $*.c
.cc.o: ; gcc $(FLAGS) -c $*.cc
.cpp.o: ; g++  $(FLAGS) -c $*.cpp
#
# Tareas
all: MyTimerTest

MyTimerTest: MyListener.o MyTimer.o MyTimerTest.o
	g++ -std=c++11 -pthread -o MyTimerTest MyListener.o MyTimer.o MyTimerTest.o
   
MyListener.o: MyListener.h MyListener.cpp

MyTimer.o: MyTimer.h MyTimer.cpp

MyTimerTest.o: MyTimerTest.cpp

clean:
	rm *.o

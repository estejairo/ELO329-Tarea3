INPUTFILE = entrada.txt

CPP_SRCS += \
./MyTimer.cpp \
./SemaforoDeGiro.cpp \
./DetectorDeRequerimiento.cpp \
./SimuladorEntradas.cpp \
./Controlador.cpp \
./TestStage3.cpp 

OBJS += \
./MyTimer.o \
./SemaforoDeGiro.o \
./DetectorDeRequerimiento.o \
./SimuladorEntradas.o \
./Controlador.o \
./TestStage3.o 

CPP_DEPS += \
./MyTimer.d \
./SemaforoDeGiro.d \
./DetectorDeRequerimiento.d \
./SimuladorEntradas.d \
./Controlador.d \
./TestStage3.d 


%.o: ./%.cpp
	g++ -std=gnu++11 -c -MMD -MP -MF "$(@:%.o=%.d)" -MT "$(@)" -o "$@" "$<"
	@echo $< "compilado sin problemas."

all: TestStage3

run: all
	./TestStage3.out $(INPUTFILE)
	@echo "Programa ejecutado sin problemas."

TestStage3: $(OBJS) 
	g++ -pthread -o TestStage3.out $(OBJS) 
	@echo $@ "compilado sin problemas."

clean:
	rm $(OBJS) $(CPP_DEPS) TestStage2.out
	@echo "Archivos eliminados."
	
INPUTFILE = entrada.txt

CPP_SRCS += \
./MyTimer.cpp \
./TrafficLight.cpp \
./StreetTrafficLight.cpp \
./SemaforoP.cpp \
./SemaforoDeGiro.cpp \
./DetectorDeRequerimiento.cpp \
./SimuladorEntradas.cpp \
./Controlador.cpp \
./TestStage4.cpp 

OBJS += \
./MyTimer.o \
./TrafficLight.o \
./StreetTrafficLight.o \
./SemaforoP.o \
./SemaforoDeGiro.o \
./DetectorDeRequerimiento.o \
./SimuladorEntradas.o \
./Controlador.o \
./TestStage4.o 

CPP_DEPS += \
./MyTimer.d \
./TrafficLight.d \
./StreetTrafficLight.d \
./SemaforoP.d \
./SemaforoDeGiro.d \
./DetectorDeRequerimiento.d \
./SimuladorEntradas.d \
./Controlador.d \
./TestStage4.d 


%.o: ./%.cpp
	g++ -std=gnu++11 -c -MMD -MP -MF "$(@:%.o=%.d)" -MT "$(@)" -o "$@" "$<"
	@echo $< "compilado sin problemas."

all: TestStage4

run: all
	./TestStage4.out $(INPUTFILE)
	@echo "Programa ejecutado sin problemas."

TestStage4: $(OBJS) 
	g++ -pthread -o TestStage4.out $(OBJS) 
	@echo $@ "compilado sin problemas."

clean:
	rm $(OBJS) $(CPP_DEPS) TestStage2.out
	@echo "Archivos eliminados."
	
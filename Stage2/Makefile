CPP_SRCS += \
./MyTimer.cpp \
./SemaforoP.cpp \
./DetectorDeRequerimiento.cpp \
./SimuladorEntradas.cpp \
./Controlador.cpp \
./TestStage2.cpp 

OBJS += \
./MyTimer.o \
./SemaforoP.o \
./DetectorDeRequerimiento.o \
./SimuladorEntradas.o \
./Controlador.o \
./TestStage2.o 

CPP_DEPS += \
./MyTimer.d \
./SemaforoP.d \
./DetectorDeRequerimiento.d \
./SimuladorEntradas.d \
./Controlador.d \
./TestStage2.d 


%.o: ./%.cpp
	g++ -std=gnu++11 -c -MMD -MP -MF "$(@:%.o=%.d)" -MT "$(@)" -o "$@" "$<"
	@echo $< "compilado sin problemas."

all: TestStage2

run: all
	./TestStage2.out $(N) $(REDTIME)
	@echo "Programa ejecutado sin problemas."

TestStage2: $(OBJS) 
	g++ -pthread -o TestStage2.out $(OBJS) 
	@echo $@ "compilado sin problemas."

clean:
	rm $(OBJS) $(CPP_DEPS) TestStage2.out
	@echo "Archivos eliminados."
	
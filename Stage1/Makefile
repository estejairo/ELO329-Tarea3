N = 120

REDTIME = 6

CPP_SRCS += \
./TrafficLight.cpp \
./StreetTrafficLight.cpp \
./TestStage1.cpp 

OBJS += \
./TrafficLight.o \
./StreetTrafficLight.o \
./TestStage1.o

CPP_DEPS += \
./TrafficLight.d \
./StreetTrafficLight.d \
./TestStage1.d 

%.o: ./%.cpp
	g++ -std=gnu++11 -c -MMD -MP -MF "$(@:%.o=%.d)" -MT "$(@)" -o "$@" "$<"
	@echo $< "compilado sin problemas."

all: TestStage1

run: all
	./TestStage1.out $(N) $(REDTIME)
	@echo "Programa ejecutado sin problemas."

TestStage1: $(OBJS) 
	g++ -pthread -o TestStage1.out $(OBJS) 
	@echo $@ "compilado sin problemas."

clean:
	rm $(OBJS) $(CPP_DEPS) TestStage1.out
	@echo "Archivos eliminados."
	
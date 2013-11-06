################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ConcreteStates.cpp \
../Context.cpp \
../Dice.cpp \
../GameContext.cpp \
../Main.cpp 

OBJS += \
./ConcreteStates.o \
./Context.o \
./Dice.o \
./GameContext.o \
./Main.o 

CPP_DEPS += \
./ConcreteStates.d \
./Context.d \
./Dice.d \
./GameContext.d \
./Main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\eclipse\boost_1_54_0" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



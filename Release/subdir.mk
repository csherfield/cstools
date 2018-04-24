################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CMatrix.cpp \
../Complex.cpp \
../Maths.cpp \
../RootFinding.cpp \
../Vector.cpp 

OBJS += \
./CMatrix.o \
./Complex.o \
./Maths.o \
./RootFinding.o \
./Vector.o 

CPP_DEPS += \
./CMatrix.d \
./Complex.d \
./Maths.d \
./RootFinding.d \
./Vector.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/TI1/Source/TI1_Program.c 

OBJS += \
./MCAL/TI1/Source/TI1_Program.o 

C_DEPS += \
./MCAL/TI1/Source/TI1_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/TI1/Source/%.o: ../MCAL/TI1/Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


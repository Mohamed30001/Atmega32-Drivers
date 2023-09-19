################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/WDT/Source/subdir.mk
-include MCAL/UART/Source/subdir.mk
-include MCAL/TWI/Source/subdir.mk
-include MCAL/TI2/Source/subdir.mk
-include MCAL/TI1/Source/subdir.mk
-include MCAL/TI0/Source/subdir.mk
-include MCAL/SPI/Source/subdir.mk
-include MCAL/GIE/Source/subdir.mk
-include MCAL/EXTI/Source/subdir.mk
-include MCAL/DIO/Source/subdir.mk
-include MCAL/ADC/Source/subdir.mk
-include HAL/Stepper/Source/subdir.mk
-include HAL/SevSeg/Source/subdir.mk
-include HAL/Servo/Source/subdir.mk
-include HAL/Motor/Source/subdir.mk
-include HAL/Led/Source/subdir.mk
-include HAL/Lcd/Source/subdir.mk
-include HAL/Kpd/Source/subdir.mk
-include FreeRTOS/subdir.mk
-include Application/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
DriversRepo.lss \

FLASH_IMAGE += \
DriversRepo.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: DriversRepo.elf secondary-outputs

# Tool invocations
DriversRepo.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,DriversRepo.map -mmcu=atmega32 -o "DriversRepo.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

DriversRepo.lss: DriversRepo.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S DriversRepo.elf  >"DriversRepo.lss"
	@echo 'Finished building: $@'
	@echo ' '

DriversRepo.hex: DriversRepo.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex DriversRepo.elf  "DriversRepo.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: DriversRepo.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 DriversRepo.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) DriversRepo.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

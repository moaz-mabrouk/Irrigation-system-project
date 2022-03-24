################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/WD_TIMER/subdir.mk
-include MCAL/USART/subdir.mk
-include MCAL/TIMERS/TIMER1/subdir.mk
-include MCAL/TIMERS/TIMER0/subdir.mk
-include MCAL/SPI/subdir.mk
-include MCAL/I2C/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/SVN_SEGMENTS/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KPAD/subdir.mk
-include HAL/H_BRIDGE/subdir.mk
-include HAL/EEPROM/subdir.mk
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
Irrigation_system.lss \

FLASH_IMAGE += \
Irrigation_system.hex \

EEPROM_IMAGE += \
Irrigation_system.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Irrigation_system.elf secondary-outputs

# Tool invocations
Irrigation_system.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Irrigation_system.map -mmcu=atmega32 -o "Irrigation_system.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Irrigation_system.lss: Irrigation_system.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Irrigation_system.elf  >"Irrigation_system.lss"
	@echo 'Finished building: $@'
	@echo ' '

Irrigation_system.hex: Irrigation_system.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Irrigation_system.elf  "Irrigation_system.hex"
	@echo 'Finished building: $@'
	@echo ' '

Irrigation_system.eep: Irrigation_system.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Irrigation_system.elf  "Irrigation_system.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Irrigation_system.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Irrigation_system.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Irrigation_system.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/SVN_SEGMENTS/SvnSeg_porg.c 

OBJS += \
./HAL/SVN_SEGMENTS/SvnSeg_porg.o 

C_DEPS += \
./HAL/SVN_SEGMENTS/SvnSeg_porg.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/SVN_SEGMENTS/%.o: ../HAL/SVN_SEGMENTS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



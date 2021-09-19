################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MICROCONTORLLER1/MCAL/USART/subdir.mk
-include MICROCONTORLLER1/MCAL/SPI/subdir.mk
-include MICROCONTORLLER1/MCAL/DIO/subdir.mk
-include MICROCONTORLLER1/subdir.mk
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
PROJ-MASTER.lss \

FLASH_IMAGE += \
PROJ-MASTER.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: PROJ-MASTER.elf secondary-outputs

# Tool invocations
PROJ-MASTER.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,PROJ-MASTER.map -mmcu=atmega32 -o "PROJ-MASTER.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

PROJ-MASTER.lss: PROJ-MASTER.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S PROJ-MASTER.elf  >"PROJ-MASTER.lss"
	@echo 'Finished building: $@'
	@echo ' '

PROJ-MASTER.hex: PROJ-MASTER.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex PROJ-MASTER.elf  "PROJ-MASTER.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: PROJ-MASTER.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 PROJ-MASTER.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) PROJ-MASTER.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets

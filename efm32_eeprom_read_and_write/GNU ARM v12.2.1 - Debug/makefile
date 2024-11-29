################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include emlib/subdir.mk
-include CMSIS/EFM32GG/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := efm32_eeprom_read_write
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: efm32_eeprom_read_write.axf

# Tool invocations
efm32_eeprom_read_write.axf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -T "efm32_eeprom_read_write.ld" -Wl,--no-warn-rwx-segments -Xlinker --gc-sections -Xlinker -Map="efm32_eeprom_read_write.map" --specs=nano.specs -o efm32_eeprom_read_write.axf "./CMSIS/EFM32GG/startup_efm32gg.o" "./CMSIS/EFM32GG/system_efm32gg.o" "./emlib/em_cmu.o" "./emlib/em_core.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_i2c.o" "./emlib/em_system.o" "./src/eeprom.o" "./src/main.o" "./src/syscalls.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building out file: efm32_eeprom_read_write.out'
	arm-none-eabi-objcopy "efm32_eeprom_read_write.axf" "efm32_eeprom_read_write.out"
	@echo ' '

	@echo 'Building hex file: efm32_eeprom_read_write.hex'
	arm-none-eabi-objcopy -O ihex "efm32_eeprom_read_write.axf" "efm32_eeprom_read_write.hex"
	@echo ' '

	@echo 'Building bin file: efm32_eeprom_read_write.bin'
	arm-none-eabi-objcopy -O binary "efm32_eeprom_read_write.axf" "efm32_eeprom_read_write.bin"
	@echo ' '

	@echo 'Building s37 file: efm32_eeprom_read_write.s37'
	arm-none-eabi-objcopy -O srec "efm32_eeprom_read_write.axf" "efm32_eeprom_read_write.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "efm32_eeprom_read_write.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) efm32_eeprom_read_write.axf
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets

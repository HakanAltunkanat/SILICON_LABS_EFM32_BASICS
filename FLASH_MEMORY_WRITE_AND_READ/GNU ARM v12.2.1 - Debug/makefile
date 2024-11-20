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


BUILD_ARTIFACT_NAME := FLASH_MEMORY_WRITE_AND_READ
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: FLASH_MEMORY_WRITE_AND_READ.axf

# Tool invocations
FLASH_MEMORY_WRITE_AND_READ.axf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -T "FLASH_MEMORY_WRITE_AND_READ.ld" -Wl,--no-warn-rwx-segments -Xlinker --gc-sections -Xlinker -Map="FLASH_MEMORY_WRITE_AND_READ.map" --specs=nano.specs -o FLASH_MEMORY_WRITE_AND_READ.axf "./CMSIS/EFM32GG/startup_efm32gg.o" "./CMSIS/EFM32GG/system_efm32gg.o" "./em_gpio.o" "./emlib/em_cmu.o" "./emlib/em_core.o" "./emlib/em_msc.o" "./emlib/em_system.o" "./src/main.o" "./src/syscalls.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building out file: FLASH_MEMORY_WRITE_AND_READ.out'
	arm-none-eabi-objcopy "FLASH_MEMORY_WRITE_AND_READ.axf" "FLASH_MEMORY_WRITE_AND_READ.out"
	@echo ' '

	@echo 'Building hex file: FLASH_MEMORY_WRITE_AND_READ.hex'
	arm-none-eabi-objcopy -O ihex "FLASH_MEMORY_WRITE_AND_READ.axf" "FLASH_MEMORY_WRITE_AND_READ.hex"
	@echo ' '

	@echo 'Building bin file: FLASH_MEMORY_WRITE_AND_READ.bin'
	arm-none-eabi-objcopy -O binary "FLASH_MEMORY_WRITE_AND_READ.axf" "FLASH_MEMORY_WRITE_AND_READ.bin"
	@echo ' '

	@echo 'Building s37 file: FLASH_MEMORY_WRITE_AND_READ.s37'
	arm-none-eabi-objcopy -O srec "FLASH_MEMORY_WRITE_AND_READ.axf" "FLASH_MEMORY_WRITE_AND_READ.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "FLASH_MEMORY_WRITE_AND_READ.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) FLASH_MEMORY_WRITE_AND_READ.axf
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets

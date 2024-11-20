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


BUILD_ARTIFACT_NAME := adc_polling
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: adc_polling.axf

# Tool invocations
adc_polling.axf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -T "adc_polling.ld" -Wl,--no-warn-rwx-segments -Xlinker --gc-sections -Xlinker -Map="adc_polling.map" --specs=nano.specs -o adc_polling.axf "./CMSIS/EFM32GG/startup_efm32gg.o" "./CMSIS/EFM32GG/system_efm32gg.o" "./emlib/em_adc.o" "./emlib/em_cmu.o" "./emlib/em_core.o" "./emlib/em_system.o" "./src/main_s0.o" "./src/sl_syscalls.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building out file: adc_polling.out'
	arm-none-eabi-objcopy "adc_polling.axf" "adc_polling.out"
	@echo ' '

	@echo 'Building hex file: adc_polling.hex'
	arm-none-eabi-objcopy -O ihex "adc_polling.axf" "adc_polling.hex"
	@echo ' '

	@echo 'Building bin file: adc_polling.bin'
	arm-none-eabi-objcopy -O binary "adc_polling.axf" "adc_polling.bin"
	@echo ' '

	@echo 'Building s37 file: adc_polling.s37'
	arm-none-eabi-objcopy -O srec "adc_polling.axf" "adc_polling.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "adc_polling.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) adc_polling.axf
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets

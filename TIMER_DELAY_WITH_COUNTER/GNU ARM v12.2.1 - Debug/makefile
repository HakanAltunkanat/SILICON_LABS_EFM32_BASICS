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


BUILD_ARTIFACT_NAME := TIMER_DELAY_WITH_COUNTER
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: TIMER_DELAY_WITH_COUNTER.axf

# Tool invocations
TIMER_DELAY_WITH_COUNTER.axf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -T "TIMER_DELAY_WITH_COUNTER.ld" -Wl,--no-warn-rwx-segments -Xlinker --gc-sections -Xlinker -Map="TIMER_DELAY_WITH_COUNTER.map" --specs=nano.specs -o TIMER_DELAY_WITH_COUNTER.axf "./CMSIS/EFM32GG/startup_efm32gg.o" "./CMSIS/EFM32GG/system_efm32gg.o" "./emlib/em_cmu.o" "./emlib/em_core.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_system.o" "./emlib/em_timer.o" "./src/delay.o" "./src/main_series0.o" "./src/sl_syscalls.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building out file: TIMER_DELAY_WITH_COUNTER.out'
	arm-none-eabi-objcopy "TIMER_DELAY_WITH_COUNTER.axf" "TIMER_DELAY_WITH_COUNTER.out"
	@echo ' '

	@echo 'Building hex file: TIMER_DELAY_WITH_COUNTER.hex'
	arm-none-eabi-objcopy -O ihex "TIMER_DELAY_WITH_COUNTER.axf" "TIMER_DELAY_WITH_COUNTER.hex"
	@echo ' '

	@echo 'Building bin file: TIMER_DELAY_WITH_COUNTER.bin'
	arm-none-eabi-objcopy -O binary "TIMER_DELAY_WITH_COUNTER.axf" "TIMER_DELAY_WITH_COUNTER.bin"
	@echo ' '

	@echo 'Building s37 file: TIMER_DELAY_WITH_COUNTER.s37'
	arm-none-eabi-objcopy -O srec "TIMER_DELAY_WITH_COUNTER.axf" "TIMER_DELAY_WITH_COUNTER.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "TIMER_DELAY_WITH_COUNTER.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) TIMER_DELAY_WITH_COUNTER.axf
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets

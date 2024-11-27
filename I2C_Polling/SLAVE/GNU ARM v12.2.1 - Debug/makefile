################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include emlib/subdir.mk
-include CMSIS/EFM32ZG/subdir.mk
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


BUILD_ARTIFACT_NAME := zg_slave_i2c
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: zg_slave_i2c.axf

# Tool invocations
zg_slave_i2c.axf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb -T "zg_slave_i2c.ld" -Wl,--no-warn-rwx-segments -Xlinker --gc-sections -Xlinker -Map="zg_slave_i2c.map" --specs=nano.specs -o zg_slave_i2c.axf "./CMSIS/EFM32ZG/startup_efm32zg.o" "./CMSIS/EFM32ZG/system_efm32zg.o" "./emlib/em_cmu.o" "./emlib/em_core.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_i2c.o" "./emlib/em_system.o" "./src/main_zg_hg.o" "./src/syscalls.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building out file: zg_slave_i2c.out'
	arm-none-eabi-objcopy "zg_slave_i2c.axf" "zg_slave_i2c.out"
	@echo ' '

	@echo 'Building hex file: zg_slave_i2c.hex'
	arm-none-eabi-objcopy -O ihex "zg_slave_i2c.axf" "zg_slave_i2c.hex"
	@echo ' '

	@echo 'Building bin file: zg_slave_i2c.bin'
	arm-none-eabi-objcopy -O binary "zg_slave_i2c.axf" "zg_slave_i2c.bin"
	@echo ' '

	@echo 'Building s37 file: zg_slave_i2c.s37'
	arm-none-eabi-objcopy -O srec "zg_slave_i2c.axf" "zg_slave_i2c.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "zg_slave_i2c.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) zg_slave_i2c.axf
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets

################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include emlib/subdir.mk
-include Drivers/subdir.mk
-include CMSIS/EFM32GG/subdir.mk
-include BSP/subdir.mk
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


BUILD_ARTIFACT_NAME := RTC_ALARM
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: RTC_ALARM.axf

# Tool invocations
RTC_ALARM.axf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -T "RTC_ALARM.ld" -Xlinker --gc-sections -Xlinker -Map="RTC_ALARM.map" --specs=nano.specs -o RTC_ALARM.axf "./BSP/bsp_trace.o" "./CMSIS/EFM32GG/startup_efm32gg.o" "./CMSIS/EFM32GG/system_efm32gg.o" "./Drivers/segmentlcd.o" "./Drivers/vddcheck.o" "./emlib/em_assert.o" "./emlib/em_cmu.o" "./emlib/em_core.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_lcd.o" "./emlib/em_rtc.o" "./emlib/em_system.o" "./emlib/em_vcmp.o" "./src/config.o" "./src/main.o" "./src/syscalls.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building out file: RTC_ALARM.out'
	arm-none-eabi-objcopy "RTC_ALARM.axf" "RTC_ALARM.out"
	@echo ' '

	@echo 'Building hex file: RTC_ALARM.hex'
	arm-none-eabi-objcopy -O ihex "RTC_ALARM.axf" "RTC_ALARM.hex"
	@echo ' '

	@echo 'Building bin file: RTC_ALARM.bin'
	arm-none-eabi-objcopy -O binary "RTC_ALARM.axf" "RTC_ALARM.bin"
	@echo ' '

	@echo 'Building s37 file: RTC_ALARM.s37'
	arm-none-eabi-objcopy -O srec "RTC_ALARM.axf" "RTC_ALARM.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "RTC_ALARM.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) RTC_ALARM.axf
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets

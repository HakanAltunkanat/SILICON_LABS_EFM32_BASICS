################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_cmu.c \
C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_core.c \
C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_emu.c \
C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_gpio.c \
C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_system.c \
C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_timer.c 

OBJS += \
./emlib/em_cmu.o \
./emlib/em_core.o \
./emlib/em_emu.o \
./emlib/em_gpio.o \
./emlib/em_system.o \
./emlib/em_timer.o 

C_DEPS += \
./emlib/em_cmu.d \
./emlib/em_core.d \
./emlib/em_emu.d \
./emlib/em_gpio.d \
./emlib/em_system.d \
./emlib/em_timer.d 


# Each subdirectory must supply rules for building sources it contributes
emlib/em_cmu.o: C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_cmu.c emlib/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32GG990F1024=1' '-DDEBUG=1' -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/EFM32GG_STK3700/config" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/common/bsp" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/common/drivers" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -O0 -Wall -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -c -fmessage-length=0 -MMD -MP -MF"emlib/em_cmu.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_core.o: C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_core.c emlib/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32GG990F1024=1' '-DDEBUG=1' -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/EFM32GG_STK3700/config" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/common/bsp" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/common/drivers" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -O0 -Wall -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -c -fmessage-length=0 -MMD -MP -MF"emlib/em_core.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_emu.o: C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_emu.c emlib/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32GG990F1024=1' '-DDEBUG=1' -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/EFM32GG_STK3700/config" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/common/bsp" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/common/drivers" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -O0 -Wall -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -c -fmessage-length=0 -MMD -MP -MF"emlib/em_emu.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_gpio.o: C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_gpio.c emlib/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32GG990F1024=1' '-DDEBUG=1' -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/EFM32GG_STK3700/config" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/common/bsp" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/common/drivers" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -O0 -Wall -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -c -fmessage-length=0 -MMD -MP -MF"emlib/em_gpio.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_system.o: C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_system.c emlib/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32GG990F1024=1' '-DDEBUG=1' -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/EFM32GG_STK3700/config" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/common/bsp" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/common/drivers" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -O0 -Wall -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -c -fmessage-length=0 -MMD -MP -MF"emlib/em_system.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_timer.o: C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_timer.c emlib/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32GG990F1024=1' '-DDEBUG=1' -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/EFM32GG_STK3700/config" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/common/bsp" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/common/drivers" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -O0 -Wall -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -c -fmessage-length=0 -MMD -MP -MF"emlib/em_timer.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



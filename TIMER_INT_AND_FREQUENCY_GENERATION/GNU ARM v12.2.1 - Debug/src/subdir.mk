################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main_series0.c \
C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2/platform/common/src/sl_syscalls.c 

OBJS += \
./src/main_series0.o \
./src/sl_syscalls.o 

C_DEPS += \
./src/main_series0.d \
./src/sl_syscalls.d 


# Each subdirectory must supply rules for building sources it contributes
src/main_series0.o: ../src/main_series0.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32GG990F1024=1' '-DDEBUG=1' -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/EFM32GG_STK3700/config" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/common/bsp" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/common/drivers" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -O0 -Wall -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -c -fmessage-length=0 -MMD -MP -MF"src/main_series0.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sl_syscalls.o: C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2/platform/common/src/sl_syscalls.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32GG990F1024=1' '-DDEBUG=1' -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/EFM32GG_STK3700/config" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/common/bsp" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/common/drivers" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -O0 -Wall -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -c -fmessage-length=0 -MMD -MP -MF"src/sl_syscalls.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main_gg_lg_wg.c \
../src/syscalls.c 

OBJS += \
./src/main_gg_lg_wg.o \
./src/syscalls.o 

C_DEPS += \
./src/main_gg_lg_wg.d \
./src/syscalls.d 


# Each subdirectory must supply rules for building sources it contributes
src/main_gg_lg_wg.o: ../src/main_gg_lg_wg.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DRETARGET_VCOM=1' '-DEFM32GG990F1024=1' '-DDEBUG=1' -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//hardware/kit/EFM32GG_STK3700/config" -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//platform/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//platform/Device/SiliconLabs/EFM32GG/Include" -O0 -Wall -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -c -fmessage-length=0 -MMD -MP -MF"src/main_gg_lg_wg.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/syscalls.o: ../src/syscalls.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DRETARGET_VCOM=1' '-DEFM32GG990F1024=1' '-DDEBUG=1' -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//hardware/kit/EFM32GG_STK3700/config" -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//platform/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//platform/Device/SiliconLabs/EFM32GG/Include" -O0 -Wall -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -c -fmessage-length=0 -MMD -MP -MF"src/syscalls.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



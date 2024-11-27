################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0/platform/Device/SiliconLabs/EFM32ZG/Source/system_efm32zg.c 

S_UPPER_SRCS += \
C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0/platform/Device/SiliconLabs/EFM32ZG/Source/GCC/startup_efm32zg.S 

OBJS += \
./CMSIS/EFM32ZG/startup_efm32zg.o \
./CMSIS/EFM32ZG/system_efm32zg.o 

C_DEPS += \
./CMSIS/EFM32ZG/system_efm32zg.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/EFM32ZG/startup_efm32zg.o: C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0/platform/Device/SiliconLabs/EFM32ZG/Source/GCC/startup_efm32zg.S CMSIS/EFM32ZG/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Assembler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//hardware/kit/EFM32ZG_STK3200/config" -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//platform/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//platform/Device/SiliconLabs/EFM32ZG/Include" '-DRETARGET_VCOM=1' '-DEFM32ZG222F32=1' -c -x assembler-with-cpp -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

CMSIS/EFM32ZG/system_efm32zg.o: C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0/platform/Device/SiliconLabs/EFM32ZG/Source/system_efm32zg.c CMSIS/EFM32ZG/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DRETARGET_VCOM=1' '-DEFM32ZG222F32=1' '-DDEBUG=1' -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//hardware/kit/EFM32ZG_STK3200/config" -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//platform/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v5_2/developer/sdks/gecko_sdk_suite/v3.0//platform/Device/SiliconLabs/EFM32ZG/Include" -O0 -Wall -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -c -fmessage-length=0 -MMD -MP -MF"CMSIS/EFM32ZG/system_efm32zg.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



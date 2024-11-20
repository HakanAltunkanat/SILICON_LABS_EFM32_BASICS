################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2/platform/Device/SiliconLabs/EFM32GG/Source/system_efm32gg.c 

S_UPPER_SRCS += \
C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2/platform/Device/SiliconLabs/EFM32GG/Source/GCC/startup_efm32gg.S 

OBJS += \
./CMSIS/EFM32GG/startup_efm32gg.o \
./CMSIS/EFM32GG/system_efm32gg.o 

C_DEPS += \
./CMSIS/EFM32GG/system_efm32gg.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/EFM32GG/startup_efm32gg.o: C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2/platform/Device/SiliconLabs/EFM32GG/Source/GCC/startup_efm32gg.S CMSIS/EFM32GG/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Assembler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/EFM32GG_STK3700/config" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/common/bsp" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/common/drivers" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" '-DEFM32GG990F1024=1' -c -x assembler-with-cpp -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

CMSIS/EFM32GG/system_efm32gg.o: C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2/platform/Device/SiliconLabs/EFM32GG/Source/system_efm32gg.c CMSIS/EFM32GG/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32GG990F1024=1' '-DDEBUG=1' -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/EFM32GG_STK3700/config" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/common/bsp" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/common/drivers" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -O0 -Wall -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -c -fmessage-length=0 -MMD -MP -MF"CMSIS/EFM32GG/system_efm32gg.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



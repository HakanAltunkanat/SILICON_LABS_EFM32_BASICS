################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../em_lcd.c \
../segmentlcd.c 

OBJS += \
./em_lcd.o \
./segmentlcd.o 

C_DEPS += \
./em_lcd.d \
./segmentlcd.d 


# Each subdirectory must supply rules for building sources it contributes
em_lcd.o: ../em_lcd.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32GG990F1024=1' '-DDEBUG=1' -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/EFM32GG_STK3700/config" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/common/bsp" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/common/drivers" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -O0 -Wall -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -c -fmessage-length=0 -MMD -MP -MF"em_lcd.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

segmentlcd.o: ../segmentlcd.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32GG990F1024=1' '-DDEBUG=1' -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/EFM32GG_STK3700/config" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/common/bsp" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//hardware/kit/common/drivers" -I"C:/Users/lextu/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -O0 -Wall -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -c -fmessage-length=0 -MMD -MP -MF"segmentlcd.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



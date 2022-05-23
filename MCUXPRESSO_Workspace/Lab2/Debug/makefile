################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Lab2.axf

# Tool invocations
Lab2.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/Users/ahmedphone/Documents/MCUXPRESSO_Workspace/lpc_board_nxp_lpcxpresso_1549/Debug" -L"/Users/ahmedphone/Documents/MCUXPRESSO_Workspace/lpc_chip_15xx/Debug" -Xlinker -Map="Lab2.map" -Xlinker --cref -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m3 -mthumb -T "Lab2_Debug.ld" -o "Lab2.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) Lab2.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "Lab2.axf"; # arm-none-eabi-objcopy -v -O binary "Lab2.axf" "Lab2.bin" ; # checksum -p LPC1549 -d "Lab2.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets

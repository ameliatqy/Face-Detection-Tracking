################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
main.obj: ../main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccsv7/ccs_base/arm/include" --include_path="/Applications/ti/msp432_driverlib_3_21_00_05/driverlib/MSP432P4xx" --include_path="/Applications/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="/Users/ameliatee/CCSworkspace_v7/Final_Project_SPI" --include_path="/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="main.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

startup_msp432p401r_ccs.obj: ../startup_msp432p401r_ccs.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccsv7/ccs_base/arm/include" --include_path="/Applications/ti/msp432_driverlib_3_21_00_05/driverlib/MSP432P4xx" --include_path="/Applications/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="/Users/ameliatee/CCSworkspace_v7/Final_Project_SPI" --include_path="/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="startup_msp432p401r_ccs.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

system_msp432p401r.obj: ../system_msp432p401r.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccsv7/ccs_base/arm/include" --include_path="/Applications/ti/msp432_driverlib_3_21_00_05/driverlib/MSP432P4xx" --include_path="/Applications/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="/Users/ameliatee/CCSworkspace_v7/Final_Project_SPI" --include_path="/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="system_msp432p401r.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '



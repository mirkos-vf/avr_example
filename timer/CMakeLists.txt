cmake_minimum_required(VERSION 3.10)

set(PROG_TYPE usbasp)
# extra arguments to avrdude: baud rate, chip type, -F flag, etc.

# Variables regarding the AVR chip
set(MCU atmega328p)
set(TMCU m328p)
set(F_CPU 8000000)

add_definitions(-DF_CPU=${F_CPU})

# program names
set(AVRCPP   avr-g++)
set(AVRC     avr-gcc)

set(OBJCOPY  avr-objcopy)
set(OBJDUMP  avr-objdump)
set(AVRSIZE  avr-size)
set(AVRDUDE  avrdude)

# Sets the compiler
# Needs to come before the project function
set(CMAKE_SYSTEM_NAME    Generic)
set(CMAKE_CXX_COMPILER   ${AVRCPP})
set(CMAKE_C_COMPILER     ${AVRC})
set(CMAKE_ASM_COMPILER   ${AVRC})

project (timer C)

# Important project paths
set(BASE_PATH    "${${PROJECT_NAME}_SOURCE_DIR}")
set(INC_PATH     "${BASE_PATH}/inc")
set(SRC_PATH     "${BASE_PATH}/src")
set(LIB_DIR_PATH "${BASE_PATH}/lib")

# Files to be compiled
file(GLOB SRC_FILES "${SRC_PATH}/*.c")

set(LIB_SRC_FILES)
set(LIB_INC_PATH)
file(GLOB LIBRARIES "${LIB_DIR_PATH}/*")
foreach(subdir ${LIBRARIES})
    file(GLOB lib_files "${subdir}/*.c")
    if(IS_DIRECTORY ${subdir})
        list(APPEND LIB_INC_PATH  "${subdir}")
    endif()
    list(APPEND LIB_SRC_FILES "${lib_files}")
endforeach()

# Compiler flags
set(CSTANDARD "-std=gnu99")
set(CWARN     "-Wall")
set(COPT      "-Os")
set(CMCU      "-mmcu=${MCU}")
set(CDEFS     "-DF_CPU=${F_CPU}")

set(CFLAGS   "${CMCU} ${CDEFS} ${COPT} ${CWARN} ${CSTANDARD}")
set(CXXFLAGS "${CMCU} ${CDEFS} ${COPT}")

set(CMAKE_C_FLAGS       "${CFLAGS}")
set(CMAKE_CXX_FLAGS     "${CXXFLAGS}")
set(CMAKE_ASM_FLAGS     "${CFLAGS}")

# Project setup
include_directories(${INC_PATH} ${LIB_INC_PATH})
add_executable(${PROJECT_NAME} ${SRC_FILES} ${LIB_SRC_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}.elf")

# Compiling targets

add_custom_target(hex ALL       ${OBJCOPY} -R .eeprom -O ihex "${PROJECT_NAME}.elf" "${PROJECT_NAME}.hex")
add_custom_target(flash         ${AVRDUDE} -c usbasp -p m328p -p atmega328p -U flash:w:${PROJECT_NAME}.hex:i)
add_custom_target(reset         ${AVRDUDE} -c ${PROG_TYPE} -p ${MCU} -e)
#TODO: exctract fuse from variables -U lfuse:w:0x62:m -U hfuse:w:0xD9:m
add_custom_target(fuses         ${AVRDUDE} -c ${PROG_TYPE} -p ${MCU} -U lfuse:w:0x62:m -U hfuse:w:0xD9:m)

set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "${PROJECT_NAME}.hex")

# Config logging
message("* ")
message("* Project Name:\t${PROJECT_NAME}")
message("* Project Source:\t${SRC_PATH}")
message("* Project Include:\t${INC_PATH}")
message("* Library Include:\t${LIB_INC_PATH}")
message("* ")
message("* Project Source Files:\t${SRC_FILES}")
message("* Library Source Files:\t${LIB_SRC_FILES}")
message("* ")
message("* C Flags:\t${CMAKE_C_FLAGS}")
message("* ")
message("* CXX Flags:\t${CMAKE_C_FLAGS}")
message("* ")
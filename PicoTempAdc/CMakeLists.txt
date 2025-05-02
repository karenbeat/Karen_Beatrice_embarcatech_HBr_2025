# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(PicoTempADC C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1
# Ajustado para o nome do arquivo correto 'src/main.c'
add_executable(PicoTempADC src/main.c)

pico_set_program_name(PicoTempADC "PicoTempADC")
pico_set_program_version(PicoTempADC "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(PicoTempADC 0)
pico_enable_stdio_usb(PicoTempADC 0)

# Add the standard library to the build
target_link_libraries(PicoTempADC
        pico_stdlib)

# Add the standard include files to the build
# Agora estamos incluindo o diretório 'include' para o arquivo de cabeçalho
target_include_directories(PicoTempADC PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/include
)

# Add any user requested libraries
target_link_libraries(PicoTempADC 
        # Se tiver bibliotecas adicionais, adicione-as aqui
)

# Generate extra outputs like UF2 file
pico_add_extra_outputs(PicoTempADC)

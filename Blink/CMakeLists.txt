cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(projeto_led C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(projeto_led
    app/main.c
    hal/hal_led.c
    drivers/led_embutido.c
)

target_include_directories(projeto_led PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(projeto_led pico_stdlib pico_cyw43_arch_none)

pico_add_extra_outputs(projeto_led)

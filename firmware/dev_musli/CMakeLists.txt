cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(dev_musli)

add_executable(dev_musli
        dev_musli.c
        )

pico_sdk_init()

target_link_libraries(dev_musli PRIVATE pico_stdlib hardware_resets hardware_irq hardware_spi)

pico_add_extra_outputs(dev_musli)

cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(host_musli_kbd)

add_executable(host_musli_kbd)

pico_sdk_init()

# Example source
target_sources(host_musli_kbd PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/hid_app.c
        ${CMAKE_CURRENT_LIST_DIR}/main.c
        )

# Make sure TinyUSB can find tusb_config.h
target_include_directories(host_musli_kbd PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})

# In addition to pico_stdlib required for common PicoSDK functionality, add dependency on tinyusb_host
# for TinyUSB device support and tinyusb_board for the additional board support library used by the example
target_link_libraries(host_musli_kbd PUBLIC pico_stdlib tinyusb_host tinyusb_board hardware_spi)

pico_add_extra_outputs(host_musli_kbd)

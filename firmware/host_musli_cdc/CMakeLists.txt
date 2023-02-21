cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(host_musli)

add_executable(host_musli_cdc_hid)

pico_sdk_init()

# Example source
target_sources(host_musli_cdc_hid PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/main.c
        ${CMAKE_CURRENT_LIST_DIR}/cdc_app.c
        )

# Make sure TinyUSB can find tusb_config.h
target_include_directories(host_musli_cdc_hid PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})

# In addition to pico_stdlib required for common PicoSDK functionality, add dependency on tinyusb_host
# for TinyUSB device support and tinyusb_board for the additional board support library used by the example
target_link_libraries(host_musli_cdc_hid PUBLIC pico_stdlib tinyusb_host tinyusb_board)

pico_add_extra_outputs(host_musli_cdc_hid)

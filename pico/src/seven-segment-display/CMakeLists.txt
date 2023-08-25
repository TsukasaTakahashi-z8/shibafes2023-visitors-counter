add_executable(seven-segment-display
        seven-segment-display.c
        )

# pull in common dependencies
target_link_libraries(seven-segment-display pico_stdlib hardware_uart)

pico_enable_stdio_usb(seven-segment-display 1)
pico_enable_stdio_uart(seven-segment-display 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(seven-segment-display)

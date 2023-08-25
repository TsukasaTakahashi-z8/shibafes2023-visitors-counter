add_executable(GPIOtest
        GPIOtest.c
        )

# pull in common dependencies
target_link_libraries(GPIOtest pico_stdlib hardware_uart)

pico_enable_stdio_usb(GPIOtest 1)
pico_enable_stdio_uart(GPIOtest 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(GPIOtest)

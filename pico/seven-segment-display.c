#include <stdio.h>
#include "pico/stdlib.h"

// 一旦Lチカ
int main() {
#ifndef PICO_DEFAULT_LED_PIN
#else
    stdio_init_all();

    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    printf("loop start\n");

    int n = 0;
    while (true) {
        n++;
        printf("count:%d\n", n);
        gpio_put(LED_PIN, 1);
        sleep_ms(100);
        gpio_put(LED_PIN, 0);
        sleep_ms(100);
        gpio_put(LED_PIN, 1);
        sleep_ms(100);
        gpio_put(LED_PIN, 0);
        sleep_ms(400);
    }
#endif
}

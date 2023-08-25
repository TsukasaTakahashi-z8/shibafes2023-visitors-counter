#include "pico/stdlib.h"

int main() {
#ifndef PICO_DEFAULT_LED_PIN
#else
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    int i;
    uint LED_PIN_TMP;
    for (i=0; i<=28; i++) {
        LED_PIN_TMP = i;
        if (i <= 22 || i >= 26) {
            gpio_init(LED_PIN_TMP);
            gpio_set_dir(LED_PIN_TMP, true);
        }
    }

    while (true) {
        for (i=0; i<=28; i++) {
            LED_PIN_TMP = i;
            if (i <= 22 || i >= 26) {
                gpio_put(LED_PIN_TMP, 1);
                gpio_put(LED_PIN, 1);
                sleep_ms(150);
                gpio_put(LED_PIN_TMP, 0);
                gpio_put(LED_PIN, 0);
                sleep_ms(150);
            }
        }
    }
#endif
}

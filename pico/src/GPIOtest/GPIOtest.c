#include "pico/stdlib.h"

int main() {
#ifndef PICO_DEFAULT_LED_PIN
#else
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    int i;
    uint LED_PIN_TMP;
    for (i=0; i<=14; i++) {
        LED_PIN_TMP = i;
        if (i == 0 || 2<=i) {
            gpio_init(LED_PIN_TMP);
            gpio_set_dir(LED_PIN_TMP, true);
        }
    }

    int all_7seg(bool tmp) {
        // 88888
        
        if (tmp) {
            gpio_put(LED_PIN, 1);

            // A~G
            for (i=0; i<=8; i++) {
                LED_PIN_TMP = i;
                gpio_put(LED_PIN_TMP, 1);
            }
            // 桁
            for (i=10; i<=14; i++) {
                LED_PIN_TMP = i;
                gpio_put(LED_PIN_TMP, 0);
            }
        }
        else {
            gpio_put(LED_PIN, 0);

            // A~G
            for (i=0; i<=8; i++) {
                LED_PIN_TMP = i;
                gpio_put(LED_PIN_TMP, 0);
            }
            // 桁
            for (i=10; i<=14; i++) {
                LED_PIN_TMP = i;
                gpio_put(LED_PIN_TMP, 0);
            }
        }
        return 0;
    }

    while (true) {
        all_7seg(true);
        sleep_ms(300);
        all_7seg(false);
        sleep_ms(150);
    }
#endif
}

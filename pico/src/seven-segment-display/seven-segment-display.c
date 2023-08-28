#include "pico/stdlib.h"
#include <stdio.h>
#include <math.h>

int gpio_initialize() {
    int i;
    uint LED_PIN_TMP;
    for (i=0; i<=14; i++) {
        LED_PIN_TMP = i;
        if (i == 0 || 2<=i) {
            gpio_init(LED_PIN_TMP);
            gpio_set_dir(LED_PIN_TMP, true);
        }
    }
    return 0;
}

int all_7seg(bool tmp) {
    int i;
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    // 88888
    if (tmp) {
        gpio_put(LED_PIN, 1);
        for (i=0; i<=8; i++) { //A~G
            LED_PIN_TMP = i;
            gpio_put(LED_PIN_TMP, 1);
        }
        for (i=10; i<=14; i++) { //桁
            LED_PIN_TMP = i;
            gpio_put(LED_PIN_TMP, 0);
        }
    }
    else {
        gpio_put(LED_PIN, 0);
        for (i=0; i<=8; i++) {
            LED_PIN_TMP = i;
            gpio_put(LED_PIN_TMP, 0);
        }
        for (i=10; i<=14; i++) {
            LED_PIN_TMP = i;
            gpio_put(LED_PIN_TMP, 0);
        }
    }
    return 0;
}

int display(int num) {
    const int bits[10] = {
        0x3f,
        0x06,
        0x5b,
        0x4f,
        0x66,
        0x6d,
        0x7d,
        0x07,
        0x7f,
        0x67
    };
    int i;
    for (i=1; i<=5, i++) {
        num
    }

    return num;
}

int main() {
    stdio_init_all();

    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_initialize();
    printf("turn all 7seg on\n");
    all_7seg(true);
    sleep_ms(500);
    printf("turn all 7seg off\n");
    all_7seg(false);

    int num = 0;
    int new_num;
    while (true) {
        while (scanf("%d", &new_num)) {
        
        }

    }
}

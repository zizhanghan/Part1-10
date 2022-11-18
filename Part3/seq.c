#include "pico/stdlib.h"
#include <stdio.h>
#include "neopixel.h"
#include "hardware/gpio.h"
#include "ws2812.pio.h"
#include "hardware/pio.h"
#define PIO         pio0
#define SM          0
#define FREQ        800000
#define PIN         12
#define POWER_PIN   11
#define IS_RGBW     true  

#define QTPY_BOOT_PIN 21

typedef struct {
    uint32_t last_serial_byte;
    uint32_t button_is_pressed;
    uint32_t light_color;
} Flashlight; 

void render_to_console(Flashlight status) {
    // adjust console window height to match 'frame size'
    for (uint8_t i=0; i<10; i++) { 
        printf("\n");
    }
    printf("button_is_pressed:  0x%08x\n",   status.button_is_pressed);
    printf("light_color:        0x%08x\n",   status.light_color);
}  


int main() {

    stdio_init_all();
    gpio_init(QTPY_BOOT_PIN);
    gpio_set_dir(QTPY_BOOT_PIN, GPIO_IN);
    neopixel_init();

    Flashlight status;
    status.last_serial_byte =  0x00000000;
    status.button_is_pressed = 0x00000000;
    status.light_color =       0x00ff0000;

    int max = 10*1000;
    int i,j = 0;
    uint32_t arr[10*100];
    char input;
    scanf("%c",&input);
    printf("Start to press button.\n");
    while (i < max/10) {
        if (gpio_get(QTPY_BOOT_PIN)) { // poll every cycle, 0 = "pressed"
            status.button_is_pressed = 0x00000000;
            arr[i] = 0x00000000;
        } else {
            status.button_is_pressed = 0x00000001;
            arr[i] = 0x00000001;
        }
        if (status.button_is_pressed) { // poll every cycle
            neopixel_set_rgb(status.light_color);
        } else {
            neopixel_set_rgb(0x00000000);
        }
        render_to_console(status);
        sleep_ms(10); // don't DDOS the serial console
        i += 1;
    }
    printf("Start Replay!");
    while(true){
        while(j < max/10){
            if(arr[j]){
                neopixel_set_rgb(status.light_color);
            }else{
                neopixel_set_rgb(0x00000000);
            }
            render_to_console(status);
            sleep_ms(5); // don't DDOS the serial console
            j += 1;
        }
        j = 0;
    }
    return 0;
}

#include "pico/stdlib.h"
#include <stdio.h>
#include "neopixel.h"
#include "hardware/gpio.h"

#define QTPY_BOOT_PIN 21

typedef struct {
    uint32_t last_serial_byte;
    uint32_t button_is_pressed;
    uint32_t light_color;
} Flashlight; 
typedef          uint32_t   VALUE;
typedef volatile uint32_t * ADDRESS;

VALUE register_read(ADDRESS address) {
    return *address;
}

void register_write(ADDRESS address, VALUE value) {
    *address = value;
}
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
    status.light_color =       0x000000ff;
    while (!stdio_usb_connected());
    uint32_t line;
    volatile uint32_t *boot_pin_address = (ADDRESS) 0xd0000004;
    volatile uint32_t *address;
    volatile uint32_t *address_value;
    char index;
    while (true) {
        sleep_ms(1000);
        printf("Enter r to read register, Enter w to write register.\n");
        scanf("%c", &index);
        uint32_t line;
        uint32_t value;
        uint32_t address_write;
        switch(index){
            case 'r':
                printf("Input address of register to read:\n");
                scanf("%x", &line);
                printf("The address of that register is : %x\n", line);
                address=(volatile uint32_t *)line;
                printf("The value in that register is : %x\n",register_read(address));
                break;
            case'w':
                printf("Input address of register to write:\n");
                scanf("%x", &address_write);
                printf("The address of that register is : %x\n", address_write);
                printf("Enter the new value:\n");
                scanf("%x", &value);
                printf("The value is : %x\n", value);
                address_value=(volatile uint32_t *)value;
                register_write(address_write, address_value);
                break;
        }
        
    }
    return 0;
}

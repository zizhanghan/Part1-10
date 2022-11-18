import time
import board
import neopixel
from adafruit_apds9960.apds9960 import APDS9960

i2c = board.STEMMA_I2C()

apds = APDS9960(i2c)
pixels = neopixel.NeoPixel(board.NEOPIXEL, 1)
#while True:
#    pixels.fill((255, 0, 0))
#    time.sleep(0.5)
#    pixels.fill((0, 0, 0))
#    time.sleep(0.5)


#apds.enable_proximity = True
#apds.enable_gesture = True
apds.enable_color = True
# Uncomment and set the rotation if depending on how your sensor is mounted.
# apds.rotation = 270 # 270 for CLUE
clear=600
while True:
    
    r, g, b, c = apds.color_data
    if(c>=clear+50):
        pixels.fill((255, 0, 0))
    else:    
        pixels.fill((0, 0, 0))
    clear=c
    time.sleep(0.01) 

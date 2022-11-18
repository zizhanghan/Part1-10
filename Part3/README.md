* Create a 'sequencer' that allows you to record BOOT button presses and play them on the Neopixel, and also play a sequence of read/write commands. You should be able to:<br>

record at a least a few seconds of button input to your RP2040 (in RAM)<br>
replay a recorded sequence on your NeoPixel<br>
loop a recording<br>
save a recording to your laptop (the Python Serial library is one way to do this)<br>
play a recording from your laptop<br>
record 'macros' (a sequence of console commands) based on keystrokes in your serial console<br>
hand-edit a list of register read/write commands on your laptop, and play them on the RP2040<br>
include multiple I/O sources in a recording, and remap among the following:<br>
inputs: BOOT button, console commands, register read/write commands<br>
outputs: neopixel color, neopixel brightness, data over serial, register read/write commands<br>

I use the array to record every press and transmit the array to the led.

https://github.com/zizhanghan/Part1-10/blob/main/Part3/489e769373daba6d98edefae15d33f01.mp4

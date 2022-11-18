* TODO:<br>
modify the PIO/DMA logic analyzer example to record a timestamped trace of an RP2040-ADPS9960 exchange while the BOOT button is pressed
with a partner, connect a second Qt Py to the Stemma Qt bus of an ADPS9960 that's attached to a first Qt Py running the Lab 1 Python code
record a trace of this exchange

I modify the logic analyzer's pin to pin 22 which is sdk pin and add the status of boot to judge whether record trace of this exchange.<br>
result:<br>
![image](https://user-images.githubusercontent.com/114272466/202813409-376711e9-6545-4901-bcdf-84ecc1f75af0.png)


# iot_temp-hum
This is an IoT mini project made using ESP8266 to share   Humidity &amp; Temperature read using DHT 11 sensor, Created by Anas Chahid

![h t](https://user-images.githubusercontent.com/64654197/131906557-4392db00-f8d9-44ec-8a03-c5fcaa6cd89d.png)


![IMG_20210902_204314672 NIGHT](https://user-images.githubusercontent.com/64654197/131906601-92dfed39-c640-41d5-b09a-702722a3fd1e.jpg)


Circuit is very simple: to upload code to your ESP8266 either you use ftdi or you can connect it via arduino,<br/>
<br/>
Connect EN,VCC to arduino's 3.3V<br/>
GND to arduino's GND<br/>
RX to RX<br/>
TX to TX<br/>
GPI0 to GND to be able to connect to ESP8266 <br/>
and don't forget to put Arduino's RESET pin in GND<br/>

after Uploading the code you can now connect your DHT11:<br/>

remove GPIO0 pin from GND<br/>
connect DHT11 VCC to 5V<br/>
DHT11 GND to GND<br/>
DHT11 S to GPIO2 in your ESP8266<br/>
Remove RESET pin from GND<br/>

Now you can connect to your local server and monitor Humidity and temperature, to do that simply go to serial monitor and find your ESP8266 IP Address, Type the IP address in your browser and Hit ENTER!<br/>





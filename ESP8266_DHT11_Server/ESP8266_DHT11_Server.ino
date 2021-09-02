/*  This is an IoT mini project made using ESP8266 to share
  Humidity & Temperature read using DHT 11 sensor, Created by Anas Chahid */

#include <DHT.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#define DHTPIN 2
#define DHTTYPE DHT11
#ifndef STASSID
#define STASSID "Your Wifi ssid"
#define STAPSK  "Wifi's password"
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;

DHT dht(DHTPIN, DHTTYPE); 
WiFiServer server(80);   //Server port
ESP8266WiFiMulti WiFiMulti;

float temperature=0.0,humidity=0.0;

void setup() {

  Serial.begin(115200);

  // We start by connecting to a WiFi network
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(ssid, password);

  Serial.println();
  Serial.println();
  Serial.print("Wait for WiFi... ");

  while (WiFiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  
  Serial.println("WiFi connected");
  server.begin();
  Serial.println("Server started");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); //your esp8266 IP Address from which you're going to access data in browser

  delay(500);

}

void loop() {
      humidity = dht.readHumidity();
      temperature = dht.readTemperature();
      WiFiClient client = server.available();
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("Connection: close");  // the connection will be closed after completion of the response
      client.println("Refresh: 5");  // refresh the page automatically every 5 sec
      client.println();
      client.println("<!DOCTYPE html>");
      client.println("<html>");
      client.println("<head>\n<meta charset='UTF-8'>");
      client.println("<title>Temperature and Humidity</title>");
      client.println("</head>\n<body>");
      client.println("<H2>Humidity & Temperature monitoring</H2>");
      client.println("<h3>Temperature °C : </h3>");
      client.print((float)temperature, 2);
      client.println("</br>");
      client.println("<h3>Humidity % : </h3>");
      client.print((float)humidity, 2);
      client.println("</br>");
      client.println("</br>");
      client.println("</br>");
      client.println("<h4>Made by Anas Chahid</h4>");
      client.print("</body>\n</html>");
}

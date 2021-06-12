#include<ESP8266WiFi.h>   //Library for connecting NODEMCU to WiFi
#include<WiFiClient.h>    //Library to handle Client Server
#include<ESP8266WebServer.h>      //Library to generate response for client requests

String ssid= "vivo 1714";
String password = "";

ESP8266WebServer server(80); //Creating an object of server hosted at 80 i.e. HTTP.

void setup() {
  //Default BAUD Rate of Serial Communication RS(323)
  Serial.begin(9600);
  WiFi.begin(ssid,password);
  while(WiFi.status()!= WL_CONNECTED )
  {
    delay(500);
    Serial.print(".");
  }
  Serial.print("Connected to");
  Serial.println(ssid);
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP()); //IP address assign to my server
  server.begin();
  server.on("/",TalentBattel); // Execute my custom function

  Serial.println("HTTP Server Started");
}

void loop() {
  // Wait for Client request
  server.handleClient();

}

void TalentBattel()
{
  server.send(200,"text/html", "<h1><marquee>Hi..!!!...I'm Server</marquee></h1>");
  }

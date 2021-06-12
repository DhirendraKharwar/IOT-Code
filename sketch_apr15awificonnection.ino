#include<ESP8266WiFi.h>
String ssid= "DESKTOP";
String password = "9076846121";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Connecting to...");
  Serial.println(ssid);

  WiFi.begin(ssid,password);

   while(WiFi.status()!= WL_CONNECTED )
  {
    delay(500);
    Serial.print(".");
  }
  Serial.print("Wifi Connected");
  Serial.print("IP address of NodeMCU%U is: ");
  Serial.print(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

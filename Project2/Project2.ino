#include <WiFi.h>
const char* ssid ="WNR";
const char* pass = "O92922065L0ng!";
//-------------------------------------------------------------
#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp32.h>
// Get Auth Token in the Blynk App.
const char* auth = "vZD7LiBZzIuYjAsgrVctsuGDUXKzl9NE";       
//-------------------------------------------------------------
void setup()
{
Serial.begin(115200);
Serial.print("Connecting to ");
Serial.println(ssid);
Serial.print("Password: ");
Serial.println(pass);
WiFi.begin(ssid, pass);
int wifi_ctr = 0;
while (WiFi.status() != WL_CONNECTED) 
          {delay(500);
          Serial.print("."); }
Serial.println("WiFi connected"); 

Blynk.begin(auth, ssid, pass);

}// end setup
 
// Vòng lặp vô hạn

void loop() {
  
  Blynk.run();

}// end loop

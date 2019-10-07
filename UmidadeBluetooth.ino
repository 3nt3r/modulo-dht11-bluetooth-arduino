#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>

#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3);

#define DHTPIN A1
#define DHTTYPE DHT11
 
DHT dht(DHTPIN, DHT11);
 
void setup() 
{
  bluetooth.begin(9600);
  dht.begin();
}
void loop() 
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(t) || isnan(h)) 
  {
    Serial.println("Erro!");
  } 
  else
  {
    bluetooth.print("Umidade: ");
    bluetooth.print(h);
    bluetooth.print(" %t");
    bluetooth.print("Temperatura: ");
    bluetooth.print(t);
    bluetooth.println(" *C");
  }
}

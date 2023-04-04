#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <BH1750FVI.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes);
LiquidCrystal_I2C lcd(0x27, 16, 2);

int waterSensor = A0;
//int waterThreshold = 500;
int waterLevel = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
  LightSensor.begin();
  lcd.begin();
  lcd.backlight();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  float light = LightSensor.GetLightIntensity();
  waterLevel = analogRead(waterSensor);

  Serial.println("Tem/Light/Water");
  Serial.print(temperature);
  Serial.print("/");
  Serial.print(light);
  Serial.print("/");
  Serial.println(waterLevel);

  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Tem/Light/Water");

  lcd.setCursor(0,1);
  lcd.print(temperature);
  lcd.print("/");
  lcd.print(light);
  lcd.print("/");
  lcd.print(waterLevel);

  
  delay(1000);
}

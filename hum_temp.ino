#include <TM1637Display.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define CLK A5
#define DIO A4

#define CLK2 4
#define DIO2 5

#define DHTPIN 2
#define DHTTYPE DHT11   // DHT 11

int temperature_celsius;
int Hum;

TM1637Display display = TM1637Display(CLK, DIO);
TM1637Display display2 = TM1637Display(CLK2, DIO2);

// Create dht object of type DHT:
DHT dht = DHT(DHTPIN, DHTTYPE);

const uint8_t celsius[] = {
    SEG_A | SEG_B | SEG_F | SEG_G,  // Circle
    SEG_A | SEG_D | SEG_E | SEG_F   // C
};
 
const uint8_t p[] = {
    !SEG_A | !SEG_B | !SEG_C | !SEG_D | !SEG_F | !SEG_G | !SEG_E,
    SEG_A | SEG_B | SEG_F | SEG_G | SEG_E
    
    
};
void setup() {
    display.setBrightness(0x0f); 
    display2.setBrightness(0x0f); 
    dht.begin();
} 


void loop() {
  temperature_celsius = dht.readTemperature();
  Hum =  dht.readHumidity();
  
    display.showNumberDec(temperature_celsius, false, 2, 0);
    display.setSegments(celsius, 2, 2);
    delay(2000);
    
    display2.showNumberDec(Hum, false, 2, 0);
    display2.setSegments(p, 2, 2);
    delay(2000);
}

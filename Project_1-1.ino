#include <DHT.h>
#include <DHT_U.h> 

//Constants
#define DHTPIN 7 //the pin which data connected to
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE); //initialize DHT sensor for Arduino

//Variables
int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int LED4 = 10;
int LED5 = 9;
int chk;
float temp; //store temperature value
float hum; //store humidity value

void setup(){
  pinMode(LED1, OUTPUT); //blue led
  pinMode(LED2, OUTPUT); //white led
  pinMode(LED3, OUTPUT); //red led
  pinMode(LED4, OUTPUT); //green led
  pinMode(LED5, OUTPUT); //yellow led
  Serial.begin(9600);
  dht.begin();
}

void loop(){
  delay(2000); 
  //Read data and store it to variables hum and temp
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  
  //if temp is greater or equal 21
  if(temp >= 21){
    digitalWrite(LED2, HIGH);
  }
  //if temp is greater or equal to 10 and less than 21
  if(temp >= 10 && temp < 21){
    digitalWrite(LED4, HIGH);
  }

  //if humidity is greater or equal to 10 and less than 25
  if(hum >= 10 && hum < 35){
    digitalWrite(LED1, HIGH);
  }
  //if humidity is between 15 and 19
  if(hum >= 5 && hum < 10){
    digitalWrite(LED5, HIGH);
  }
  //if humidity is greater or equals than 25
  if(hum >= 35){
    digitalWrite(LED3, HIGH);
  }
  
  
  
  //Print temp and humidity values to serial monitor
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print("%, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");
  delay(10000); //delay in ms
  
}



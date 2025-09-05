#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is connected to the Arduino analog pin A1
#define ONE_WIRE_BUS A1
#define RELAY_PIN 3
#define L298_IN1 11
#define L298_IN2 10
#define L298_IN3 9
#define L298_IN4 6

// Initialize the LCD, set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD I2C address may vary, typically 0x27 or 0x3F


// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

void setup(void)
{
  // Start serial communication for debugging purposes
  // Serial.begin(9600);
  
  // Start up the library
  sensors.begin();

  // Initialize the LCD with 16 columns and 2 rows
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("VENTILATED SEAT");
  delay(1000);

  // Set relay and L298N pins as outputs
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(L298_IN1, OUTPUT);
  pinMode(L298_IN2, OUTPUT);
  pinMode(L298_IN3, OUTPUT);
  pinMode(L298_IN4, OUTPUT);

  // Initialize relay and L298N to off state
  digitalWrite(RELAY_PIN, HIGH);
  digitalWrite(L298_IN1, LOW);
  digitalWrite(L298_IN2, LOW);
  digitalWrite(L298_IN3, LOW);
  digitalWrite(L298_IN4, LOW);
}

void loop(void)
{ 
  // Request temperature from the sensor
  sensors.requestTemperatures(); 
  float tempC = sensors.getTempCByIndex(0);

  // Serial.print("Celsius temperature: ");
  // Serial.print(tempC); 
  // Serial.print(" - Fahrenheit temperature: ");
  // Serial.println(sensors.getTempFByIndex(0));

  // Display temperature on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempC);
  lcd.print((char)223); // Degree symbol
  lcd.print("C  ");

  // Check if temperature exceeds 30°C
  if (tempC > 27) {
    // Turn on relay
    digitalWrite(RELAY_PIN, LOW);

    // Turn on L298N (assuming forward motion)
    digitalWrite(L298_IN1, LOW);
    digitalWrite(L298_IN2, HIGH);
    digitalWrite(L298_IN3, LOW);
    digitalWrite(L298_IN4, HIGH);

    // Display cooling status
    lcd.setCursor(0, 1);
    lcd.print("Cooling: ON ");
  } else {
    // Turn off relay
    digitalWrite(RELAY_PIN, HIGH);

    // Turn off L298N
    digitalWrite(L298_IN1, LOW);
    digitalWrite(L298_IN2, LOW);
    digitalWrite(L298_IN3, LOW);
    digitalWrite(L298_IN4, LOW);

    // Display cooling status
    lcd.setCursor(0, 1);
    lcd.print("Cooling: OFF");
  }

  delay(1000);
}

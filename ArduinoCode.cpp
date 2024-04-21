#include <Servo.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(13, 7, 4, 2, 12, 8);

const int trigPin = 9;    
const int echoPin = 10;    
const int ledPin = A1;    
const int servoPin = 6;
const int trig2Pin=5;
const int echo2Pin=11;

#define BUTTON_PIN 3

Servo myservo;

long duration;
int distance;

int ledState = LOW;
int buttonState = LOW;
bool s = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(trig2Pin,OUTPUT);
  pinMode(echo2Pin,INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
 // myservo.write(0);
   myservo.attach(servoPin);
  lcd.begin(16, 2); 
  lcd.setCursor(0,0);          
  lcd.print("FREE");
}

bool detectieUltrasonic_interior(int t,int e)
{
  digitalWrite(t, LOW);
  delayMicroseconds(2);
  digitalWrite(t, HIGH);
  delayMicroseconds(10);
  digitalWrite(t, LOW);

   duration = pulseIn(e, HIGH);
   distance = (duration / 2) / 29.1;

  if (distance < 20)
    return 1;
  else
    return 0;
}

void loop() 
{
  
  if (detectieUltrasonic_interior(trig2Pin,echo2Pin)==1 &&!s ) 
  {  
    myservo.write(90); 
   	delay(5000);
    
	  if (detectieUltrasonic_interior(trigPin,echoPin)) 
    {
      s=1;
      digitalWrite(ledPin, HIGH);
      lcd.clear();
      lcd.setCursor(0,0);          
  	  lcd.print("Occupied! Someone is here");
      lcd.setCursor(2,1);
      lcd.print("Wait");
      myservo.write(0);
    }
  }
  int buttonState = digitalRead(BUTTON_PIN);
  if(buttonState==HIGH && s)
  {
    myservo.write(90);
    delay(2500);
    if(!detectieUltrasonic_interior(trigPin,echoPin))
    {
    digitalWrite(ledPin,LOW);
    lcd.clear();
    lcd.setCursor(0,0);          
 	lcd.print("FREE");
    delay(2500);
    s=0;
    }
  }
  else
  { 
    myservo.write(0);
  }
}


#include <Servo.h> // allows you to use the library

Servo myServo1; // give a name to your servo
Servo myServo2;

void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);   //The First Motor (Right Motor)
  pinMode(6, OUTPUT);

  pinMode(9, OUTPUT); //The second Motor (Left motor)
  pinMode(10, OUTPUT);

  pinMode(13, OUTPUT);
  
  Serial.begin(9600);

  myServo1.attach(3); // state that your servo is connected to pin 3
  myServo2.attach(11);
}

void loop()
{
  digitalWrite(13, LOW); 

  
  
  if (Serial.available()){

    int command = Serial.read();

    if (command == 114) // 114 is the code for r for right
    {
        spinRight();
    }
    if (command == 108) // 108 is the code for l for left
    {
        spinLeft();
    }
     if (command == 102) // 102 is the code for f for forward
    {
        moveForward();
    }
    if (command == 98) // 98 is the code for b for backwards
    {
        moveBackward();
    }
    if (command == 117) // 117 is the code for u for up
    {
      servo1Up();
    }
    if (command == 100) // 100 is the code for d for down
    {
      servo1Down();
    }
    if (command == 111) // 111 is the code for o for open
    {
      servo2Up();
    }
    if (command == 99) // 99 is the code for c for close
    {
      servo2Down();
    }
    if (command == 115) // 115 is the code for s for stop
    {
      stop();
    }
  }
  
  

  
}


void moveForward()
{
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);

  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
}
void moveBackward()
{
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);

  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
}
void spinLeft()
{
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);

  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
}
void spinRight()
{
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);

  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
}
void servo1Up()
{
     myServo1.write(18);
}
void servo1Down()
{
     myServo1.write(0);
}
void servo2Up()
{
     myServo2.write(180);
}
void servo2Down()
{
     myServo2.write(0);
}
void stop()
{
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);

  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
}



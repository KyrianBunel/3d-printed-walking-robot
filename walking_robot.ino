#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

#define RCPin1 4
#define RCPin2 5
float RCValue1;
float RCValue2;

float coefTHR;
float coefDIR;

void setup() {
  Serial.begin(115200);
  pinMode(RCPin1, INPUT);
  pinMode(RCPin2, INPUT);

  servo1.attach(15);
  servo2.attach(13);
  servo3.attach(12);
  servo4.attach(14);

  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);

}

void loop() {

  servo1.write((-90 * coefTHR) + (90 * coefDIR) + 90);// Moteur Droit
  servo2.write((90 * coefTHR) + (90 * coefDIR) + 90);// Moteur Gauche
  servo3.write((-90 * coefTHR) + (90 * coefDIR) + 90);// Moteur Droit
  servo4.write((90 * coefTHR) + (90 * coefDIR) + 90);// Moteur Gauche

  RCValue1 = pulseIn(RCPin1, HIGH);
  RCValue2 = pulseIn(RCPin2, HIGH);
  coefTHR = (RCValue2 - 1500)/500;
  coefDIR = (RCValue1 - 1500)/500;
  Serial.print("DIR : ");
  Serial.println(RCValue1);
  Serial.print("THR : ");
  Serial.println(RCValue2);
}
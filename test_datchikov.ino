#include <Ultrasonic.h>
Ultrasonic ultrasonic1(2, 3);
Ultrasonic ultrasonic2(6, 7);
Ultrasonic ultrasonic3(8, 9);
Ultrasonic ultrasonic4(10, 11);
void setup() {
  Serial.begin(9600);
}
void loop() {
  Serial.print(ultrasonic1.read()); 
  Serial.print("    ");
  Serial.print(ultrasonic2.read()); 
  Serial.print("    ");
  Serial.print(ultrasonic3.read()); 
  Serial.print("    ");
  Serial.print(ultrasonic4.read()); 
  Serial.println("    ");
}

#include <Ultrasonic.h>
#include <Servo.h>
Ultrasonic Fultrasonic(2, 3);
Ultrasonic Bultrasonic(4, 5);
Ultrasonic Lultrasonic(6, 7);
Ultrasonic Rultrasonic(8, 9);
Servo myservo;

/////////////////////////
int do_front = 70;
int do_back = 20;
/////////////////////////

void motor(int s, int n) {
  if (n == 1) {
    digitalWrite(4, HIGH);
    analogWrite(5, s);
    delay(1);
  }
  else {
    digitalWrite(4, LOW);
    analogWrite(5, s);
    delay(1);
  }
}

void pazvorot(int a) {
  for (int i = 0; i < a; i++) {
    myservo.write(150);
    motor(255, 0);
    delay(1);
  }
}
void setup() {
  myservo.attach(12);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  delay(2000);
}

void ostanovka(int i, int do_back) {
  int x = 0;
  while ( x < i) {
    if (Fultrasonic.read() >= do_back) {
      motor(Fultrasonic.read() - do_back, 1);
      delay(1);
    }
    else {
      motor(do_back - Fultrasonic.read(), 0);
      delay(1);
    }
    delay(1);
    x++;
  }
}

void loop() {
  int do_steni = Rultrasonic.read();
  myservo.write(95);
  int fff = 0;
  while (fff < 10){
    int f = do_steni -Rultrasonic.read();
    if (f*5 < -20 ){
    f = - 4;
   
  }
   if (f*5 > 20 ){
    f =  4;
   
  }
  myservo.write(100 +f*3.8);
    motor(100, 0);
    delay(1);
    if (Fultrasonic.read() < 75 ){
      fff++;
      delay(1);
    }

  }
  pazvorot(2000);
  myservo.write(95);
  //do_steni = 60;//Rultrasonic.read() - 15;
  fff = 0;
   while (fff < 10){
    int f = do_steni -Rultrasonic.read();
    if (f*5 < -15 ){
    f = - 3;
   
  }
   if (f*5 > 15 ){
    f =  3;
   
  }
  //myservo.write(100 +f*3.8);
  myservo.write(100 +f*2);
    motor(100, 0);
    delay(1);
    if (Fultrasonic.read() < 50 ){
      fff++;
      delay(1);
    }

  }

myservo.write(150);
  
  //ostanovka(100000, 50);
  for(int i = 0; i < 1600; i++){
  motor(100, 1);
  delay(1);
  }
 
  motor(0, 1);
  delay ( 100000000);




  //  while (true) {
  //    myservo.write(95);
  //    motor(100, 0);
  //    delay(1);
  //  }
}

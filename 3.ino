#include <Ultrasonic.h>
#include <Servo.h>
Ultrasonic Fultrasonic(2, 3);
Ultrasonic Bultrasonic(4, 5);
Ultrasonic Lultrasonic(6, 7);
Ultrasonic Rultrasonic(8, 9);
Servo myservo;

/////////////////////////
int do_front = 50;
int do_back = 50;
/////////////////////////

void motor(int s, int n) {
  if (n == 1) {
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    analogWrite(12, s);
    delay(1);
  }
  else {
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    analogWrite(12, s);
    delay(1);
  }
}

void povorot(int t) {
  for (int i = 0; i < t; i++) {
    motor(255, 1);
    myservo.write(30);
    delay(1);
  }
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

void setup() {
  myservo.attach(9);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop () {
  myservo.write(90);
  int do_steni = Rultrasonic.read();
  int first_s = Fultrasonic.read();
  int do_maiak = 200;

  int fff = 0;
  while (fff < 10) {
    int f = do_steni - Rultrasonic.read();
    if (f * 5 < -20 ) {
      f = - 4;

    }
    if (f * 5 > 20 ) {
      f = 4;

    }
    myservo.write(100 + f * 3.8);
    motor(100, 0);
    delay(1);
    if (Lultrasonic.read() >= do_maiak) {
      fff++;
      delay(1);
    }
  }

  for (int qqq = 1; qqq < 1500; qqq++) {
    motor(50, 1);
    delay(1000);
  }
  povorot(3000);
  while (Fultrasonic.read() >= do_front) {
    motor(30, 1);
    if (Rultrasonic.read() > do_steni) {
      myservo.write(150);
    }
    else {
      myservo.write(30);
    }
  }

  povorot(3000);
  while (Fultrasonic.read() >= do_front) {
    motor(30, 1);
    if (Rultrasonic.read() > do_steni) {
      myservo.write(150);
    }
    else {
      myservo.write(30);
    }
  }

  povorot(3000);
  while (Fultrasonic.read() >= do_front) {
    motor(30, 1);
    if (Rultrasonic.read() > do_steni) {
      myservo.write(150);
    }
    else {
      myservo.write(30);
    }
  }

  povorot(3000);


  while (Fultrasonic.read() >= first_s) {
    motor(30, 1);
    if (Rultrasonic.read() > do_steni) {
      myservo.write(150);
    }
    else {
      myservo.write(30);
    }
  }
  ostanovka(10000, do_back);
}

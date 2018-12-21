/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

//import java.util.concurrent.TimeUnit;

int led = 9;

float st_wind_up = 0;
float st_walk_on = 4.7;
float st_cha1 = 40.143; //.135 too early .145 too late
float st_paso1 = 58.275; // .225 too early .28 too late
float st_rumba1 = 77.331; //.3295 too early
float st_samba1 = 108.41; // .41 too early .411 too late
float st_cha2 = 121.243; //.241 too early .245 too late
float st_paso2 = 136.23; //.22 is early
float st_jive1 = 152.18; // .18 too early .181 too late
float st_rumba2 = 180.114; //.11 too early .115 too late
float st_paso3 = 219.821; //.82 is too early .822 too late
float st_cha3 = 223.129; // .131 too late
float st_jive2 = 238.97; //239.02 too late
float st_samba2 = 250.865; //.87 too late
float st_jive3 = 270.295; //270.95 too late
//float st_walk_off = 305.2; /.2 too late

long len;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  bar(4, 49.7);
  delay(20);
  len = wind_up();
  delay(st_walk_on - st_wind_up - len);
  len = walk_on();
  delay(st_cha1 - st_walk_on - len);
  len = cha1();
  delay(st_paso1 - st_cha1 - len);
  len = paso1();
  delay(st_rumba1 - st_paso1 - len);
  len = rumba1();
  delay(st_samba1 - st_rumba1 - len);
  len = samba1();
  delay(st_cha2 - st_samba1 - len);
  len = cha2();
  delay(st_paso2 - st_cha2 - len);
  len = paso2();
  delay(st_jive1 - st_paso2 - len);
  len = jive1();
  delay(st_rumba2 - st_jive1 - len);
  len = rumba2();
  delay(st_paso3 - st_rumba2 - len);
  len = paso3();
  delay(st_cha3 - st_paso3 - len);
  len = cha3();
  delay(st_jive2 - st_cha3 - len);
  len = jive2();
  delay(st_samba2 - st_jive2 - len);
  len = samba2();
  delay(st_jive3 - st_samba2 - len);
  len = jive3();
//  delay(st_walk_off - st_jive3 - len);
  walk_off();
  delay(2000);
}

int wind_up() {
  int st = millis();
  for (int i = 0; i < 3; i++) {
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(500);
  }
  int et = millis();
  return (float)(st - et) / 1000;
}

int walk_on() {
  int st = millis();
  for (int i = 0; i < 3; i++) {
    bar(8, 129.8);
  }
  for (int i = 0; i < 3; i++) {
    bar(8, 129.874); //.8749 too fast
  }
  for (int i = 0; i < 3; i++) {
    bar(8, 129.875); //.8754 too fast
  }
  for (int i = 0; i < 1; i++) {
    bar(4, 129.8685); //.869 too fast
  }
  int et = millis();
  return (float)(st - et) / 1000;
}

int cha1() {
  int st = millis();
  for (int i = 0; i < 5; i++) {
    bar(4, 120.9675); //9677 too fast
  }
  for (int i = 0; i < 2; i++) {
    bar(8, 120.9677);
  }
  int et = millis();
  return (float)(st - et) / 1000;
}

int paso1() {
  int st = millis();
  for (int i = 0; i < 4; i++) {
    bar(8, 120.96555); //.9656 too fast .9655 too slow
  }
  // fade into rumba
  digitalWrite(led, HIGH);
  delay(10);
  digitalWrite(led, LOW);
  delay(90);
  digitalWrite(led, HIGH);
  delay(10);
  digitalWrite(led, LOW);
  delay((float)60 / 120.9 * 1000 - 110);

  for (int i = 1; i < 5; i++) {
    digitalWrite(led, HIGH);
    delay(10);
    digitalWrite(led, LOW);
    delay((float)60 / (120.9 - 5 * i) * 1000 - 10);
  }
  digitalWrite(led, HIGH);
  delay(10);
  digitalWrite(led, LOW);
  delay((float)60 / 95 * 1000 - 10);

  int et = millis();
  return (float)(st - et) / 1000;
}

int rumba1() {
  int st = millis();
  for (int i = 0; i < 12; i++) {
    bar(4, 94.9); //.89 too slow
  }
  int et = millis();
  return (float)(st - et) / 1000;
}

int samba1() {
  int st = millis();
  for (int i = 0; i < 3; i++) {
    bar(8, 105.436); //.434 too slow .435 too fast
  }
  int et = millis();
  return (float)(st - et) / 1000;
}


int cha2() {
  int st = millis();
  for (int i = 0; i < 7; i++) {
    bar(4, 129.28); //.29 too fast
  }

  // Stretch into paso
  bar(4, 129.29);
  int et = millis();
  return (float)(st - et) / 1000;
}


int paso2() {
  int st = millis();
  for (int i = 0; i < 4; i++) {
    bar(8, 122.882); //.883 too fast
  }
  int et = millis();
  return (float)(st - et) / 1000;
}

int jive1() {
  int st = millis();
  // ticks into Jive
  bar(4, 163.45);//.44 too slow

  for (int i = 0; i < 8; i++) {
    bar(8, 163.325); // .32<*<.4
  }

  // fade into rumba
  digitalWrite(led, HIGH);
  delay(10);
  digitalWrite(led, LOW);
  delay(90);
  digitalWrite(led, HIGH);
  delay(10);
  digitalWrite(led, LOW);
  delay((float)60 / 163.6 * 1000 - 110);

  for (int i = 1; i < 4; i++) {
    digitalWrite(led, HIGH);
    delay(10);
    digitalWrite(led, LOW);
    delay((float)60 / 163.6 * 1000 - 10);
  }
  for (int i = 0; i < 2; i++) {
    digitalWrite(led, HIGH);
    delay(10);
    digitalWrite(led, LOW);
    delay((float)60 / 85 * 1000 - 10);
  }

  int et = millis();
  return (float)(st - et) / 1000;
}

int rumba2() {
  int st = millis();
  for (int i = 0; i < 12; i++) {
    bar(4, 96.845); //.84 too slow
  }
  int et = millis();
  return (float)(st - et) / 1000;
}

int paso3() {
  int st = millis();
  bar(8, 102);
  bar(4, 107);
  for (int i = 0; i < 4; i++) {
    digitalWrite(led, HIGH);
    delay(10);
    digitalWrite(led, LOW);
    delay((float)60 / (107 + 2 * (i + 1)) * 1000 - 10);
  }
  digitalWrite(led, HIGH);
  delay(10);
  digitalWrite(led, LOW);
  delay(90);
  digitalWrite(led, HIGH);
  delay(10);
  digitalWrite(led, LOW);
  delay((float)60 / 112 * 1000 - 110);
  for (int i = 1; i < 4; i++) {
    digitalWrite(led, HIGH);
    delay(10);
    digitalWrite(led, LOW);
    delay((float)60 / (113 + 4.5 * i) * 1000 - 10);
  }
  for (int i = 0; i < 4; i++) {
    digitalWrite(led, HIGH);
    delay(10);
    digitalWrite(led, LOW);
    delay((float)60 / 127.65 * 1000 - 10);
  }

  int et = millis();
  return (float)(st - et) / 1000;
}

int cha3() {
  int st = millis();
  for (int i = 0; i < 8; i++) {
    bar(4, 127.6944); //127.6945 too fast .6942 too slow
  }
  int et = millis();
  return (float)(st - et) / 1000;
}


int jive2() {
  int st = millis();
  for (int i = 0; i < 4; i++) {
    bar(8, 162.55); //163 too fast 162.5 too slow
  }
  int et = millis();
  return (float)(st - et) / 1000;
}

int samba2() {
  int st = millis();

  for (int i = 0; i < 4; i++) {
    bar(8, 104.2); //104.5 too fast
  }
  int et = millis();
  return (float)(st - et) / 1000;
}

int jive3() {
  int st = millis();

  for (int i = 0; i < 7; i++) {
    bar(8, 163.61); //163.63 too fast .6 too slow
  }

  // steps before walk off
  bar(4, 163.6);
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led, LOW);
  delay(1500);

  int et = millis();
  return (float)(st - et) / 1000;
}


void walk_off() {
  // Gong
  digitalWrite(led, HIGH);
  delay(1100);
  digitalWrite(led, LOW);
  delay(500);
  
  digitalWrite(led, HIGH);
  delay(10);
  digitalWrite(led, LOW);
  delay((float)60 / 123.52 * 1000 - 10);
  for (int i = 0; i < 8; i++) {
    bar(8, 123.54); // 123.53 too slow
  }
}

void bar(int beats, float bpm) {
  float beat = (float)60 / bpm * 1000;
  // 1
  digitalWrite(led, HIGH);
  delay(10);
  digitalWrite(led, LOW);
  delay(90);
  digitalWrite(led, HIGH);
  delay(10);
  digitalWrite(led, LOW);
  delay(beat - 110);

  // remaining beats
  int i;
  for (i = 2; i <= beats; i++) {
    digitalWrite(led, HIGH);
    delay(10);
    digitalWrite(led, LOW);
    delay(beat - 10);
  }
}

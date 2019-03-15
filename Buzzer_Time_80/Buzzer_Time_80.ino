/*
  Blink_Time

  An LED is blinking to the music of "Time".

*/

int buzzer = 0;
//int buzzer = 9;

int PERCENTAGE_SPEED = 100;

float slowdown = (float) PERCENTAGE_SPEED / 100;

long st_wind_up = 0 * 1000;
long st_walk_on = 4.5 * 1000 * slowdown;
long st_cha1 = 39.563 * 1000 * slowdown;
long st_paso1 = 57.384 * 1000 * slowdown;
long st_rumba1 = 76.603 * 1000 * slowdown;
long st_samba1 = 106.941 * 1000 * slowdown;
long st_cha2 = 120.598 * 1000 * slowdown;
long st_paso2 = 135.448 * 1000 * slowdown;
long st_jive1 = 151.065 * 1000 * slowdown;
long st_rumba2 = 178.898 * 1000 * slowdown;
long st_paso3 = 208.613 * 1000 * slowdown;
long st_cha3 = 221.589 * 1000 * slowdown;
long st_jive2 = 236.558 * 1000 * slowdown;
long st_samba2 = 248.367 * 1000 * slowdown;
long st_jive3 = 266.768 * 1000 * slowdown;
long st_walk_off = 302 * 1000 * slowdown; //without delay: 288.831

long len;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(buzzer, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  counting_in();
  long init_st = millis();
  long current_time = 0;
  len = wind_up();
  current_time += len; 
  next_delay(st_walk_on, current_time);
  len = walk_on();
  current_time += len; 
  next_delay(st_cha1, current_time);
  len = cha1();
  current_time += len;
  next_delay(st_paso1, current_time);
  len = paso1();
  current_time += len;
  next_delay(st_rumba1, current_time);
  len = rumba1();
  current_time += len;
  next_delay(st_samba1, current_time);
  len = samba1();
  current_time += len;
  next_delay(st_cha2, current_time);
  len = cha2();
  current_time += len;
  next_delay(st_paso2, current_time);
  len = paso2();
  current_time += len;
  next_delay(st_jive1, current_time);
  len = jive1();
  current_time += len;
  next_delay(st_rumba2, current_time);
  len = rumba2();
  current_time += len;
  next_delay(st_paso3, current_time);
  len = paso3();
  current_time += len;
  next_delay(st_cha3, current_time);
  len = cha3();
  current_time += len;
  next_delay(st_jive2, current_time);
  len = jive2();
  current_time += len;
  next_delay(st_samba2, current_time);
  len = samba2();
  current_time += len;
  next_delay(st_jive3, current_time);
  len = jive3();
  current_time += len;
  next_delay(st_walk_off, current_time);
  walk_off();
  delay(2000 * slowdown);
}

long wind_up() {
  long st = millis();
  for (int i = 0; i < 3; i++) {
    digitalWrite(buzzer, HIGH);
    delay(600 * slowdown);
    digitalWrite(buzzer, LOW);
    delay(900 * slowdown);
  }
  long et = millis();
  return et - st;
}

long walk_on() {
  long st = millis();
  for (int i = 0; i < 3; i++) {
    bar(8, 129.8, slowdown);
  }
  for (int i = 0; i < 3; i++) {
    bar(8, 129.8745, slowdown); //.8749 too fast
  }
  for (int i = 0; i < 3; i++) {
    bar(8, 129.8745, slowdown); //.8754 too fast
  }
  for (int i = 0; i < 1; i++) {
    bar(4, 129.89, slowdown); //.87 too slow
  }
  long et = millis();
  /*
  Serial.print("st: ");
  Serial.print(st);
  Serial.print("et: ");
  Serial.print(et);
  */
  return et - st;
}

long cha1() {
  long st = millis();
  bar(4, 123, slowdown); // 98 too slow
  for (int i = 1; i < 5; i++) {
    bar(4, 120.9675, slowdown); //9677 too fast
  }
  for (int i = 0; i < 2; i++) {
    bar(8, 120.9677, slowdown);
  }
  long et = millis();
  return et - st;
}

long paso1() {
  long st = millis();
  for (int i = 0; i < 4; i++) {
    bar(8, 120.96556, slowdown); //.96555 too slow
  }
  // fade into rumba
  digitalWrite(buzzer, HIGH);
  delay(160);
  digitalWrite(buzzer, LOW);
  delay(((float)60 / 120.9 * 1000 * slowdown) - 160);

  for (int i = 1; i < 5; i++) {
    digitalWrite(buzzer, HIGH);
    delay(80);
    digitalWrite(buzzer, LOW);
    delay(((float)60 / (120.9 - 5 * i) * 1000) * slowdown - 80);
  }
  digitalWrite(buzzer, HIGH);
  delay(80);
  digitalWrite(buzzer, LOW);
  delay(((float)60 / 95 * 1000) * slowdown - 80);

  long et = millis();
  return et - st;
}

long rumba1() {
  long st = millis();
  for (int i = 0; i < 12; i++) {
    bar(4, 94.909, slowdown); //.9 too slow .91 too fast
  }
  long et = millis();
  return et - st;
}

long samba1() {
  long st = millis();
  for (int i = 0; i < 3; i++) {
    bar(8, 105.436, slowdown); //.434 too slow .435 too fast
  }
  long et = millis();
  return et - st;
}


long cha2() {
  long st = millis();
  for (int i = 0; i < 7; i++) {
    bar(4, 129.27, slowdown); //.28 too fast
  }

  // Stretch into paso
  bar(4, 129.27, slowdown);
  long et = millis();
  return et - st;
}


long paso2() {
  long st = millis();
  for (int i = 0; i < 4; i++) {
    bar(8, 122.882, slowdown); //.883 too fast
  }
  long et = millis();
  return et - st;
}

long jive1() {
  long st = millis();
  // ticks into Jive
  bar(4, 163.449, slowdown);//.44 too slow .45 too fast

  for (int i = 0; i < 8; i++) {
    bar(8, 163.3275, slowdown); // .327<*<.4
  }

  // fade into rumba
  digitalWrite(buzzer, HIGH);
  delay(160);
  digitalWrite(buzzer, LOW);
  delay(((float)60 / 163.6 * 1000) * slowdown - 160);

  for (int i = 1; i < 4; i++) {
    digitalWrite(buzzer, HIGH);
    delay(80);
    digitalWrite(buzzer, LOW);
    delay(((float)60 / 163.6 * 1000) * slowdown - 80);
  }
  for (int i = 0; i < 2; i++) {
    digitalWrite(buzzer, HIGH);
    delay(80);
    digitalWrite(buzzer, LOW);
    delay(((float)60 / 85 * 1000) * slowdown - 80);
  }

  long et = millis();
  return et - st;
}

long rumba2() {
  long st = millis();
  for (int i = 0; i < 12; i++) {
    bar(4, 96.855, slowdown); //.845 too slow
  }
  long et = millis();
  return et - st;
}

long paso3() {
  long st = millis();
  bar(8, 102, slowdown);
  bar(4, 107, slowdown);
  for (int i = 0; i < 4; i++) {
    digitalWrite(buzzer, HIGH);
    delay(80);
    digitalWrite(buzzer, LOW);
    delay(((float)60 / (107 + 2 * (i + 1)) * 1000) * slowdown - 80);
  }
  digitalWrite(buzzer, HIGH);
  delay(160);
  digitalWrite(buzzer, LOW);
  delay(((float)60 / 112 * 1000) * slowdown - 160);
  for (int i = 1; i < 4; i++) {
    digitalWrite(buzzer, HIGH);
    delay(80);
    digitalWrite(buzzer, LOW);
    delay(((float)60 / (113 + 4.5 * i) * 1000) * slowdown - 80);
  }
  for (int i = 0; i < 4; i++) {
    digitalWrite(buzzer, HIGH);
    delay(80);
    digitalWrite(buzzer, LOW);
    delay(((float)60 / 127.65 * 1000) * slowdown - 80);
  }

  long et = millis();
  return et - st;
}

long cha3() {
  long st = millis();
  for (int i = 0; i < 7; i++) {
    bar(4, 127.6944, slowdown); //127.6945 too fast .6942 too slow
  }
  bar(3, 127.6944, slowdown); //127.6945 too fast .6942 too slow
  digitalWrite(buzzer, HIGH);
  delay(80);
  digitalWrite(buzzer, LOW);
  delay(((float)60 / 140 * 1000) * slowdown - 80);
  long et = millis();
  return et - st;
}


long jive2() {
  long st = millis();
  for (int i = 0; i < 4; i++) {
    bar(8, 162.55, slowdown); //163 too fast 162.5 too slow
  }
  long et = millis();
  return et - st;
}

long samba2() {
  long st = millis();

  for (int i = 0; i < 4; i++) {
    bar(8, 104.2, slowdown); //104.5 too fast
  }
  long et = millis();
  return et - st;
}

long jive3() {
  long st = millis();

  for (int i = 0; i < 7; i++) {
    bar(8, 163.599, slowdown); //163.602 too fast .6 too slow //.595
  }

  // steps before walk off
  bar(4, 163.6, slowdown);
  digitalWrite(buzzer, HIGH);
  delay(100 * slowdown);
  digitalWrite(buzzer, LOW);

  long et = millis();
  return et - st;
}


void walk_off() {
  // Gong
  digitalWrite(buzzer, HIGH);
  delay(1100 * slowdown);
  digitalWrite(buzzer, LOW);
  delay(482 * slowdown);

  digitalWrite(buzzer, HIGH);
  delay(80);
  digitalWrite(buzzer, LOW);
  delay(((float)60 / 123.52 * 1000) * slowdown - 80);
  for (int i = 0; i < 8; i++) {
    bar(8, 123.65, slowdown); // 123.56 too slow
  }
}

void counting_in() {
  long count_beat = ((float)60 / 49.7 * 1000) * slowdown;
  digitalWrite(buzzer, HIGH);
  delay(160);
  digitalWrite(buzzer, LOW);
  delay(count_beat - 160);

  // remaining beats
  int i;
  for (i = 2; i < 4; i++) {
    digitalWrite(buzzer, HIGH);
    delay(80);
    digitalWrite(buzzer, LOW);
    delay(count_beat - 80);
  }
    digitalWrite(buzzer, HIGH);
    delay(80);
    digitalWrite(buzzer, LOW);
    delay(count_beat - 80 - 140); // 170 too short
}

void next_delay(long next_time, long current_time) 
{
    long total_delay = next_time - current_time;
    
    delay(max(total_delay, 0));
}

void bar(int beats, float bpm, float slowdown) {
  float beat = ((float)60 / bpm * 1000) * slowdown;
  // 1
  digitalWrite(buzzer, HIGH);
  delay(160);
  /*
  digitalWrite(buzzer, LOW);
  delay(60);
  digitalWrite(buzzer, HIGH);
  delay(40);
  */
  digitalWrite(buzzer, LOW);
  delay(beat - 160);

  // remaining beats
  int i;
  for (i = 2; i <= beats; i++) {
    digitalWrite(buzzer, HIGH);
    delay(80);
    digitalWrite(buzzer, LOW);
    delay(beat - 80);
  }
}

#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;

int o=175;
int c =-175;


int const len = 10;
float mean;
int value1 ;
int value2 ;
float result ;
int Move = 0;
float means[5];
float error[5];
//----------------------------------------
//these values = emg value 1/ emg value2
// we take the last 100 readings coming from emgs and record it for each movement
float values[len];

void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);
    myservo1.attach(3);
  myservo2.attach(5);
  myservo3.attach(6);
  myservo4.attach(9);
  myservo5.attach(10);
}

void loop() {
  
  //determine the mode
  if (digitalRead(2) == HIGH) {
    store_data(0);
    Serial.println(means[0]);
  }
  else if (digitalRead(3) == HIGH) {
    store_data(1);
    Serial.println(means[1]);
  }
  else if (digitalRead(4) == HIGH) {
    store_data(2);
    Serial.println(means[2]);
  }
  else if (digitalRead(5) == HIGH) {
    store_data(3);
    Serial.println(means[3]);
  }
  else if (digitalRead(6) == HIGH) {
    store_data(4);
    Serial.println(means[4]);
  }
  else if (digitalRead(7) == HIGH) {
    data_in();
    choose();
    order_to_motors();
  }
  else{
    test_emg();
  }
}
void data_in() {
  value1 = analogRead(A0);
  value2 = analogRead(A1);
  result = (float)(value2+1) / (float)(value1+1);
  values[len - 1] = result;
  for (int i = 0; i < len - 1; i++) {
    values[i] = values[i + 1];
  }
  if (values[0] > 0) {
    for (int i = 0; i < len; i++) {
      mean += values[i];
    }
    mean = mean / (float)len;
  }

}
void choose()
{
  float minimum = 1000;
  for (int i = 0; i < 5; i++) {
    error[i] = abs(mean - means[i]);
    if (error[i] < minimum) {
      minimum = error[i];
      Move = i;
    }
  }
}
void order_to_motors() {
  switch (Move) {
    case 0:
       myservo1.write(o);
       myservo2.write(o);
       myservo3.write(o);
       myservo4.write(o);
       myservo5.write(o);
      Serial.println("open");
      break;
    case 1:
       myservo1.write(c);
       myservo2.write(c);
       myservo3.write(c);
       myservo4.write(c);
       myservo5.write(c); 
      Serial.println("fist");
      break;
    case 2:
       myservo1.write(o);
       myservo2.write(c);
       myservo3.write(c);
       myservo4.write(c);
       myservo5.write(c); 
      Serial.println("thumb");
      break;
    case 3:
       myservo1.write(o);
       myservo2.write(c);
       myservo3.write(c);
       myservo4.write(c);
       myservo5.write(o);
      Serial.println("love");
      break;
    case 4:
       myservo1.write(o);
       myservo2.write(o);
       myservo3.write(o);
       myservo4.write(c);
       myservo5.write(c);  
      Serial.println("three");
      break;
  }
}
void store_data(int the_mean) {
  data_in();
  means[the_mean] = mean;
}
void test_emg(){
  delay(250);
    int value1 = analogRead(A0);
    int value2 = analogRead(A1);
    //
    float result = (float)value2 / (float)value1;
    Serial.println(value1);
    Serial.println(value2);
    Serial.println(result);
    Serial.println("--------------------");
  }


void order_to_motors() {
  switch (Move) {
    case 0:
       myservo1.write(o);
       myservo2.write(o);
       myservo3.write(o);
       myservo4.write(o);
       myservo5.write(o);
      Serial.println("open");
      break;
    case 1:
       myservo1.write(c);
       myservo2.write(c);
       myservo3.write(c);
       myservo4.write(c);
       myservo5.write(c); 
      Serial.println("fist");
      break;
    case 2:
       myservo1.write(o);
       myservo2.write(c);
       myservo3.write(c);
       myservo4.write(c);
       myservo5.write(c); 
      Serial.println("thumb");
      break;
    case 3:
       myservo1.write(o);
       myservo2.write(c);
       myservo3.write(c);
       myservo4.write(c);
       myservo5.write(o);
      Serial.println("love");
      break;
    case 4:
       myservo1.write(o);
       myservo2.write(o);
       myservo3.write(o);
       myservo4.write(c);
       myservo5.write(c);  
      Serial.println("three");
      break;
  }
}

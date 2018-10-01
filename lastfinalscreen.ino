#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 7, d7 = 6,pingPin = 8,echoPin = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte LED = 13;
const byte send_pin = 10;
const byte BUTTON = 2;

char ch[20] = "I'm Smart Dustbin";

void switchPressed ()
{
    if (digitalRead (BUTTON) == HIGH){
    digitalWrite (LED, HIGH);
    }else{
    digitalWrite (LED, LOW);
    }
}

byte eyes0[8] = {
  B00000,
  B00100,
  B01010,
  B10001,
  B01010,
  B00100,
  B00000,
};

byte eyes1[8] = {
  B00000,
  B00000,
  B01110,
  B10001,
  B01110,
  B00000,
  B00000,
};

byte eyes2[8] = {
  B00000,
  B00000,
  B00000,
  B11111,
  B00000,
  B00000,
  B00000,
};

byte eyes3[8] = {
  B00000,
  B00000,
  B00100,
  B01000,
  B10000,
  B01000,
  B00100,
  B00000
};

byte eyes4[8] = {
  B00000,
  B00000,
  B00100,
  B01000,
  B01000,
  B01000,
  B00100,
  B00000
};

byte eyes5[8] = {
  B00000,
  B00000,
  B00100,
  B00010,
  B00010,
  B00010,
  B00100,
  B00000
};

byte eyes6[8] = {
  B00000,
  B00000,
  B00100,
  B00010,
  B00001,
  B00010,
  B00100,
  B00000
};

byte smile[8] = {
  B00000,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000,
};

void setup() {
  pinMode (LED, OUTPUT);  // so we can update the LED
   pinMode (send_pin, OUTPUT);
  digitalWrite (BUTTON, HIGH);  // internal pull-up resistor
  attachInterrupt (digitalPinToInterrupt (BUTTON), switchPressed, CHANGE);  // attach interrupt handler
  delay(3000);
  lcd.begin(16, 2);
  lcd.createChar(0, eyes0);
  lcd.createChar(1, eyes1);
  lcd.createChar(2, eyes2);
  lcd.createChar(3, smile);
  lcd.createChar(4, eyes3);
  lcd.createChar(5, eyes4);
  lcd.createChar(6, eyes5);
  lcd.createChar(7, eyes6);
  Serial.begin(9600);
  delay(5000);
  lcd.write(byte(0));
  lcd.setCursor(2,0);
  lcd.write(byte(1));
  lcd.setCursor(1,1);
  lcd.write(byte(3));
  lcd.setCursor(4,0);
  lcd.print("Hello! There");
}

void loop(){
  int duration, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   cm = microsecondsToCentimeters(duration);
   if(cm>14){
    cm=3;
   }
   if(cm<3){
    cm=3;
   }
   Serial.print(cm);
   if(cm<=14 && cm>=3){
     //Serial.print(cm);
     int p = map(cm, 3, 14, 100, 0);
     int q = map(p,100,0,1,10);
     if(cm<=5){
      digitalWrite(send_pin,HIGH);
      delay(100);
      digitalWrite(send_pin,LOW);
     }
     Serial.print("cm");
     Serial.println();
     Serial.print("maped:");
     Serial.print(p);
     lcd.setCursor(4,1);
     lcd.print("#############");
     for(int i=10;i>0;i--){
      lcd.setCursor(4+i,1);
      lcd.print(" ");
      delay(100);
     }
     for(int i=0;i<q;i++){
      lcd.setCursor(4+i,1);
      lcd.print("#");
      delay(100);
     }
     lcd.setCursor(13, 1);
     lcd.print("   ");
     lcd.setCursor(13, 1);
     lcd.print(p);
     Serial.println();
     delay(2000);
   }
   for(int i=0;i<2;i++){
    lcd.setCursor(0,0);
    lcd.write(byte(0));
    lcd.setCursor(2,0);
    lcd.write(byte(0));
    delay(2000);
    lcd.setCursor(4,0);
    lcd.print("            ");
    lcd.setCursor(4,0);
    lcd.print("Use Me");
    lcd.setCursor(0,0);
    lcd.write(byte(1));
    lcd.setCursor(2,0);
    lcd.write(byte(1));
    delay(100);
    lcd.setCursor(0,0);
    lcd.write(byte(2));
    lcd.setCursor(2,0);
    lcd.write(byte(2));
    delay(100);
    lcd.setCursor(0,0);
    lcd.write(byte(0));
    lcd.setCursor(2,0);
    lcd.write(byte(0));
    delay(250);
    lcd.setCursor(0,0);
    lcd.write(byte(1));
    lcd.setCursor(2,0);
    lcd.write(byte(1));
    delay(100);
    lcd.setCursor(0,0);
    lcd.write(byte(2));
    lcd.setCursor(2,0);
    lcd.write(byte(2));
    delay(100);
  }
  lcd.setCursor(0,0);
  lcd.write(byte(0));
  lcd.setCursor(2,0);
  lcd.write(byte(0));
  lcd.setCursor(4,0);
  lcd.print("             ");
  for(int i=16;i>3;i--){
    lcd.setCursor(i,0);
    lcd.print(ch);
    delay(130);
  }
  int e=1;
  for(int i=0;i<4;i++){
    lcd.setCursor(4,0);
    int f=4;
    for(int j=e;j<18;j++){
      lcd.print(ch[j]);
      lcd.setCursor(f++,0);
    }
    delay(130);
    e++;
  }
  for(int i=0;i<1;i++){
  lcd.setCursor(0,0);
  lcd.write(byte(4));
  lcd.setCursor(2,0);
  lcd.write(byte(4));
  delay(1000);
  lcd.print("            ");
  lcd.setCursor(4,0);
  lcd.print("Hello! There");
  lcd.setCursor(0,0);
  lcd.write(byte(5));
  lcd.setCursor(2,0);
  lcd.write(byte(5));
  delay(70);
  lcd.setCursor(0,0);
  lcd.write(byte(6));
  lcd.setCursor(2,0);
  lcd.write(byte(6));
  delay(70);
  lcd.setCursor(0,0);
  lcd.write(byte(7));
  lcd.setCursor(2,0);
  lcd.write(byte(7));
  delay(1000);
  lcd.setCursor(0,0);
  lcd.write(byte(6));
  lcd.setCursor(2,0);
  lcd.write(byte(6));
  delay(70);
  lcd.setCursor(0,0);
  lcd.write(byte(5));
  lcd.setCursor(2,0);
  lcd.write(byte(5));
  delay(70);}
  delay(1000);
}

double microsecondsToCentimeters(double microseconds) {
   return microseconds / 29 / 2;
}

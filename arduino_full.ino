#include <LiquidCrystal_I2C.h>
int sensorValue = 0;
int inPin = 2;
char s1[] = "GOOD SHOT!";
char s2[] = "BALL TO PLAYER";
char s3[] = "J.F. AUTO-POOL";
char s4[] = "SYSTEM";
byte fc[] = {0, 0, 0, 0, 0, 0, 0, 0}
byte sc[] = {0, 0, 0, 0, 0, 0, 0, 0}
byte flag = 0;
byte gameStarted = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  Serial.begin(9600);
  pinMode(inPin, INPUT);
  lcd.init();
             
  lcd.backlight();      
  lcd.setCursor(1, 0);
  for (int i = 0; i < strlen(s3); i++) {
    lcd.print(s3[i]);
    delay(100);
  }
  lcd.setCursor(4, 1);
  for (int i = 0; i < strlen(s4); i++) {
    lcd.print(s4[i]);
    delay(100);
  }
  delay(2000);
  lcd.clear();
  
}

void loop() {
  if (digitalRead(inPin) == 1)
  {
    lcd.setCursor(3, 0);
    for (int i = 0; i < strlen(s1); i++) {
      lcd.print(s1[i]);
      delay(100);
    }
    lcd.setCursor(1, 1);
    for (int i = 0; i < strlen(s2); i++) {
      lcd.print(s2[i]);
      delay(100);
    }
    delay(5000);
  }
  lcd.clear();
}

#include <LiquidCrystal_I2C.h>
int sensorValue = 0;
int inPin = 2;
char s1[] = "GOOD SHOT!";
char s2[] = "BALL TO PLAYER";
char s3[] = "J.F. AUTO-POOL";
char s4[] = "SYSTEM";
char s5[] = "PRESS BLUE BUT";
char s6[] = "FIRST WON";
char s7[] = "SECOND WON";
char s8[] = "NEXT PLAYER";
char s9[] = "MINUS BALL";
char s10[] = "PLAYER 1";
char s11[] = "PLAYER 2";
char s12[] = "FIRST LOST";
char s13[] = "SECOND LOST";
byte fc = 0;
byte sc = 0;
byte flag = 0;
byte gameStarted = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  Serial.begin(9600);
  // Кнопка начала игры.
  pinMode(5, INPUT);
  // Кнопка для смены команды.
  pinMode(6, INPUT);
  // Кнопка выставления шара.
  pinMode(7, INPUT);
  // Датчик чувствительности - фоторезистор.
  pinMode(8, INPUT);
  // Кнопка черного шара.
  pinMode(9, INPUT);
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
  int readL = digitalRead(5);
  if (gameStarted == 1)
  {
    int readS = digitalRead(6);
    int readK = digitalRead(7);
    int readB = digitalRead(9);
    if(readB == 1)
    {
      if (flag == 0)
      {
        printLost1();
      }
      else
      {
        printLost2();
      }
      fc = 0;
      sc = 0;
      flag = 0;
      gameStarted = 0;
    }
    if(readS == 1)
    {
      printNext();
      if (flag == 0)
      {
        flag = 1;
      }
      else
      {
        flag = 0;
      }
    }
    if (readK == 1)
    {
      if (flag == 0 && fc > 0)
      {
        printMinBall1();
        fc -= 1;
      }
      else if (flag == 1 && sc > 0)
      {
        printMinBall2();
        sc -= 1;
      }
      delay(2000);
    }
    if (digitalRead(8) == 1)
    {
      if (flag == 0){
        fc += 1;
      }
      else if(flag == 1){
        sc += 1;
      }
      delay(100);
      printAdd();
      if (fc == 9 || sc == 9)
      {
        if (fc == 9)
        {
          printFirstWon();
        }
        else
        {
          printSecondWon();
        }
        fc = 0;
        sc = 0;
        flag = 0;
        gameStarted = 0;
      }
    }
  }
  else
    {
      printStartWords();
      Serial.println(readL);
      if (readL == 1)
      {
        gameStarted = 1;
      }
    }
  lcd.clear();
}

void printAdd(){
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
    lcd.clear();   
}
void printStartWords(){
  lcd.setCursor(1, 0);
  for (int i = 0; i < strlen(s5); i++)
  {
    lcd.print(s5[i]);
    delay(10);
  }
  delay(5000);
  lcd.clear();
}

void printFirstWon(){
  lcd.setCursor(1, 0);
  for (int i = 0; i < strlen(s6); i++)
  {
    lcd.print(s6[i]);
    delay(100);
  }
  delay(5000);
  lcd.clear();
}

void printSecondWon(){
  lcd.setCursor(1, 0);
  for (int i = 0; i < strlen(s7); i++)
  {
    lcd.print(s7[i]);
    delay(100);
  }
  delay(5000);
  lcd.clear();
}
void printNext()
{
  lcd.setCursor(1, 0);
  for (int i = 0; i < strlen(s8); i++)
  {
    lcd.print(s8[i]);
    delay(100);
  }
  delay(5000);
  lcd.clear();
}

void printMinBall1()
{
  lcd.setCursor(1, 0);
  for (int i = 0; i < strlen(s9); i++)
  {
    lcd.print(s9[i]);
    delay(100);
  }
  lcd.setCursor(1, 1);
  for (int i = 0; i < strlen(s10); i++)
  {
    lcd.print(s10[i]);
    delay(100);
  }
  delay(5000);
  lcd.clear();
}

void printMinBall2()
{
  lcd.setCursor(1, 0);
  for (int i = 0; i < strlen(s9); i++)
  {
    lcd.print(s9[i]);
    delay(100);
  }
  lcd.setCursor(1, 1);
  for (int i = 0; i < strlen(s11); i++)
  {
    lcd.print(s11[i]);
    delay(100);
  }
  delay(5000);
  lcd.clear();
}

void printLost1()
{
  lcd.setCursor(1, 0);
  for (int i = 0; i < strlen(s12); i++)
  {
    lcd.print(s12[i]);
    delay(100);
  }
  delay(5000);
}

void printLost2()
{
  lcd.setCursor(1, 0);
  for (int i = 0; i < strlen(s13); i++)
  {
    lcd.print(s13[i]);
    delay(100);
  }
  delay(5000);
}
  

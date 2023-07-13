#include<LiquidCrystal.h>
  LiquidCrystal lcd(12,11,5,4,3,2);
#include <Keypad.h>
  const byte ROWS=4;
  const byte COLS=3;
  char hexaKeys[ROWS][COLS] = {
   {'A','B','C'},
   {'D','E','F'},
   {'G','8','9'},
   {'*','5','#'},
  };
  byte rowPins[ROWS] = {7 , 6 , 1 , 0};
  byte colPins[COLS] = {10 , 9 , 8};
  Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup() {
   //put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(13, INPUT);
}

void loop() {
   //put your main code here, to run repeatedly:
   int note;
  while(1){  
    char customKey = customKeypad.getKey();
     
    if (customKey=='A'){
      lcd.clear();
      lcd.setCursor(7,0);
      lcd.print("La");
      note=2272;
    }
    else if (customKey=='B'){
      lcd.clear();
      lcd.setCursor(7,0);
      lcd.print("Si");
      note=2024;
    }
    else if (customKey=='C'){
      lcd.clear();
      lcd.setCursor(7,0);
      lcd.print("Do");
      note=3822;
    }
    else if (customKey=='D'){
      lcd.clear();
      lcd.setCursor(7,0);
      lcd.print("Re");
      note=3405;
    }
    else if (customKey=='E'){
      lcd.clear();
      lcd.setCursor(7,0);
      lcd.print("Mi");
      note=3033;
    }
    else if (customKey=='F'){
      lcd.clear();
      lcd.setCursor(7,0);
      lcd.print("Fa");
      note=2863;
    }
    else if (customKey=='G'){
      lcd.clear();
      lcd.setCursor(7,0);
      lcd.print("Sol");
      note=2551;
    }
    else if (customKey=='#'){
      break;
    } 
  }
  while(1){
    int i=0;
    int duration=0;
    while(i<10){
    unsigned long d = pulseInLong(13, HIGH);
    duration=duration+d;
    i++; 
    }
    duration=duration/10;
    
    int a=duration-note;
    lcd.setCursor(0,1);
        
    if(a>-20 && a<20){
      lcd.print("--------|--------");
      delay(100);
    }
    else if(a>-30 && a<-20){
      lcd.print("---------|-------");
      delay(100);
    }
    else if(a<30 && a>20){
      lcd.print("-------|---------");
      delay(100);
    }
    else if(a>-40 && a<-30){
      lcd.print("----------|------");
      delay(100);
    }
    else if(a<40 && a>30){
      lcd.print("------|----------");
      delay(100);
    }
    else if(a>-50 && a<-40){
      lcd.print("-----------|-----");
      delay(100);
    }
    else if(a<50 && a>40){
      lcd.print("-----|-----------");
      delay(100);
    }
    else if(a>-60 && a<-50){
      lcd.print("------------|----");
      delay(100);
    }
    else if(a<60 && a>50){
      lcd.print("----|------------");
      delay(100);
    }
    else if(a>-70 && a<-60){
      lcd.print("-------------|---");
      delay(100);
    }
    else if(a<70 && a>60){
      lcd.print("---|-------------");
      delay(100);
    }
    else if(a>-80 && a<-70){
      lcd.print("--------------|--");
      delay(100);
    }
    else if(a<80 && a>70){
      lcd.print("--|--------------");
      delay(100);
    }
    else if(a<-80){
      lcd.print("---------------|-");
      delay(100);
    }
    else if(a>80){
      lcd.print("-|---------------");
      delay(100);
    }
    
    char customKey = customKeypad.getKey();
    if (customKey=='#'){
      lcd.clear();
      break;
    }
   
  }
   
}

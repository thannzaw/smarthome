#include<Keypad.h>
#include<Servo.h>
#include <Wire.h>
#include<Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>// import the Software serial library
char ch;
 // the data given from Computer
int in1 =2;
int in2 =3;
int in3 =4;
int in4 =5;
int in5 =6;
int in6 =7;
int in7 =8;
int in8 =9;
SoftwareSerial bluetooth(0,1); // RX, TX

#define GreenLED 11

LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE );
char* password="1234";
int Position= 0;

const byte rows=4;
const byte cols=4;

char keyMap [rows][cols]={
 {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
 
  };

  byte rowPins [rows]={22,23,24,25};
  byte colPins [cols]={26,27,28,29};

  Keypad myKeypad=Keypad(makeKeymap(keyMap),rowPins,colPins,rows,cols);
void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Goodnight moon!");
  bluetooth.begin(9600);
  bluetooth.println("Bluetooth On please press 1 or 0 blink LED ..");
    lcd.begin(16,2);
    pinMode(GreenLED,OUTPUT);
    DoorLocked(true);
    pinMode(in1,OUTPUT);
 pinMode(in2,OUTPUT);
 pinMode(in3,OUTPUT);
 pinMode(in4,OUTPUT);
 pinMode(in5,OUTPUT);
 pinMode(in6,OUTPUT);
 pinMode(in7,OUTPUT);
 pinMode(in8,OUTPUT);
digitalWrite(in2,HIGH);
digitalWrite(in3,HIGH);
digitalWrite(in4,HIGH);
digitalWrite(in5,HIGH);
digitalWrite(in6,HIGH);
digitalWrite(in7,HIGH);
digitalWrite(in8,HIGH);
}
void loop() 
{
  
 if (bluetooth.available()) {
    //Serial.println("bluetooth sending");
    ch=bluetooth.read();
    Serial.println(ch);
     if (Serial.available()) {
    bluetooth.write(Serial.read());
  }
    if(ch=='1')
    {
      garden();
    }
    else if(ch=='2')
    {
      light1();
    }
    else if(ch=='3')
    {
      light2();
    }
    else if(ch=='4')
    {
      light3();
    }
    else if(ch=='5')
    {
      light4();
    }
    else if(ch=='6')
    {
     light5();
    }
    else if(ch=='7')
    {
      light6();
    }
    else if(ch=='8')
    {
      door();
    }
        else if(ch=='a')
    {
      gardenoff();
    }
     else if(ch=='b')
    {
      light1off();
    }
    else if(ch=='c')
    {
      light2off();
    }
    else if(ch=='d')
    {
      light3off();
    }
    else if(ch=='e')
    {
      light4off();
    }
    else if(ch=='f')
    {
     light5off();
    }
    else if(ch=='f')
    {
      light6off();
    }
    else if(ch=='g')
    {
      dooroff();
    }
  }
 
  char passcode=myKeypad.getKey();
   lcd.setCursor(0,0);
      lcd.print("Welcome Honey!!!");
      lcd.setCursor(0,1);
      lcd.print("  Enter Password  ");
   if( passcode =='*' || passcode== '#'|| passcode== 'A' || passcode=='B' || passcode=='C' ||passcode =='D') 
 {        
        Position=0;
        DoorLocked(true);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Access Denied");
        delay(1000);
        lcd.clear();
       
        }
        if(passcode==password[Position]){
          Position ++;
          
          }
          if(Position ==4){
            
            DoorLocked(false);
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Access Granted");
           
           digitalWrite(in8,LOW);
           delay(5000);
           digitalWrite(in8,HIGH);
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Warmly Welcome");
            lcd.setCursor(0,1);
            lcd.print("From TU(Myeik)");
            delay(5000);
            lcd.clear();            
}
   delay(100); 
}

void DoorLocked(int locked){
  
  if(locked){
    
    digitalWrite(GreenLED,LOW);
    
    }else{
      digitalWrite(GreenLED,HIGH); 
}
}
void garden()
{
  Serial.println("garden off");
   digitalWrite(in1,HIGH); 
          
        bluetooth.println("garden Off ! ");
}
void light1()
{
    Serial.println("light1 off");
    digitalWrite(in2,HIGH); 
          
        bluetooth.println("light1 Off ! ");
}
void light2()
{
    Serial.println("light2 off");
    digitalWrite(in3,HIGH); 
          
        bluetooth.println("light2 Off ! ");
}
void light3()
{
    Serial.println("light3 off");
    digitalWrite(in4,HIGH); 
          
        bluetooth.println("light3 Off ! ");
}
void light4()
{
    Serial.println("light4 off");
    digitalWrite(in5,HIGH); 
          
        bluetooth.println("light4 Off ! ");
}
void light5()
{
    Serial.println("light5 off");
    digitalWrite(in6,HIGH); 
          
        bluetooth.println("light5 Off ! ");
}
void light6()
{
    Serial.println("light6 off");
    digitalWrite(in7,HIGH); 
          
        bluetooth.println("light6 Off ! ");
}
void door()
{
    Serial.println("door off");
    digitalWrite(in8,HIGH); 
          
        bluetooth.println("door Off ! ");
}


void gardenoff()
{
  Serial.println("garden on");
   digitalWrite(in1,LOW); 
          
        bluetooth.println("gardenoff ! ");
}
void light1off()
{
    Serial.println("light1 on");
    digitalWrite(in2,LOW); 
          
        bluetooth.println("light1 ! ");
}
void light2off()
{
    Serial.println("light2 on");
    digitalWrite(in3,LOW); 
          
        bluetooth.println("light2 Off ! ");
}

void light3off()
{
    Serial.println("light3");
    digitalWrite(in4,LOW); 
          
        bluetooth.println("light3 Off !");
}
void light4off()
{
    Serial.println("light4 on");
    digitalWrite(in5,LOW); 
          
        bluetooth.println("light4 Off ! ");
}
void light5off()
{
    Serial.println("light5 on");
    digitalWrite(in6,LOW); 
          
        bluetooth.println("light6 Off ! ");
}
void light6off()
{
    Serial.println("light6 on");
    digitalWrite(in7,LOW); 
          
        bluetooth.println("garden Off ! ");
}

void dooroff()
{
    Serial.println("door on");
    digitalWrite(in8,LOW); 
          
        bluetooth.println("door ON ! ");
}

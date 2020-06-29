#include <DS3231.h> #include<LiquidCrystal.h> LiquidCrystal lcd(8,6,5,4,3,2); DS3231 rtc(SDA, SCL);
const int button=53; int toggle=0;
String t; void setup()
{ 
Serial.begin(115200); 
pinMode(7,OUTPUT); 
digitalWrite(7,LOW); 
pinMode(11,OUTPUT); 
pinMode(button,INPUT);
//Serial.begin(9600); 
lcd.begin(16,2); 
lcd.setCursor(0,0); 
lcd.print("Initialising."); 
delay(1000); 
lcd.clear(); 
lcd.print("Initialising.."); 
delay(1000); 
lcd.clear(); 
lcd.print("Initialising..."); 
delay(1000); 
lcd.clear();

rtc.begin(); 
rtc.setDOW(WEDNESDAY);
rtc.setTime(12, 29, 00);

rtc.setDate(30, 10, 2019); 
} 

void loop() 
{ 
toggle=digitalRead(button); 
Serial.println(toggle); 
lcd.clear(); 
lcd.setCursor(0,0); 
lcd.print("Day: "); 
lcd.print(rtc.getDOWStr()); 
lcd.print(" "); 
lcd.setCursor(0,1);
//lcd.print(rtc.getDateStr());

//lcd.print(" -- ");

lcd.print("Time: "); 
lcd.println(rtc.getTimeStr()); 
delay (1000); 
t=rtc.getTimeStr(); 
if(t[6]=='1' && t[7]=='0')
{ 
lcd.clear(); 
lcd.setCursor(0,0); 
lcd.print("Medicine 1"); 
while(toggle!=1)
{ 
digitalWrite(11,HIGH); 
digitalWrite(21,HIGH); 
delay(500); 
digitalWrite(21,LOW); 
digitalWrite(11,LOW); 
delay(500);

if(digitalRead(button))
{ toggle=1; delay(500); } 
} 
toggle=0; 
}
if(t[6]=='2' && t[7]=='5')

{ 
lcd.clear(); 
lcd.setCursor(0,0); 
lcd.print("Medicine 2"); 
while(toggle!=1)
{ 
digitalWrite(11,HIGH); 
digitalWrite(29,HIGH); 
delay(500); 
digitalWrite(29,LOW); 
digitalWrite(11,LOW); 
delay(500); 
if(digitalRead(button))
{ toggle=1; delay(500); } 
} 
toggle=0; 
}

if(t[6]=='4' && t[7]=='5')
{ 
lcd.clear(); 
lcd.setCursor(0,0); 
lcd.print("Medicine 3"); 
while(toggle!=1)
{ 
digitalWrite(11,HIGH); 
digitalWrite(39,HIGH); 
delay(500); 
digitalWrite(39,LOW); 
digitalWrite(11,LOW); 
delay(500);

if(digitalRead(button))

{ 
toggle=1; 
delay(500); 
} 
}
toggle=0; 
}

if(t[6]=='5' && t[7]=='9')

{ 
lcd.clear(); 
lcd.setCursor(0,0); 
lcd.print("Medicine 4"); 
while(toggle!=1)
{ 
digitalWrite(11,HIGH); 
digitalWrite(47,HIGH); 
delay(500); 
digitalWrite(47,LOW); 
digitalWrite(11,LOW); 
delay(500); 
if(digitalRead(button))
{ 
toggle=1; 
delay(500); 
} 
} 
toggle=0; 
}
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////keypad and lcd
#include <LiquidCrystal.h>
#include <Keypad.h>
// digital pins for LCD display 
LiquidCrystal lcd(2,3,4,5,6,7);

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
	{'1','2','3'},
	{'4','5','6'},
	{'7','8','9'},
	{'*','0','#'}
	};
//key pad conected to pins 22-28
byte rowPins[ROWS] = {28,27,26,25}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {24,23,22}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 
 
 
///////////////////////////////////////////////////////////////////////////////
// Date and time functions using just software, based on millis() & timer
//Connected to pins A6-A7
#include <Wire.h>
#include "RTClib.h"
RTC_Millis RTC;


//////////////////////////////////////////////////////////////////////////////
////////////For DHT11 Temp and Humidity

#include "DHT.h"
#define DHTPIN 52     

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTPIN, DHTTYPE);

//***********************************************************//
// digital Pins Outlets are hooked up to
int Outlet1 =8;
int Outlet2 = 9;
int Outlet3 = 10;
int Outlet4 = 34;
int Outlet5 =30;
int incomingByte; 
//**********************************************************//

 
void setup()
{
  //start communication
  Serial.begin(9600);
  
  // set digital pins as outputs to switch relays
  pinMode(Outlet1, OUTPUT);
  pinMode(Outlet2, OUTPUT);
  pinMode(Outlet3, OUTPUT); 
  pinMode(Outlet4, OUTPUT);
  pinMode(Outlet5, OUTPUT);

  //for keypad
  keypad.addEventListener(keypadEvent); //add an event listener for this keypad
  lcd.begin(20,4);
  lcd.print("Created by: Carlos  ");
  lcd.print("Capstone Project    ");
  lcd.print("120VAC SwitchBox    ");
  lcd.print("v1.0                ");
  delay(3500);
  lcd.clear();
  lcd.begin(20,4);
  lcd.print("<<<SWITCHBOX MENU>>>");
  lcd.setCursor(0,1);
  lcd.print("* = Temp & Humidity");
  lcd.setCursor(0,2);
  lcd.print("# = Time & Date ");
  lcd.setCursor(0,3);
  lcd.print("7 = List");
  lcd.setCursor(10,3);
  lcd.print("8 = HELP");
       
  // following line sets the RTC to the date & time this sketch was compiled
  RTC.begin(DateTime(__DATE__, __TIME__));
  
  
  //for Temp and Humidity
  dht.begin();
       
}
  
void loop()
{
  ////////////////////////////////////////////////////////////////////////////
  //listen for keypad press
  char key = keypad.getKey();
  //print key to serial for communicate over serial
  if (key) 
  {
    Serial.println(key);
 
  }
  
}

/////////////////////////////////////////////////////////////////////////////
// Void key events
//take care of some special events
void keypadEvent(KeypadEvent key)
{
  switch (keypad.getState())
  {
    case PRESSED:
      switch (key)
      {
///////////////////////////////////////////////////////////////////////////////
// switch outlets on and off digital pins 8-12
        case '1':
        lcd.clear();
        digitalWrite(Outlet1,!digitalRead(Outlet1));
        lcd.setCursor(0,1);
        lcd.print("      OUTLET#1      "); 
        lcd.setCursor(0,2);
        lcd.print("    WAS SWITCHED    ");
        delay(500);
        lcd.clear();
        lcd.begin(20,4);
        lcd.print("<<<SWITCHBOX MENU>>>");
        lcd.setCursor(0,1);
        lcd.print("* = Temp & Humidity");
        lcd.setCursor(0,2);
        lcd.print("# = Time & Date ");
        lcd.setCursor(0,3);
        lcd.print("7 = List");
        lcd.setCursor(10,3);
        lcd.print("8 = HELP");
        break;
        
        case '2': 
        lcd.clear();
        digitalWrite(Outlet2,!digitalRead(Outlet2));
        lcd.setCursor(0,1);
        lcd.print("      OUTLET#2      "); 
        lcd.setCursor(0,2);
        lcd.print("    WAS SWITCHED    ");
        delay(500);
        lcd.clear();
        lcd.begin(20,4);
        lcd.print("<<<SWITCHBOX MENU>>>");
        lcd.setCursor(0,1);
        lcd.print("* = Temp & Humidity");
        lcd.setCursor(0,2);
        lcd.print("# = Time & Date ");
        lcd.setCursor(0,3);
        lcd.print("7 = List");
        lcd.setCursor(10,3);
        lcd.print("8 = HELP");
        break;
        
        case '3': 
        lcd.clear();
        digitalWrite(Outlet3,!digitalRead(Outlet3));
        lcd.setCursor(0,1);
        lcd.print("      OUTLET#3      "); 
        lcd.setCursor(0,2);
        lcd.print("    WAS SWITCHED    ");
        delay(500);
        lcd.clear();
        lcd.begin(20,4);
        lcd.print("<<<SWITCHBOX MENU>>>");
        lcd.setCursor(0,1);
        lcd.print("* = Temp & Humidity");
        lcd.setCursor(0,2);
        lcd.print("# = Time & Date ");
        lcd.setCursor(0,3);
        lcd.print("7 = List");
        lcd.setCursor(10,3);
        lcd.print("8 = HELP");
        break;
        
        case '4': 
        lcd.clear();
        digitalWrite(Outlet4,!digitalRead(Outlet4));
        lcd.setCursor(0,1);
        lcd.print("      OUTLET#4     "); 
        lcd.setCursor(0,2);
        lcd.print("    WAS SWITCHED    ");
        delay(500);
        lcd.clear();
        lcd.begin(20,4);
        lcd.print("<<<SWITCHBOX MENU>>>");
        lcd.setCursor(0,1);
        lcd.print("* = Temp & Humidity");
        lcd.setCursor(0,2);
        lcd.print("# = Time & Date ");
        lcd.setCursor(0,3);
        lcd.print("7 = List");
        lcd.setCursor(10,3);
        lcd.print("8 = HELP");
        break;
        
        case '5': 
        lcd.clear();
        digitalWrite(Outlet5,!digitalRead(Outlet5));
        lcd.setCursor(0,1);
        lcd.print("      OUTLET#5      "); 
        lcd.setCursor(0,2);
        lcd.print("    WAS SWITCHED    ");
        delay(500);
        lcd.clear();
        lcd.begin(20,4);
        lcd.print("<<<SWITCHBOX MENU>>>");
        lcd.setCursor(0,1);
        lcd.print("* = Temp & Humidity");
        lcd.setCursor(0,2);
        lcd.print("# = Time & Date ");
        lcd.setCursor(0,3);
        lcd.print("7 = List");
        lcd.setCursor(10,3);
        lcd.print("8 = HELP");
        break;
        
        case '6': 
        lcd.clear();
        digitalWrite(Outlet1,LOW);
        digitalWrite(Outlet2,LOW);
        digitalWrite(Outlet3,LOW);
        digitalWrite(Outlet4,LOW);
        digitalWrite(Outlet5,LOW);
        lcd.setCursor(0,0);
        lcd.print("********************");    
        lcd.setCursor(0,1);
        lcd.print("     ALL OUTLETS    "); 
        lcd.setCursor(0,2);
        lcd.print("       ARE OFF      ");
        lcd.setCursor(0,3);
        lcd.print("********************");
        delay(1500);
        lcd.clear();
        lcd.begin(20,4);
        lcd.print("<<<SWITCHBOX MENU>>>");
        lcd.setCursor(0,1);
       lcd.print("* = Temp & Humidity");
       lcd.setCursor(0,2);
       lcd.print("# = Time & Date ");
       lcd.setCursor(0,3);
       lcd.print("7 = List");
       lcd.setCursor(10,3);
       lcd.print("8 = HELP");
        break;    
        
 ///////////////////////////////////////////////////////////////////////////////
//help pressed 
        case '8':
        lcd.clear();
        lcd.begin(20,4);
        lcd.print("all outlets are in o");
        lcd.setCursor(0,1);
        lcd.print("rder toggle keys 1-5");
        lcd.setCursor(0,2);
        lcd.print("to turn on and off o");
        lcd.setCursor(0,3);
        lcd.print("utlets 1-5 0= S/Menu");
        break;
        
////////////////////////////////////////////////////////////////////////////////
//outlet list pressed
        case '7': 
        lcd.begin(20,4);
        lcd.print("<<<<OUTLET LIST>>>>>");
        lcd.setCursor(0,1);
        lcd.print("1=Outlet1");
        lcd.setCursor(10,1);
        lcd.print("4=Outlet4");
        lcd.setCursor(0,2);
        lcd.print("2=Outlet2");
        lcd.setCursor(10,2);
        lcd.print("5=Outlet5");
        lcd.setCursor(0,3);
        lcd.print("3=Outlet3");
        lcd.setCursor(10,3);
        lcd.print("0 = S/Menu");
        break;

///////////////////////////////////////////////////////////////////////////////
// man menu pressed
       
       case '0':
       lcd.clear();
       lcd.begin(20,4);
       lcd.print("<<<SWITCHBOX MENU>>>");
       lcd.setCursor(0,1);
       lcd.print("* = Temp & Humidity");
       lcd.setCursor(0,2);
       lcd.print("# = Time & Date ");
       lcd.setCursor(0,3);
       lcd.print("7 = List");
       lcd.setCursor(10,3);
       lcd.print("8 = HELP");
       break;
     
     
///////////////////////////////////////////////////////////////////////////////
//// this is for temp and humidity keep at the bottom of CASE: PRESSED  
       case '*':
       lcd.clear();
       //Temp and Humidity
       // Reading temperature or humidity takes about 250 milliseconds!
       // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
       float h = dht.readHumidity();
       float t = dht.readTemperature();
       lcd.begin(20,4);
       lcd.print("<<TEMP AND HUMIDITY>");
       // check if returns are valid, if they are NaN (not a number) then something went wrong!
       if (isnan(t) || isnan(h)) 
       {
        lcd.setCursor(0,2);
        lcd.print("Failed read from DHT");
       } 
       else
       {
         lcd.setCursor(0,1);
         lcd.print("Humidity: ");
         lcd.setCursor(10,1);
         lcd.print(h);
         lcd.print(" %");
         lcd.setCursor(0,2);
         lcd.print("Temp: ");
         // DHT11 calculates in C to convert to F do bellow
         // to convert c to f multiply by1.8+32
         lcd.setCursor(10,2);
         lcd.print(t*1.8+32);
         lcd.print(" F");
         lcd.setCursor(10,3);
         lcd.print("0 = S/Menu");
}
     
       
      
      }
      /////////////////////////////////////////////////////////////////////////////////////////////////
      // this is for time and date keep under RELEASED
       break;
       case RELEASED:
       switch (key) { 
       case '#':
       lcd.clear();
       lcd.begin(20,4);
       lcd.print("<<<TIME AND DATE>>>>");
       DateTime now = RTC.now();
       lcd.setCursor(0,1);
       lcd.print(now.year(), DEC);
       lcd.print('/');
       lcd.print(now.month(), DEC);
       lcd.print('/');
       lcd.print(now.day(), DEC);
       lcd.setCursor(0,2);
       lcd.print(now.hour(), DEC);
       lcd.print(':');
       lcd.print(now.minute(), DEC);
       lcd.print(':');
       lcd.print(now.second(), DEC);
       lcd.setCursor(10,3);
       lcd.print("0 = S/Menu");
       break;
      
      
      
     
  }
 
}
}





    


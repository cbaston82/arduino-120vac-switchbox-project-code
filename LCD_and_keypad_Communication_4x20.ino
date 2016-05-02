#include <LiquidCrystal.h>
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'#','0','*'}
};
byte rowPins[ROWS] = {28,27,26,25}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {24,23,22}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


// digital pins for LCD display 
LiquidCrystal lcd(2,3,4,5,6,7);

// digital pin outputs to switch relays
int OUTLET1 =8;
int OUTLET2 = 9;
int OUTLET3 = 10;
int OUTLET4 = 11;
int OUTLET5 =12;
int incomingByte;



void setup()
{

  // set pins to OUTPUTS for relay switching 5VDC
  pinMode(OUTLET1, OUTPUT);
  pinMode(OUTLET2, OUTPUT);
  pinMode(OUTLET3, OUTPUT);
  pinMode(OUTLET4, OUTPUT);
  pinMode(OUTLET5, OUTPUT);

  
  // When Starts read out 120VAC:  OFF
  lcd.begin(20,4);
  lcd.print("**MAIN 120VAC: OFF**");
  lcd.setCursor(0,1);
    lcd.print("1: OFF");
    lcd.setCursor(10,1);
    lcd.print("2: OFF");
    lcd.setCursor(0,2);
    lcd.print("3: OFF");
    lcd.setCursor(10,2);
    lcd.print("4: OFF");
    lcd.setCursor(0,3);
    lcd.print("5: OFF");
    
    Serial.begin(9600);
}

void loop()
{
    // read the input from keypad 
    char key = keypad.getKey() - '0';
    int val = Serial.read() - '0';
    if (key == 1) 
    {
     lcd.begin(20,4);
    lcd.print("**MAIN 120VAC: ON***");
    Serial.print("**MAIN 120VAC: ON***");
    lcd.setCursor(0,1);
    lcd.print("1: ON ");
    Serial.print("1: ON ");
    lcd.setCursor(10,1);
    lcd.print("2: OFF");
    lcd.setCursor(0,2);
    lcd.print("3: OFF");
    lcd.setCursor(10,2);
    lcd.print("4: OFF");
    lcd.setCursor(0,3);
    lcd.print("5: OFF");
    digitalWrite(OUTLET1, HIGH);
  }
    else if (key ==6) 
  {
    lcd.begin(20,4);
    lcd.print("**MAIN 120VAC: OFF**");
    
    Serial.print("**MAIN 120VAC: OFF**");
    lcd.setCursor(0,1);
    lcd.print("1: OFF");
    Serial.print("1: OFF");
    lcd.setCursor(10,1);
    lcd.print("2: OFF");
    lcd.setCursor(0,2);
    lcd.print("3: OFF");
    lcd.setCursor(10,2);
    lcd.print("4: OFF");
    lcd.setCursor(0,3);
    lcd.print("5: OFF");
    digitalWrite(OUTLET1, LOW);
    digitalWrite(OUTLET2,LOW);
    digitalWrite(OUTLET3, LOW);
    digitalWrite(OUTLET4, LOW);
    digitalWrite(OUTLET5, LOW);
  }
     if (key==2)
  {
   // Start LCD at verry top 
    lcd.setCursor(10,1);
    //Print Fan: ON
    lcd.print("2: ON ");
    // Also print to Serial Monitor
    Serial.print("2: ON ");
    // Swtich relay on
    digitalWrite(OUTLET2, HIGH);
  }
    else if (key ==7) 
  {
    lcd.setCursor(10,1);
    //Turn Fan: OFF
    lcd.print("2: OFF");
    Serial.print("2: OFF");
    digitalWrite(OUTLET2, LOW);
  }
     if (key==3)
  {
   // Start LCD at verry top 
    lcd.setCursor(0,2);
    //Print Soldering: ON
    lcd.print("3: ON ");
    // Also print to Serial Monitor
    Serial.print("3: ON ");
    // Swtich relay on
    digitalWrite(OUTLET3, HIGH);
  }
    else if (key ==8) 
  {
    lcd.setCursor(0,2);
    //Turn Soldering: OFF
    lcd.print("3: OFF");
    Serial.print("3: OFF");
    digitalWrite(OUTLET3, LOW);
}
 if (key ==4)
  {
   // Start LCD at verry top 
    lcd.setCursor(10,2);
    //Print Lamp: ON
    lcd.print("4: ON ");
    // Also print to Serial Monitor
    Serial.print("4: ON ");
    // Swtich relay on
    digitalWrite(OUTLET4, HIGH);
  }
    else if (key ==9) 
  {
    lcd.setCursor(10,2);
    //Turn Lamp: OFF
    lcd.print("4: OFF");
    Serial.print("4: OFF");
    digitalWrite(OUTLET4, LOW);
  }
  if (key==5)
  {
   // Start LCD at verry top 
    lcd.setCursor(0,3);
    //Print PowerSupply:On
    lcd.print("5: ON ");
    // Also print to Serial Monitor
    Serial.print("5: ON ");
    // Swtich relay on
    digitalWrite(OUTLET5, HIGH);
  }
   
    else if (key ==0) 
  {
    lcd.setCursor(0,3);
    lcd.print("5: OFF");
    Serial.print("5: OFF");
    digitalWrite(OUTLET5, LOW);
}
if (val == 1) 
    {
     lcd.begin(20,4);
    lcd.print("**MAIN 120VAC: ON***");
    Serial.print("**MAIN 120VAC: ON***");
    lcd.setCursor(0,1);
    lcd.print("1: ON ");
    Serial.print("1: ON ");
    lcd.setCursor(10,1);
    lcd.print("2: OFF");
    lcd.setCursor(0,2);
    lcd.print("3: OFF");
    lcd.setCursor(10,2);
    lcd.print("4: OFF");
    lcd.setCursor(0,3);
    lcd.print("5: OFF");
    digitalWrite(OUTLET1, HIGH);
  }
    else if (val ==6) 
  {
    lcd.begin(20,4);
    lcd.print("**MAIN 120VAC: OFF**");
    Serial.print("**MAIN 120VAC: OFF**");
    lcd.setCursor(0,1);
    lcd.print("1: OFF");
    Serial.print("1: OFF");
    lcd.setCursor(10,1);
    lcd.print("2: OFF");
    lcd.setCursor(0,2);
    lcd.print("3: OFF");
    lcd.setCursor(10,2);
    lcd.print("4: OFF");
    lcd.setCursor(0,3);
    lcd.print("5: OFF");
    digitalWrite(OUTLET1, LOW);
    digitalWrite(OUTLET2,LOW);
    digitalWrite(OUTLET3, LOW);
    digitalWrite(OUTLET4, LOW);
    digitalWrite(OUTLET5, LOW);
  }
     if (val==2)
  {
   // Start LCD at verry top 
    lcd.setCursor(10,1);
    //Print Fan: ON
    lcd.print("2: ON ");
    // Also print to Serial Monitor
    Serial.print("2: ON ");
    // Swtich relay on
    digitalWrite(OUTLET2, HIGH);
  }
    else if (val ==7) 
  {
    lcd.setCursor(10,1);
    //Turn Fan: OFF
    lcd.print("2: OFF");
    Serial.print("2: OFF");
    digitalWrite(OUTLET2, LOW);
  }
     if (val==3)
  {
   // Start LCD at verry top 
    lcd.setCursor(0,2);
    //Print Soldering: ON
    lcd.print("3: ON ");
    // Also print to Serial Monitor
    Serial.print("3: ON ");
    // Swtich relay on
    digitalWrite(OUTLET3, HIGH);
  }
    else if (val ==8) 
  {
    lcd.setCursor(0,2);
    //Turn Soldering: OFF
    lcd.print("3: OFF");
    Serial.print("3: OFF");
    digitalWrite(OUTLET3, LOW);
}
 if (val ==4)
  {
   // Start LCD at verry top 
    lcd.setCursor(10,2);
    //Print Lamp: ON
    lcd.print("4: ON ");
    // Also print to Serial Monitor
    Serial.print("4: ON ");
    // Swtich relay on
    digitalWrite(OUTLET4, HIGH);
  }
    else if (val ==9) 
  {
    lcd.setCursor(10,2);
    //Turn Lamp: OFF
    lcd.print("4: OFF");
    Serial.print("4: OFF");
    digitalWrite(OUTLET4, LOW);
  }
  if (val==5)
  {
   // Start LCD at verry top 
    lcd.setCursor(0,3);
    //Print PowerSupply:On
    lcd.print("5: ON ");
    // Also print to Serial Monitor
    Serial.print("5: ON ");
    // Swtich relay on
    digitalWrite(OUTLET5, HIGH);
  }
   
    else if (val ==0) 
  {
    lcd.setCursor(0,3);
    lcd.print("5: OFF");
    Serial.print("5: OFF");
    digitalWrite(OUTLET5, LOW);
  }
    
while (digitalRead(OUTLET1) == LOW) {
    poweroff();
    
}
}
  


  void poweroff () {
    char key = keypad.getKey() - '0';
    int val = Serial.read() - '0';
    digitalWrite(OUTLET1, LOW);
    digitalWrite(OUTLET2, LOW);
    digitalWrite(OUTLET3, LOW);
    digitalWrite(OUTLET4, LOW);
    digitalWrite(OUTLET5, LOW);
    if (key == 1) 
    {
      lcd.begin(20,4);
    lcd.print("**MAIN 120VAC: ON**");
    Serial.print("**MAIN 120VAC: ON**");
    lcd.setCursor(0,1);
    lcd.print("1: ON ");
    lcd.setCursor(10,1);
    lcd.print("2: OFF");
    lcd.setCursor(0,2);
    lcd.print("3: OFF");
    lcd.setCursor(10,2);
    lcd.print("4: OFF");
    lcd.setCursor(0,3);
    lcd.print("5: OFF");
    digitalWrite(OUTLET1, HIGH);
  }
  if (val == 1) 
    {
      lcd.begin(20,4);
    lcd.print("**MAIN 120VAC: ON**");
    Serial.print("**MAIN 120VAC: ON**");
    lcd.setCursor(0,1);
    lcd.print("1: ON ");
    lcd.setCursor(10,1);
    lcd.print("2: OFF");
    lcd.setCursor(0,2);
    lcd.print("3: OFF");
    lcd.setCursor(10,2);
    lcd.print("4: OFF");
    lcd.setCursor(0,3);
    lcd.print("5: OFF");
    digitalWrite(OUTLET1, HIGH);
  }
  }



  
  


    
  

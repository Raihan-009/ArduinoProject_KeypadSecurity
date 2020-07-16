#include<LiquidCrystal_I2C.h>

#include <Servo.h> 

Servo myservo;
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
#include <Keypad.h>

const byte ROWS = 4;
const byte COLUMNS = 5;


char* password ="1234";
int i = 0;

char pushbuttons[ROWS][COLUMNS]= 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowpins[COLUMNS] = {2,3,4,5};
byte columnpins[ROWS] = {9,8,7,6};

Keypad customkeypad = Keypad(makeKeymap(pushbuttons), rowpins, columnpins, ROWS, COLUMNS);
void setup() {
  myservo.attach(12);
  myservo.write(180);
  pinMode(10,OUTPUT);
  digitalWrite(10,HIGH);
  lcd.begin(16,2);
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Start");
  //setLocked (true);
  // put your setup code here, to run once:

}

void loop() {

  lcd.setCursor(0, 0);
  lcd.print("    Welcome");
  lcd.setCursor(0, 1);
  lcd.print(" Enter Password");

  char customButton = customkeypad.getKey();
  if (customButton)
  {
    if (customButton)
    {
      Serial.println(customButton);
    }
  }

  
  if(customButton == '*' || customButton == '#' || customButton == 'A' ||       //define invalid keys
  customButton == 'B' || customButton == 'C' || customButton == 'D'){

    i=0;
    //setLocked (true);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Invalid Key!");
    delay(1000);
    lcd.clear();
  }
  if(customButton == password [i]){

    i ++;
  }
  if(i == 4){
    //setLocked (false);
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("*** Verified ***");
    delay(3000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("RAIHAN");
    lcd.setCursor(0, 1);
    lcd.print("     1809009");
    delay(1000);
    myservo.write(90);
    delay(4000);
    myservo.write(180);
    lcd.clear();
  }
  delay(100);

}


  

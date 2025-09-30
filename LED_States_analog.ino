//#include <IRremoteInt.h>
/*arduino-cli compile --fqbn arduino:avr:uno --port /dev/cu.usbmodem2101 --upload <sketch path>*/
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LedControl.h>
#include <dht11.h>
//#include <IRremote.hpp>
//#include <IRremote.h>
#define ledRed A1
#define ledYellow A5
#define ledBlue A6
#define ledGreen A0
#define inputred A7
#define IR_RECEIVE_PIN 3
#define DIN 11
#define CS 10
#define CLK 9
#define ANALOG_X_CORRECTION 128 
#define ANALOG_Y_CORRECTION 128 
Servo myservo;
Servo servo1;
dht11 dht11;
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2line display


int inputYellow=5;
int inputGreen = 6;
int inputBlue= 7;
int state = 0;
int ledstate =0;
int seq=0;
int EchoPin = 9; //Connect Echo pin to D13
int TrigPin = 8;
int n=0;
int temp = 0;
int pir = 4;
int DHT11PIN = 2;
int pir_val=0;
int i=0;
unsigned int a_in=0;
unsigned int pos=0;
unsigned int pos1=0;
unsigned long previousMillis1s = 0;
unsigned long previousMillis500ms=0;
unsigned long previousMillis100ms=0;
unsigned long previousMillis10ms=0;
unsigned long period1s = 1000;
unsigned long period500ms = 500;
unsigned long period100ms = 100;
unsigned long period10ms = 10;
unsigned long  t_wait=0;
uint8_t choose_mode =0;
float duration;
float distance;  
uint8_t ulsmode =0;
uint8_t dir=0;
//int i=2;
int j= 2;
int butprev =0;
int lastleft= 0;
int lastright=0;
int lastup=0;
int lastdown=0;
bool buttedge=false;
bool buttpressed=false;
struct button { 
	 byte pressed = 0; 
}; 
	 
struct analog { 
	 short x, y; 
	 
	 button button; 
}; 
LedControl lc=LedControl(DIN,CLK,CS,6);
byte data_val[6][8]= {
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x04, 0x05, 0x05, 0x04, 0x00, 0x00},
{0x00, 0x10, 0x14, 0x15, 0x15, 0x14, 0x10, 0x00},
{0x40, 0x50, 0x54, 0x55, 0x55, 0x54, 0x50, 0x40},
{0xc0, 0xd0, 0xd4, 0xd5, 0xd5, 0xd4, 0xd0, 0xc0},
};
#define ON 1
#define OFF 0
#define blinkall 1
#define blinksequence 2
#define analogall 3
#define analogseq 4
#define ALARM 10 
#define motor 5
#define pirstate 6
#define dht11state 7
#define irstate 8
#define ulstate 9
#define joystick 10
#define ANALOG_X_PIN A2 
#define ANALOG_Y_PIN A3 
#define ANALOG_BUTTON_PIN A4 
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4	 
//Default values when axis not actioned 
/*long ir_rec;
IRrecv irrecv(IRPIN);
decode_results results;*/
void alloff(){
  digitalWrite(ledRed, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledBlue, LOW);
  ledstate = OFF;
}
void allon(){
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledYellow, HIGH);
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledBlue, HIGH);
  ledstate = ON;
}
/*TODO: Define array of LED and sequence through indexes instead of brute-force*/
void blksequence(int seq){
    if (seq ==0){
      digitalWrite(ledRed, HIGH);
      digitalWrite(ledYellow,LOW);
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledBlue, LOW);
    }
    
    if( seq == 1){
      digitalWrite(ledRed, LOW);
      digitalWrite(ledYellow,HIGH);
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledBlue, LOW);

    }
    if (seq == 2){
      digitalWrite(ledRed, LOW);
      digitalWrite(ledYellow,LOW);
      digitalWrite(ledGreen, HIGH);
      digitalWrite(ledBlue, LOW);
 
    }
   
    if (seq ==3){
      digitalWrite(ledRed, LOW);
      digitalWrite(ledYellow,LOW);
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledBlue, HIGH);

    }
    if (seq==4){
       alloff();
    }
   

}

void setup() {
 //Serial.begin(9600);
 
  /* for(int i=0;i<8;i++)
      {
        //Serial.println(data_val[temp][i]);
        lc.setRow(0,i,data_val[4][i]);
      }*/
  Serial.begin(115200);

/*  // Just to know which program is running on my Arduino
    Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));

    // Start the receiver and if not 3. parameter specified, take LED_BUILTIN pin from the internal boards definition as default feedback LED
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

    Serial.print(F("Ready to receive IR signals of protocols: "));
    printActiveIRProtocols(&Serial);
//   Serial.println(F("at pin " STR(IR_RECEIVE_PIN)));*/
  servo1.attach(8);
  myservo.attach(12);

  //lc.setRow(0,2,data_val[5][2]);
 // pinMode(TrigPin, OUTPUT);  
//	pinMode(EchoPin, INPUT); 
 pinMode(ANALOG_BUTTON_PIN, INPUT_PULLUP); 
  pinMode(pir, INPUT);
  lcd.init(); 
  lcd.backlight(); //Turn on the LCD backlight
  lcd.setCursor(2,0); //Set the display position
  lcd.print("Hello,world!"); //LCD displays "Hello, world!"
  lcd.setCursor(2,1);
  lcd.print("Silva"); //LCD displays "!"*/
  pinMode(ledRed, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(inputBlue, INPUT);
  pinMode(inputYellow, INPUT);
  pinMode(inputGreen, INPUT);
  pinMode(inputred, INPUT);
  pinMode (A6, INPUT);
  pinMode(DHT11PIN, INPUT);
  //pinMode(4, INPUT);*/
    lc.shutdown(0,false);//MAX72XX is in power saving mode when starting
  lc.setIntensity(0,8);//Set the brightness to the maximum
  lc.clearDisplay(0); //Clear display
}

void loop() {
  unsigned long currentMillis = millis();
   analog analog; 
  /*todo:
   change modes based on IR input - let tasks run on periodic task(10,100,,500,1000 ms) use IR mode to detect only changes
   lc command not working when IR interrups active
   ULS mode must be enabled only without IR mode (interrups conflit)
   Bug in Pos during IR mode
  
   // lc.setRow(0,5,data_val[temp][5]);


  if ((currentMillis-previousMillis1s) >= period1s){
    previousMillis1s = currentMillis;    
    if (state == blinkall){
      if (ledstate == ON)
        alloff();
      else
        allon();
    }
    if(state==blinksequence){
      blksequence(seq);
      seq++;
      if( seq >=4) 
        seq=0;
    }
    if (distance <= 12.0){
      n++;
    }
    else 
      n=0;
    if(state == ulstate){
      if (distance <= 12.0 && n >=3){
        state = ALARM;
        alloff();
        digitalWrite(ledRed, HIGH);
        lcd.clear();
        lcd.print("MODE = ALARM!");
      }
    }
    if(state == motor) {
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print(pos);
    }
    if (state == dht11state){
      int chk = dht11.read(DHT11PIN);
      lcd.clear();
      lcd.print("H(%): ");
      lcd.println((float)dht11.humidity,2);
      lcd.setCursor(0,1);
      lcd.print("T(C): ");
      lcd.println((float)dht11.temperature,2);

    }
   
    
  }*/
  if((currentMillis - previousMillis10ms) >= period10ms){
    previousMillis10ms = currentMillis;
    /*if (ulsmode == 1){
      digitalWrite(TrigPin, LOW);  
      delayMicroseconds(2);  
      digitalWrite(TrigPin, HIGH);  
      delayMicroseconds(10);  
      digitalWrite(TrigPin, LOW);  
      noInterrupts();
      duration = pulseIn(EchoPin, HIGH);  
      interrupts();
      distance = (duration*.0343)/2; 
    }*/
    if (state == motor){
      if (pos >= 180) pos = 180;
      if (pos <= 0) pos=0;
      myservo.write(pos);
      servo1.write(pos);

    } 
  
  }
  if((currentMillis - previousMillis100ms) >= period100ms){
    previousMillis100ms = currentMillis;
    /*if(state = motorsweep){
      myservo.write(pos);
      pos++;
    todo
    }*/
  if ((state == joystick) ||1){
  analog.x = readAnalogAxisLevel(ANALOG_X_PIN) - ANALOG_X_CORRECTION; 
	 analog.y = readAnalogAxisLevel(ANALOG_Y_PIN) - ANALOG_Y_CORRECTION;
	 analog.button.pressed = isAnalogButtonPressed(ANALOG_BUTTON_PIN); 

  if(analog.button.pressed != buttedge){
    buttpressed=true;
  }
   if (analog.y >15){
    dir =RIGHT;
    if (i>=0 && i <8){
      lc.clearDisplay(0);
      lc.setLed(0,i,j,true);
    i++;
    if(i>7) i=7;
    }
    if( pos>=10){
        pos-=10;
        myservo.write(pos);

      }
    Serial.println("RIGHT:");
    Serial.println(i);
    Serial.println(j);
    //if(i<6) {i=i+1;}
   }
   if (analog.y <-15){
    dir = LEFT;
    if(i>=0 && i<8){
      lc.clearDisplay(0);
      lc.setLed(0,i,j,true);
      i--;
      if(i<0) i=0;
      if( pos<=170){
        pos+=10;
        myservo.write(pos);

      }
    }
    Serial.println("LEFT:");
    Serial.println(i);
    Serial.println(j);
    //if(i>1) i=i-1;
   } 
  if (analog.x >15){
    dir = UP;
     if(j>=0 && j<8){
      lc.clearDisplay(0);
      lc.setLed(0,i,j,true);
      j++;
      if(j>7) j=7;
     }
    Serial.println("UP:");
    Serial.println(i);
    Serial.println(j);
    if( pos1<=170){
        pos1+=10;
        servo1.write(pos1);

      }
  }
  if (analog.x < -15){
    dir = DOWN;
    if (j>=0 && j<=8){
    lc.clearDisplay(0);
    lc.setLed(0,i,j,true);
    }
    Serial.println("DOWN:");
    Serial.println(i);
    Serial.println(j);
    j--;
    if(j<=0) j=0;
    if( pos1>=10){
        pos1-=10;
        servo1.write(pos1);

      }
    
  }
  if (buttpressed) /*&& (butprev == 0)*/{
    lc.clearDisplay(0);
    lc.setLed(0,0,0, true);
    lc.setLed(0,7,7, true);
    lc.setLed(0,0,7, true);
    lc.setLed(0,7,0, true);
    myservo.write(60);
    servo1.write(60);
    buttpressed = false;
  }
  buttedge=analog.button.pressed; 
  }
    if(state ==motor){
      a_in= analogRead(A6);
      pos = map(a_in,0,1023,0,180);
    }
    if(state == analogall){
      a_in = analogRead(A6);
       if(a_in <= 512) 
         alloff();
      else
        allon();
    }
   /* if(state == analogseq){
      a_in = analogRead(A6);
      if( a_in <= 170){
        alloff();
        lcd.setCursor(0, 1);
         //lcd.print("               ");
         lcd.setCursor(0, 1);
        lcd.print("OFF             ");
        lc.clearDisplay(0);
        temp = 0;

      }
      if (a_in >170 && a_in <=340){
        alloff();
        digitalWrite(ledRed, HIGH);
        lcd.setCursor(0, 1);
        //lcd.print("               ");
        lcd.setCursor(0, 1);
        lcd.print("RED            ");
        temp=1;
      }
      if (a_in >340 && a_in <= 510){
        alloff();
        digitalWrite(ledYellow, HIGH);
        lcd.setCursor(0, 1);
        //lcd.print("               ");
        lcd.setCursor(0, 1);
        lcd.print("YELLOW          ");
        temp=2;
        
      }
      if (a_in >510 && a_in <= 680) {
        alloff();
        digitalWrite(ledGreen, HIGH);        
        lcd.setCursor(0, 1);
         //lcd.print("               ");
         lcd.setCursor(0, 1);
        lcd.print("GREEN           ");
        temp = 3;
        
      }
      if (a_in >680 && a_in <=850){
        alloff();
        digitalWrite(ledBlue, HIGH);
        lcd.setCursor(0, 1);
       //  lcd.print("               ");
         lcd.setCursor(0, 1);
        lcd.print("BLUE           ");
        temp= 4;
      }
      if (a_in >850) {
        lcd.setCursor(0, 1);
        //lcd.print("               ");
        lcd.setCursor(0, 1);
        lcd.print("ON             ");
        allon();
        temp = 5;
      }
      for(int i=0;i<8;i++){
        lc.setRow(0,i,data_val[temp][i]);
      } 
    } */
   if(state == pirstate){
    pir_val= digitalRead(pir);
    //Serial.println(pir_val);
    if (pir_val == 1){
      alloff();
      digitalWrite(ledRed, HIGH);
      digitalWrite(ledBlue, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("INTRUDER");
    }
    else{
      alloff();
      analogWrite(ledGreen, 255);
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      lcd.print("SAFE");
    }
   }
    
  }
  if((currentMillis - previousMillis500ms) >= period500ms){
    previousMillis500ms = currentMillis;
   
    if (analogRead(inputred) <= 100){
        state = blinkall;
        lcd.clear();
        lcd.print("MODE = BLINK ALL!");
    }  

    if(digitalRead(inputYellow)== LOW){
        state =blinksequence;
        lcd.clear();
        lcd.print("MODE = SEQUENCE!");
    }
    if(digitalRead(inputGreen) == LOW){
      state = analogall;
      //noInterrupts();
      lcd.clear();
      lcd.print("MODE = AN ALL!");
    }

    if(digitalRead(inputBlue) == LOW){
      state = analogseq;
    
      lcd.clear();
      lcd.print("MODE = AN SEQ!");
      //noInterrupts();

    }
    if((digitalRead(inputBlue) == LOW) && (digitalRead(inputGreen) == LOW)){
      state = motor;
      lcd.clear();
      lcd.print("MODE = MOTOR");
     
    }
    if((digitalRead(inputBlue) == LOW) && (digitalRead(inputYellow) == LOW)){
      state = pirstate;
      lcd.clear();
      lcd.print("MODE = PIR");
    }
    if((digitalRead(inputBlue) == LOW) && (analogRead(inputred) <= 100)){
      state = dht11state;
      lcd.clear();
    }
    if((digitalRead(inputBlue) == LOW) && (digitalRead(inputYellow)== LOW) && (digitalRead(inputGreen)== LOW)){
      state = irstate;
      lcd.clear();
      lcd.print("MODE = IR");

    }
    Serial.println(pos);
    Serial.println(pos1);
  }
}
byte readAnalogAxisLevel(int pin) 
{ 
	 return map(analogRead(pin), 0, 1023, 0, 255); 
} 
	 
bool isAnalogButtonPressed(int pin) 
{ 
	 return digitalRead(pin) == 0; 
   myservo.write(0);
   butprev=0;
} 
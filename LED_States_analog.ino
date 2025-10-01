//#include <IRremoteInt.h>
/*arduino-cli compile --fqbn arduino:avr:uno --port /dev/cu.usbmodem2101 --upload <sketch path>*/
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LedControl.h>
#include <dht11.h>
#include <IRremote.hpp>
//#include "PinDefinitionsAndMore.h"
//#include <IRremote.h>
#define ledRed A1
#define ledYellow A2
#define ledBlue A3
#define ledGreen A0
#define inputred A7
#define IR_RECEIVE_PIN 3
#define DIN 11
#define CS 10
#define CLK 13
Servo myservo;
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
unsigned int a_in=0;
unsigned int pos=0;
unsigned long previousMillis1s = 0;
unsigned long previousMillis500ms=0;
unsigned long previousMillis100ms=0;
unsigned long previousMillis10ms=0;
unsigned long period1s = 1000;
unsigned long period500ms = 500;
unsigned long period100ms = 100;
unsigned long period10ms = 10;
unsigned long  t_wait=0;
float duration;
float distance;  
uint8_t ulsmode =0;
LedControl lc=LedControl(DIN,CLK,CS,4);
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
/*long ir_rec;
IRrecv irrecv(IRPIN);
decode_results results;*/


void setup() {
 initialize();
}

void loop() {
  unsigned long currentMillis = millis();
  /*todo:
   change modes based on IR input - let tasks run on periodic task(10,100,,500,1000 ms) use IR mode to detect only changes
   lc command not working when IR interrups active
   ULS mode must be enabled only without IR mode (interrups conflit)
   Bug in Pos during IR mode
  */
   //
   if (state == irstate){
    irprocess();
   }
  if ((currentMillis-previousMillis1s) >= period1s){
    previousMillis1s = currentMillis;
    //Serial.println(analogRead(inputred));
    onesecTask();
  }
  if((currentMillis - previousMillis10ms) >= period10ms){
    previousMillis10ms = currentMillis;
    tenmsecTask();
  }
  if((currentMillis - previousMillis100ms) >= period100ms){
    previousMillis100ms = currentMillis;
    hundredmsecTask();
  }
  if((currentMillis - previousMillis500ms) >= period500ms){
    previousMillis500ms = currentMillis;
    fivehundredmsecTask();
  }
}
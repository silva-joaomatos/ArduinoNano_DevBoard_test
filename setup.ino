void initialize(){
  //Serial.begin(9600);
 
  /* for(int i=0;i<8;i++)
      {
        //Serial.println(data_val[temp][i]);
        lc.setRow(0,i,data_val[4][i]);
      }*/
  //Serial.begin(115200);

  // Just to know which program is running on my Arduino
   // Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));

    // Start the receiver and if not 3. parameter specified, take LED_BUILTIN pin from the internal boards definition as default feedback LED
  
  myservo.attach(12);

  //lc.setRow(0,2,data_val[5][2]);
  pinMode(TrigPin, OUTPUT);  
	pinMode(EchoPin, INPUT); 
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
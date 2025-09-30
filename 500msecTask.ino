void fivehundredmsecTask(){
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

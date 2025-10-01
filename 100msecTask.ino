void hundredmsecTask(){

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
    if(state == analogseq){
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
      for(int i=0;i<8;i++)
      {
        //Serial.println(data_val[temp][i]);
        lc.setRow(0,5,data_val[temp][i]);
      }
    } 
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
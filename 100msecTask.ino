void hundredmsecTask(){
   analog analog; 
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

void onesecTask(){
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

}
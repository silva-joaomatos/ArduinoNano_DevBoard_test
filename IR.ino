void irprocess(){
  if (IrReceiver.decode()) {

          /*
          * Print a summary of received data
          */
          if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
              Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
              // We have an unknown protocol here, print extended info
              IrReceiver.printIRResultRawFormatted(&Serial, true);

              IrReceiver.resume(); // Do it here, to preserve raw data for printing with printIRResultRawFormatted()
          } else {
              IrReceiver.resume(); // Early enable receiving of the next IR frame

              IrReceiver.printIRResultShort(&Serial);
              IrReceiver.printIRSendUsage(&Serial);
          }
          Serial.println();

          /*
          * Finally, check the received data and perform actions according to the received command
          */
          if (IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT) {
              Serial.println(F("Repeat received. Here you can repeat the same action as before."));
          } 
          else {
              if (IrReceiver.decodedIRData.command == 0x5E) {
                  Serial.println(F("Received command 0x10."));
                  alloff();
                  digitalWrite(ledYellow, HIGH);
              } 
              else if (IrReceiver.decodedIRData.command == 0xC) {
                  Serial.println(F("Received command 0x11."));
                  alloff();
                  digitalWrite(ledBlue,HIGH);
              }
              else if (IrReceiver.decodedIRData.command == 0x45){
                Serial.println(F("Received command 0x45."));
                if (ledstate == OFF){
                  allon();
                }
                else
                  alloff();
              }
              else if (IrReceiver.decodedIRData.command == 0x18){
                Serial.println(F("Received command 0x18."));
                alloff();
                digitalWrite(ledGreen, HIGH);    
              }
              else if (IrReceiver.decodedIRData.command == 0x8){
                Serial.println(F("Received command 0x8."));
                alloff();
                digitalWrite(ledRed, HIGH);    
              }
              else if (IrReceiver.decodedIRData.command == 0x43){
                Serial.println(F("Received command 0x43."));              
                blksequence(seq);
                seq++;
                 if( seq >=4) seq=0;
                pos+=5;
                if(pos >=178) pos=180;
                myservo.write(pos); 
                lcd.setCursor(0,1); 
                lcd.print("Motor Pos: ");
                lcd.print(pos); 
              }
              else if (IrReceiver.decodedIRData.command == 0x44){
                Serial.println(F("Received command 0x44."));
                blksequence(seq);
                seq--;
                if (seq <0) seq=4;
                pos-=5;
                if(pos <=10) pos=0;
                myservo.write(pos);
                lcd.setCursor(0,1); 
                lcd.print("Motor Pos: ");
                lcd.print(pos);

              }
              else if (IrReceiver.decodedIRData.command == 0x47){
                Serial.println(F("Received command 0x47."));
                //mode++; 
              }
      }
   }
}
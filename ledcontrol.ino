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
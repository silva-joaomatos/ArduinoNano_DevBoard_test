void tenmsecTask(){
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
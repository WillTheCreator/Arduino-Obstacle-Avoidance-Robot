

#define DistanceForward A0
#define L_F 2
#define L_B 3
#define R_F 4
#define R_B 4
int RD = 0;
int DistanceSetOff = 20;
void setup() {
  // put your setup code here, to run once:
pinMode(L_F, OUTPUT);
pinMode(L_B, OUTPUT);
pinMode(R_F, OUTPUT);
pinMode(R_B, OUTPUT);
}

   void Forwards(){
    digitalWrite(L_F, HIGH);
    digitalWrite(R_F, HIGH);
    digitalWrite(L_B, LOW);
    digitalWrite(R_B, LOW);
    
   }
   void Backwards(){
    digitalWrite(L_F, LOW);
    digitalWrite(R_F, LOW);
    digitalWrite(L_B, HIGH);
    digitalWrite(R_B, HIGH);
    
   }
   void TurnLeft(){
    digitalWrite(L_F, LOW);
    digitalWrite(R_F, HIGH);
    digitalWrite(L_B, HIGH);
    digitalWrite(R_B, LOW);
   }
   void TurnRight(){
    digitalWrite(L_F, HIGH);
    digitalWrite(R_F, LOW);
    digitalWrite(L_B, LOW);
    digitalWrite(R_B, HIGH);
   }
   void Stop(){
    digitalWrite(L_F, LOW);
    digitalWrite(R_F, LOW);
    digitalWrite(L_B, LOW);
    digitalWrite(R_B, LOW);
    }





void loop() {
  

  Forwards();
  if(analogRead(DistanceForward) < DistanceSetOff){
       Stop();
       RD = random(TurnLeft,TurnRight);
       
       // if left is randomly choice go left
      if (RD = TurnLeft){
          TurnLeft();
          delay(1000);
          Stop();
      }
      if (RD = TurnRight){
          TurnRight();
          delay(1000);
          Stop();
          }
  }
}
    















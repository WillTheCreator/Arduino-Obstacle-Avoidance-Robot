//#include <Servo.h>

#define DistanceForward A0
#define DistanceLeft A1
#define DistanceRight A2
#define DistanceRightAngle A3
#define DistanceLeftAngle A4
#define DistanceBack A5
#define L_F 2
#define L_B 3
#define R_F 4
#define R_B 4
#define SoundLeft A6
#define SoundFront A7
#define SoundRight A8
//Servo neck;
int pos = 0;
int MicSetOff = 20;
int DistanceSetOff = 20;
int RD = 0;
void setup() {
  // put your setup code here, to run once:
//neck.attach(9);

//pinMode(, );
//pinMode(, );
//pinMode(, );

pinMode(L_F, OUTPUT);
pinMode(L_B, OUTPUT);
pinMode(R_F, OUTPUT);
pinMode(R_B, OUTPUT);

}
// movement functions
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
   void Neck_Left(){
   
   }
   void Neck_Right(){
    
   }
   void Neck_Forwards(){
    
   }
 



// modes of use functions!
   void Guard_Search_Roam(){   
   }
   
   void roam(){ //roam around a room
   






   
   }
   
   void Hall_Roam(){ //roam around in the halls trying to find somone
   Forwards();
   if (analogRead(DistanceForward) < DistanceSetOff){
      Stop();
      // comes to wall forward,check if there are halls on iether sides of the bot, if left distance sensor not tripped and right distance sensor not tripped eiether (aka. a dead end and no left or right hall ways to go down) , randomly choice which way to turn to turn around and go back the way it came!
      if ((analogRead(DistanceLeft) < DistanceSetOff) && (analogRead(DistanceRight) < DistanceSetOff)){
        RD = random(TurnLeft,TurnRight);
        
        if(RD == TurnLeft){
          TurnLeft();
          if (analogRead(DistanceForward) > DistanceSetOff){
             Stop();
             return;
          }
        }
        if(RD == TurnRight){
          TurnRight();
          if(analogRead(DistanceForward) > DistanceSetOff){
            Stop();
            return;
          }
        }
      }
       
      // if a hall way is detected in both left and right directions, then first listen for sound to see if one hall has more noice activilty (aka posilbly it's owner down that hall or people to find!) Go down that specific hall. If both have no noice or equal amount, then randomly choice which to go down!
      else if ((analogRead(DistanceLeft) > DistanceSetOff) && (analogRead(DistanceRight) > DistanceSetOff)){
        // if left has more sound then right go down left hall!
        if ((analogRead(SoundLeft) > 15) && (analogRead(SoundRight) < 5)){
          TurnLeft();
          if (analogRead(DistanceForward) > DistanceSetOff){
            Stop();
            return;
          }
        }
        // if right hall has more nice then go down right hall!
        else if ((analogRead(SoundRight) > 15) && (analogRead(SoundLeft) < 5)){
          TurnRight();
          if (analogRead(DistanceForward) > DistanceSetOff){
            Stop();
            return;
          }
        }
        
      }
      // if a left hall is detected and right isn't it will obviously turn left becuase it is the only way for it to go!
      else if ((analogRead(DistanceLeft) > DistanceSetOff) && (analogRead(DistanceRight) < DistanceSetOff)){
         TurnLeft();
         if (analogRead(DistanceForward) > DistanceSetOff){
           Stop();
           return;
         }
      }
      // if right side has a detected hall then go down that one 
      else if ((analogRead(DistanceLeft) < DistanceSetOff) && (analogRead(DistanceRight) > DistanceSetOff)){
         TurnRight();
         if (analogRead(DistanceForward) > DistanceSetOff){
           Stop();
           return;
         }  

      }
   }

    
   }




void loop() {
  // if there are two walls in front and back turn until they are on the bots two sides! left or right
  if((analogRead(DistanceForward) < DistanceSetOff) && (analogRead(DistanceBack) < DistanceSetOff)){
    RD = random(TurnLeft,TurnRight);
    // if left is randomly choice go left
    if (RD = TurnLeft){
      TurnLeft();
      if((analogRead(DistanceLeft) < DistanceSetOff) && (analogRead(DistanceRight) < DistanceSetOff)){
        Stop();
        return;
      }
    }
    // if right is randomly chosen go right
    if (RD = TurnRight){
      TurnRight();
      if((analogRead(DistanceLeft) < DistanceSetOff) && (analogRead(DistanceRight) < DistanceSetOff)){
        Stop();
        return;
      }
    }
  }
  // if there are walls on both left and right sides, bot is in hallway and must find its way around to people or a 
  else if((analogRead(DistanceLeft) < DistanceSetOff) && (analogRead(DistanceRight) < DistanceSetOff)){
    Hall_Roam();
    
  }
  if ((analogRead(DistanceForward) > DistanceSetOff) && (analogRead(DistanceBack) > DistanceSetOff) && (analogRead(DistanceLeft) > DistanceSetOff) && (analogRead(DistanceRight) > DistanceSetOff)){
    
  }
}










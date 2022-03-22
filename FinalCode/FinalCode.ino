//ROBOKEN 2021
#include <SharpIR.h>
#include <VarSpeedServo.h>
VarSpeedServo servo1; // grip servo
VarSpeedServo servo2; // shoulder servo
VarSpeedServo servo3; // elbow servo
VarSpeedServo servo4; // base servo                                  
#define IRPin A15                                          
#define model 1080   
SharpIR mySensor = SharpIR(IRPin,model); 
/* Model :

  GP2Y0A02YK0F --> 20150
  GP2Y0A21YK0F --> 1080
  GP2Y0A710K0F --> 100500
  GP2YA41SK0F --> 430
*/    
const int PWM_Right = 3; // pwm pin   [brown with blue tie]
const int rightIN1 = 26; // digital pin [black]
const int rightIN2 = 28; // digital pin [white]
const int PWM_Left = 2; // pwm pin    [black with blue tie]
const int leftIN3 = 30; // digital pin [grey]
const int leftIN4 = 32; // digital pin [purple]
int PWM_RightVal;
int rightIN1Val;
int rightIN2Val;     
int PWM_LeftVal;
int leftIN3Val;
int leftIN4Val;
const int Interrupt = 49;
int button;
unsigned long time_now = 0;
const int sensor1 =34; // [blue]
const int sensor2 =36; // [violet]
const int sensor3 =38; // [grey]
const int sensor4 =40; // [white]
const int sensor5 =42; // [dark grey]
const int sensor6 =44; // [green]
const int sensor7 =46; // [yellow]   // vcc [red with blue tie]
const int sensor8= 48; // [orange]  // Gnd [yellow with blue tie]
                 
int U1; int U2;  int U3;  int U4;  int U5;  int U6;  int U7;  int U8; // variables to store tracker sensor readings

int Dist; //variable to store distance
int Right_Speed;
int Left_Speed; 
int Kp = 50;    
int Ki = 0;
int Kd = 5; 
int error;
int previousError = 0;
int totalError = 0;
int power = 0;
int count = 0;
void Track_line(); 
void lineTrack_PID(int Base_leftspeed ,int Base_rightspeed);
void tracksensors_testing();
void forward();
void reverse();
void Stop();
int Counter();
void Delay(int seconds); //Function to create delay in the program
void SendData_2pi();
int GetData_from_pi();
void Search_container();
void Trackobject();
void Trackobject_PID(int p,int d, int i);
void armobject_Search();
void armcontroL_FromPi();

typedef enum {START,STOP,ARM_PARK,TASK1,TASK2,TASK3,TASK4,TASK5,TASK6,TASK7,TASK8,TASK9,TASK10,TASK11,TASK12,TASK13,TASK14,TASK15,TASK16,TASK17,TASK18,TASK19,TASK20,
TASK21,TASK22,TASK23,TASK24,TASK25,TASK26,TASK27,TASK28,TASK29,TASK30,TASK31,TASK32,SEND_DATA,RECEIVE_DATA,STAND_BY,TESTCODE,WAIT,FORWARD,REVERSE} T_state_machine;  //Declare all the task of the Robot

T_state_machine  state = START;

void setup() 
{// put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PWM_Right, OUTPUT);
  pinMode(rightIN1, OUTPUT);
  pinMode(rightIN2, OUTPUT);
  pinMode(PWM_Left,OUTPUT);
  pinMode(leftIN3, OUTPUT);
  pinMode(leftIN4, OUTPUT);
  pinMode(Interrupt,INPUT);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
  pinMode(sensor6, INPUT);
  pinMode(sensor7, INPUT);
  servo1.attach(4); // PWM pins attached to the servo motors
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(7);
  Serial.print(0); // To clear any data in the serial buffer
  Delay(1000);

}

void loop() 
{
  // put your main code here, to run repeatedly:
  switch(state) 
  { // put the code for each task here and remember to indicate the next state
     case TESTCODE:
           //tracksensors_testing(); 
           //forward(); 
           //Track_line();
           lineTrack_PID(65, 65); 
           //count = Counter();
           //Dist = mySensor.distance();
           //Serial.println(Dist); 
           //Delay(1000);
           //Serial.print("\n");           
     break; 
/*..............................................................................................................................*/
     case WAIT:
            
     break;
/*...............................................................................................................................*/
     case START:         
          button = digitalRead(Interrupt);
          //Serial.println(button);                  
          if (button == HIGH)
            {state = TASK1;}
          else
          state = STAND_BY;
     break;
/*........................................................................................................................................*/
     case STAND_BY:
           Delay(200);
           state = START;
     break;
/*........................................................................................................................................*/
     case ARM_PARK: // Setting the inital arm position
         servo1.write(90,12); 
         Delay(1500);
         servo2.write(10,12);
         Delay(1500);
         servo3.write(165,12);
         Delay(1500);
         servo4.write(90,12);
         Delay(1500);
         state = TESTCODE;
     break;
/*........................................................................................................................................*/
     case TASK1:// Move from start to point Q
     lineTrack_PID(60, 60); 
     U6 = digitalRead(sensor6);  
     if(U6 == LOW )
     {
     Stop();
     Delay(1000);
     state = TASK2;
     }       
     break;
/*.......................................................................................................................................*/    
     case TASK2://Move from point Q to point A
          U1= digitalRead(sensor1); U2= digitalRead(sensor2); U3= digitalRead(sensor3); U4= digitalRead(sensor4); U5= digitalRead(sensor5);
          lineTrack_PID(60, 60); 
          if (U1==LOW&&U2==LOW&&U3==LOW&&U4==LOW&&U5==LOW)
          {
           Stop();
           //reverse();
           //delay(80);
           Stop();
           state = TASK3; 
          }       
     break;
/*.......................................................................................................................................*/
     case TASK3://Turn Left
          U2 = digitalRead(sensor2); 
          analogWrite(PWM_Right,95 );
          analogWrite(PWM_Left,0);
          digitalWrite(rightIN1,HIGH);
          digitalWrite(rightIN2, LOW);
          digitalWrite(leftIN3, HIGH);
          digitalWrite(leftIN4, LOW);  
          if(U2 == HIGH)
          {        
           Stop();
           Delay(1000);
           state = TASK4;
          }         
     break;
/*.........................................................................................................................................*/
     case TASK4://Move from point A to R
          U1= digitalRead(sensor1); U2= digitalRead(sensor2); U3= digitalRead(sensor3); U4= digitalRead(sensor4); U5= digitalRead(sensor5);
          lineTrack_PID(60, 60); 
          if(U1==HIGH&&U2==HIGH&&U3==HIGH&&U4==HIGH&&U5==HIGH)
          {
           Stop();
           Delay(1000);
           state = TASK5;
          }                
     break;
/*........................................................................................................................................*/
     case TASK5://Move from point R to point S
          U1= digitalRead(sensor1); U2= digitalRead(sensor2); U3= digitalRead(sensor3); U4= digitalRead(sensor4); U5= digitalRead(sensor5);
          lineTrack_PID(60, 60);   
          if(U1==HIGH&&U2==HIGH&&U3==HIGH&&U4==HIGH&&U5==HIGH)
          {
           Stop();
           Delay(1000);
           state = TASK7;
          }      
     break;
/*........................................................................................................................................*/
   case TASK6://Move from point S to point B
        U1= digitalRead(sensor1); U2= digitalRead(sensor2); U3= digitalRead(sensor3); U4= digitalRead(sensor4); U5= digitalRead(sensor5);
        //U6 = digitalRead(sensor6);
        lineTrack_PID(60, 60);   
        if(U1==HIGH&&U2==HIGH&&U3==HIGH&&U4==HIGH&&U5==HIGH)
        {
         Stop();
         reverse();
         delay(250);
         Stop();
         state = TASK7;
        } 
   break;
/*........................................................................................................................................*/
  case TASK7:// Turn Right
          analogWrite(PWM_Right,0 );
          analogWrite(PWM_Left,95);
          digitalWrite(rightIN1,HIGH);
          digitalWrite(rightIN2, LOW);
          digitalWrite(leftIN3, HIGH);
          digitalWrite(leftIN4, LOW); 
          delay(100);
          Stop();
          Delay(500);
          state = TASK8;     
  break;
/*........................................................................................................................................*/
  case TASK8:
          U4 = digitalRead(sensor4);
          analogWrite(PWM_Right,0 );
          analogWrite(PWM_Left,90);
          digitalWrite(rightIN1,HIGH);
          digitalWrite(rightIN2, LOW);
          digitalWrite(leftIN3, HIGH);
          digitalWrite(leftIN4, LOW); 
          if(U4==HIGH)
          {
            Stop();
            Delay(1000);
            state = TASK9;
          }         
  break;
/*........................................................................................................................................*/
  case TASK9://Move from point B to C
       Dist = mySensor.distance();
       lineTrack_PID(60, 60);
       if(Dist<17)
       {
        Stop();
        reverse();
        delay(180);
        Stop();
        state = START;
       }           
  break;
 /*........................................................................................................................................*/
   case TASK10:// Pick yellow object and place it on the left carrier
           
   break;
}
}

void Delay(int seconds ) // Function to create delay in the program
{ 
  int period = seconds ;// variable to store delay in milliseconds
  time_now = millis();
  while(millis()<(time_now+period))
  { 
    //wait approx.[period] ms 
  }
}

void Stop()
{
  analogWrite(PWM_Right,0 );
  analogWrite(PWM_Left,0);

}

void reverse()
{
  digitalWrite(rightIN1, LOW);
  digitalWrite(rightIN2, HIGH);
  analogWrite(PWM_Right,70 );
  digitalWrite(leftIN3, LOW);
  digitalWrite(leftIN4, HIGH);
  analogWrite(PWM_Left,70 );
}
void lineTrack_PID(int Base_leftspeed ,int Base_rightspeed)//  Using five channel sensor
{
int R_speed = Base_rightspeed;         int L_speed = Base_leftspeed;

U1 = digitalRead(sensor1);  U2 = digitalRead(sensor2);  U3 = digitalRead(sensor3);   U4 = digitalRead(sensor4);   U5 = digitalRead(sensor5);
     
if (U1 == HIGH && U2 == HIGH && U3 == HIGH && U4 == HIGH && U5 == HIGH)
{error = 0;}
else if  (U1 == HIGH && U2 == HIGH && U3 == HIGH && U4 == LOW && U5 == LOW)
{error = 0;}
else if  (U1 == LOW && U2 == LOW && U3 == HIGH && U4 == HIGH && U5 == HIGH)
{error = 0;}
else if  (U1 == LOW && U2 == LOW && U3 == HIGH && U4 == LOW && U5 == LOW)
{error = 0;}
else if  (U1 == LOW && U2 == LOW && U3 == HIGH && U4 == HIGH && U5 == LOW)
{error = 1;}
else if  (U1 == LOW && U2 == LOW && U3 == LOW && U4 == HIGH && U5 == LOW)
{error = 2;}
else if  (U1 == LOW && U2 == LOW && U3 == LOW && U4 == HIGH && U5 == HIGH)
{error = 3;}
else if  (U1 == LOW && U2 == LOW && U3 == LOW && U4 == LOW && U5 == HIGH)
{error = 4;}
else if  (U1 == LOW && U2 == HIGH && U3 == HIGH && U4 == LOW && U5 == LOW)
{error = -1;} 
else if  (U1 == LOW && U2 == HIGH && U3 == LOW && U4 == LOW && U5 == LOW)
{error = -2;}
else if  (U1 == HIGH && U2 == HIGH && U3 == LOW && U4 == LOW && U5 == LOW)
{error = -3;}
else if  (U1 == HIGH && U2 == LOW && U3 == LOW && U4 == LOW && U5 == LOW)
{error = -4;}
else if (U1 == LOW && U2 == LOW && U3 == LOW && U4 == LOW && U5 == LOW)
{
 Stop();
 Delay(1000); 
}

 power = (Kp*error) + (Kd*(error-previousError)) + (Ki*totalError);
 previousError = error; // save previous error for differential 
 totalError += error; // Accumulate error for integral
     
    if(power<0) // Turn left
    {
      
     Right_Speed = R_speed - power ;
     Left_Speed = L_speed ;
     analogWrite(PWM_Right,Right_Speed );
     analogWrite(PWM_Left,Left_Speed);
     digitalWrite(rightIN1, HIGH);
     digitalWrite(rightIN2, LOW);
     digitalWrite(leftIN3, HIGH);
     digitalWrite(leftIN4, LOW);    
    }
    
   else if(power>0) // Turn right
    {
      
      Right_Speed = R_speed ;
      Left_Speed = L_speed + power ;
      analogWrite(PWM_Right,Right_Speed );
      analogWrite(PWM_Left,Left_Speed);
      digitalWrite(rightIN1, HIGH);
      digitalWrite(rightIN2, LOW);   
      digitalWrite(leftIN3, HIGH);
      digitalWrite(leftIN4, LOW);
   
    }
    
   else if(power==0)
    {
     Right_Speed = R_speed ;
     Left_Speed = L_speed ;
     analogWrite(PWM_Right,Right_Speed );
     analogWrite(PWM_Left,Left_Speed);
     digitalWrite(rightIN1, HIGH);
     digitalWrite(rightIN2, LOW);   
     digitalWrite(leftIN3, HIGH);
     digitalWrite(leftIN4, LOW);

    }
}

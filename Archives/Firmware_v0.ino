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
const int PWM_Right = 2; // pwm pin   [brown with blue tie]
const int rightIN1 = 26; // digital pin [black]
const int rightIN2 = 28; // digital pin [white]
const int PWM_Left = 3; // pwm pin    [black with blue tie]
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
int sensorReading[8] = {0,0,0,0,0,0,0,0}; // Sensor reading array
int Kp = 25;   
int Ki = 0;
int Kd = 0;
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
void turn_right();
void turn_left();
int distance1(); // function to calculate distance of an object using infra red sensor
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
{
  Serial.begin(9600);
  // put your setup code here, to run once:
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
           tracksensors_testing(); 
           //forward(); 
           //lineTrack_PID(80, 82);                
     break; 
/*..............................................................................................................................*/
     case WAIT:
            
     break;
/*...............................................................................................................................*/
     case START:         
          button = digitalRead(Interrupt);
          //Serial.println(button);                  
          if (button == HIGH)
            {state = ARM_PARK;}
          else
          state = STAND_BY;
     break;
/*........................................................................................................................................*/
     case STAND_BY:
           Delay(500);
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
        state = TASK6;
     break;
/*........................................................................................................................................*/
     case TASK1:// move from start to point A then stop
          while (count<2)
          {
            
            //Track_line();
            count = Counter();
          }
          Stop();
          Delay(1000);
          count = 0; // reset counter
          state = TASK2;
                           
     break;
/*.......................................................................................................................................*/    
     case TASK2:// turn left
          U3 = digitalRead(sensor3); 
          while(U3==LOW)
          {
            turn_left();
            U3 = digitalRead(sensor3);
          }
          Stop();
          Delay(1000);
          state = TASK3;     
     break;
/*.......................................................................................................................................*/
     case TASK3:// move from point A to point B then stop
          while(count<3)
          {
            
            //Track_line();
            count = Counter();
          }
          Stop();
          Delay(1000);
          count = 0; // reset counter
          state = TASK4;   
     break;
/*.........................................................................................................................................*/
     case TASK4: //turn right
           U3 = digitalRead(sensor3);
          while(U3 == HIGH )
          {
            turn_right();
            U3 = digitalRead(sensor3);
          }
           U3 = digitalRead(sensor3);
          while(U3==LOW )
          {
            turn_right();
            U3 = digitalRead(sensor3);
          }
          Stop();
          Delay(1000);
          state = TASK5;
     break;
/*........................................................................................................................................*/
     case TASK5:// move from point B to point C then stop
          Dist = distance1();
          while(Dist>13)
          {
            
            //Track_line();
            Dist = distance1();
          }
          Stop();
          Delay(1000);
          state = TASK6;
     break;
/*........................................................................................................................................*/
     case TASK6://Pick yellow object and store it on the left carrier
          servo2.write(26,12);
          Delay(1500);
          servo1.write(51,12); // grip the yellow object
          Delay(1200);
          servo3.write(132,12);
          Delay(1200);
          servo2.write(49,12);
          Delay(1200);
          servo3.write(98,12);
          Delay(1200);
          servo2.write(71,12);
          Delay(1200);
          servo3.write(64,12);
          Delay(1200);
          servo4.write(8,12); // rotate the arm to the left carrier position
          Delay(1200);
          servo3.write(40,12);
          Delay(1200);
          servo2.write(119,12);
          Delay(1200);
          servo1.write(100,12); // ungrip the yellow object
          Delay(1200);
          
          forward(); // Inch forward alittle
          Delay(500);
          Stop();
          
          state = TASK7;
     break;
/*........................................................................................................................................*/
     case TASK7: // Search for the red object pick it and place it on the right carrier
          servo2.write(86,12);
          Delay(1200);
          
          servo4.write(60,12); // rotate the arm to the position of the red object
          Delay(1200);
          //SendData_2pi(1, 1, 1); // Send data to raspberry pi to take control of the arm
          //Delay(1000);
          //armobject_Search();
          //Delay(2000);
          
          servo3.write(90,12);
          Delay(1200);
          servo2.write(71,12);
          Delay(1200);
          servo3.write(127,12);
          Delay(1200);
          servo2.write(38,12);
          Delay(1200);
          servo3.write(159,12);
          Delay(1200);
          servo2.write(34,12);
          Delay(1200);
          servo1.write(51,12);// grip the red object
          
          Delay(1200);
          servo3.write(140,12);
          Delay(1200);
          servo2.write(50,12); 
          Delay(1200);
          servo1.write(62,120); // grip the red object
          Delay(1200);

          // Placing the red object on the right carrier
          servo3.write(123,12);
          Delay(1200);
          servo2.write(59,12);
          Delay(1200);
          servo3.write(74,12);
          Delay(1200);
          servo4.write(176,12);// rotate the arm to the right carrier position
          Delay(1200);
          servo3.write(56,12);
          Delay(1200);
          servo2.write(95,12);
          Delay(1200);
          servo3.write(40,12);
          Delay(1200);
          servo2.write(122,12);
          Delay(1200);
          servo1.write(100,12); // ungrip the red object
          Delay(1200);
          
          state = TASK8;
     break;
/*........................................................................................................................................*/
     case TASK8: // Pick the blue object 
          servo2.write(86,12);
          Delay(1200);
          servo4.write(120,12); // rotate the arm to the blue object position
          Delay(1200);
          servo3.write(102,12);
          Delay(1200);
          servo2.write(61,12);
          Delay(1200);
          servo3.write(132,12);
          Delay(1200);
          servo2.write(29,12);
          Delay(1200);
          servo3.write(157,12);
          Delay(1200);
          servo2.write(20,12);
          Delay(1200);
          servo3.write(165,12);
          Delay(1200);
          servo2.write(30,12);
          Delay(1200);
          servo1.write(51,12); // grip the blue object
          Delay(1200);
          servo2.write(20,12);
          Delay(1200);
          servo3.write(149,12);
          Delay(1200);
          servo4.write(90,12);
          Delay(1500);
          servo3.write(107,12);
          Delay(1200);
          servo2.write(86,12);
          Delay(1200);
          servo3.write(98,12);
          Delay(1200);
          servo2.write(85,12);
          Delay(1200);

          Delay(5000);
          state = ARM_PARK;
          
     break;
/*.........................................................................................................................................*/
     case TASK9: // Move from point D to point E and Stop
          turn_right();
          Delay(500);
          Stop();
          forward();
          Delay(1000);
          Stop();
          U3 = digitalRead(sensor3);
          while(U3==LOW )
          {
            turn_right();
            U3 = digitalRead(sensor3);
          }
          Stop();
          Delay(1000);
          
          Dist = distance1();
          while(Dist>13)
          {
            
            //Track_line();
            Dist = distance1();
          }
          Stop();
       
          state = TASK10;
     break;
     case TASK10:// Place the blue object in the blue container, and then pick the blue container

          servo1.write(85,12); //ungrip the blue object and drop it in the blue container
          Delay(1000);
          
          
          state = TASK11;
     break;
/*........................................................................................................................................*/
     case TASK11: // Move from point F to G then stop
          SendData_2pi(2, 2, 2); // Send data to raspberry pi to track the blue platform
          Delay(1000);
          Dist = distance1();
          while(Dist>13)
          {
          Trackobject_PID(20,0,0);
          //Trackobject();
          Dist = distance1();
          }
          Stop();
          Delay(2000);
          state = TASK12;
     break;
/*........................................................................................................................................*/
     case TASK12:// Place the blue package on the blue platform at point G

          servo3.write(132,12);
          Delay(1000);
          servo2.write(39,12);
          Delay(1000);
          servo3.write(100,12);
          Delay(1000);
          servo2.write(66,12);
          Delay(1000);
          servo3.write(73,12);
          Delay(1000);
          servo2.write(80,12);
          Delay(1000);
          servo3.write(50,12);
          Delay(1000);
          servo2.write(93,12);
          Delay(1000);
          
          forward();
          Delay(500);
          Stop();
          
          servo1.write(85,12); //ungrip the blue container to place it on the blue platform
          Delay(1000);

          reverse();
          Delay(1000);
          Stop();

         servo1.write(90,12); 
         Delay(1500);
         servo2.write(20,12);
         Delay(1500);
         servo3.write(165,12);// Setting the inital arm position
         Delay(1500);
         servo4.write(90,12);
         Delay(1500);
                
         state = TASK13; 
     break;
     case TASK13://Reverse from point G to point F then stop
          U6 = digitalRead(sensor6); U7 = digitalRead(sensor8);
          while(U6 == LOW )
          {
            reverse();
            U6 = digitalRead(sensor6); U7 = digitalRead(sensor7);       
          }
          Stop();
          Delay(2000);
          state = TASK14;    
     break;
/*..............................................................................................................*/
     case TASK14:// turn left
         U3 = digitalRead(sensor3);
         while(U3 == LOW )
         {
          turn_left();
          U3 = digitalRead(sensor3);
         }
         Stop();
         Delay(2000);
         state = TASK15;
     break;
/*..............................................................................................................*/
     case TASK15:// move from point F to H then stop
          U6 = digitalRead(sensor6); U7 = digitalRead(sensor7);
          while(U6 == LOW )
          {
           
            //Track_line();
            U6 = digitalRead(sensor7); U7 = digitalRead(sensor7);        
          }
          Stop();
          Delay(2000);
          state = TASK16;
     break;
/*..............................................................................................................*/
     case TASK16:// turn left
          U3 = digitalRead(sensor3);
          while(U3 == HIGH )
          {
            turn_left();
            U3 = digitalRead(sensor3); 
          }
      
          U3 = digitalRead(sensor3); 
          while(U3 == LOW )
          {
            turn_left();
            U3 = digitalRead(sensor3); 
          }
          Stop();
          Delay(2000);
          state == TASK17;          
     break;
/*...............................................................................................................*/
     case TASK17:// move from poit H to I then stop
         
          //Track_line();
          Delay(1000);
          U6 = digitalRead(sensor6); U7 = digitalRead(sensor7);
          while(U6 == LOW )
          {
           
           //Track_line();
           U6 = digitalRead(sensor6); U7 = digitalRead(sensor7); 
          }
          Stop();
          Delay(2000);
          state == TASK18;   
     break;
/*.......................................................................................................................*/
     case TASK18:// turn right
           U3 = digitalRead(sensor3);
          while(U3 == HIGH )
          {
            turn_right();
            U3 = digitalRead(sensor3); 
          }
          
          U3 = digitalRead(sensor3);
          while(U3 == LOW )
          {
            turn_right();
            U3 = digitalRead(sensor3); 
          }
          Stop();
          Delay(2000);
          state == TASK19;       
     break;
/*......................................................................................................................*/
     case TASK19:// move from point I to J then stop
          
          //Track_line();
          Delay(5000); // approximate time to travel from I to J
          Stop();
          state = TASK20;
     break;
/*......................................................................................................................*/
     case TASK20:// search for the red package container
          servo3.write(137,12);
          Delay(1000);
          servo2.write(60,12);
          Delay(1000);
          SendData_2pi(3, 3, 3); // Send data to raspberry pi initiate container search
          Delay(1000);
          Search_container();
          Delay(2000);
          state = TASK21;
     break;
/*......................................................................................................................*/
     case TASK21:// move from point J to K then stop
          SendData_2pi(4, 4, 4); // Send data to raspberry pi to track the red container
          Delay(1000);
          Dist = distance1();
          while(Dist>13)
          {
            Trackobject_PID(20,0,0);
            //Trackobject();
          Dist = distance1();
          }
          Stop();
          Delay(2000);
          state = TASK22;
     break;
/*......................................................................................................................*/
     case TASK22://place the red object in the red container

          state = TASK23;
     break;
/*......................................................................................................................*/
     case TASK23://Grip the red container then move from point K to point M stop and place the red container on the red platform

          servo3.write(151,12);
          Delay(1000);
          servo2.write(37,12);
          Delay(1000);
          servo1.write(78,12); // grip the red container
          Delay(1000);
          servo3.write(125,12);
          Delay(1000);
          servo2.write(48,12);
          Delay(1000);
          servo3.write(107,12);
          Delay(1000);
          servo2.write(61,12);
          Delay(1000);
          servo3.write(83,12);
          Delay(1000);
          servo2.write(80,12);
          Delay(1000);
          servo3.write(53,12);
          Delay(1000);
          servo2.write(132,12);
          Delay(1000);

          SendData_2pi(5, 5, 5); // Send data to raspberry pi to track the red platform
          Delay(1000);
          Dist = distance1();
          while(Dist>13)
          {
            Trackobject_PID(20,0,0);
            //Trackobject();
          Dist = distance1();
          }
          Stop();
          Delay(2000);

          forward();
          Delay(500);
          Stop();

          servo3.write(75,12);
          Delay(1000);
          servo2.write(89,12);
          Delay(1000);
          servo3.write(69,12);
          Delay(1000);
          servo1.write(85,12); //ungrip the red container on the red platform

          reverse();
          Delay(600);
          Stop();

         servo1.write(90,12); 
         Delay(1500);
         servo2.write(20,12);
         Delay(1500);
         servo3.write(165,12);// Setting the inital arm position
         Delay(1500);
         servo4.write(90,12);
         Delay(1500);
                  
          state = TASK24;
     break;
/*......................................................................................................................*/
     case TASK24: // reverse from point M to point J and stop
          while(count<2)
          {
            reverse();
            count = Counter();
          }
          Stop();
          Delay(2000);
          count = 0; // reset counter
          state = TASK25;
     break;
/*......................................................................................................................*/
     case TASK25:// turn right
          U3 = digitalRead(sensor3);
          while(U3 == LOW )
          {
            turn_right();
            U3 = digitalRead(sensor3);
          }
          Stop();
          Delay(2000);
          state == TASK26;
     break;
/*......................................................................................................................*/
     case TASK26:// Move from point J to point N then stop
          while(count<4)
          {
            
            //Track_line();
            count = Counter();
          }
          Stop();
          Delay(2000);
          state = TASK27;
     break;
/*......................................................................................................................*/
     case TASK27:// turn left
          U3 = digitalRead(sensor3); 
          while(U3 == HIGH )
          {
            turn_left();
            U3 = digitalRead(sensor3);
          }
           
          U3 = digitalRead(sensor3); 
          while(U3 == LOW )
          {
            turn_left();
            U3 = digitalRead(sensor3);
          }
          Stop();
          Delay(2000);
          state == TASK28;
     break;
/*......................................................................................................................*/
     case TASK28:// move from point D to pick E and stop
          Dist = distance1();
          while(Dist<13)
          {
          
          //Track_line();
          Dist = distance1();
          }
          Stop();
          Delay(2000);
          state = TASK29;
     break;
/*......................................................................................................................*/
     case TASK29:// place the yellow object into the container then pick the yellow container

          
          
          servo3.write(158,12); 
          Delay(1000);
          servo2.write(31,12); 
          Delay(1000);
          servo1.write(75,12);  // grip the yellow container
          Delay(1000);
          servo3.write(99,12); 
          Delay(1000);
          servo2.write(67,12); 
          Delay(1000);
          servo3.write(70,12); 
          Delay(1000);
          servo2.write(88,12); 
          Delay(1000);
                
          state = TASK30; 
     break;
/*......................................................................................................................*/
     case TASK30:// move from point O to point P and place the yellow container on the yellow platform
          Dist = distance1();
          while(Dist<13)
          {
          
          //Track_line();
          Dist = distance1();
          }
          Stop();
          Delay(2000);

          forward();
          Delay(500);

          servo3.write(79,12); 
          Delay(1000);
          servo2.write(102,12); 
          Delay(1000);
          servo1.write(85,12); // ungrip the yellow container to place it on the red platform
          Delay(1000);

          
         servo1.write(90,12); 
         Delay(1500);
         servo2.write(20,12);
         Delay(1500);
         servo3.write(165,12);// Setting the inital arm position
         Delay(1500);
         servo4.write(90,12);
         Delay(1500);
          
          
          state = TASK31;
     break;
/*......................................................................................................................*/
     case TASK31:// move from point P to the start point and park
          state = TASK32;
     break;
/*......................................................................................................................*/
     case TASK32: // task finished
          Delay(3000);
          state = STOP;
     break;
/*......................................................................................................................*/
     case FORWARD:
          forward();
     break;
/*......................................................................................................................*/
     case REVERSE:
          reverse();
     break;
/*......................................................................................................................*/
     case STOP: // To be used when the robot has finished its tasks or in code testing
          Stop();                          // Sequence to put the arm at rest postion
          Delay(2000);
          servo1.write(60,10); 
          Delay(3000);
          servo2.write(25,10);    
          Delay(3000);
          servo3.write(175,15);
          Delay(5000);
          servo4.write(88,10);
          Delay(3000);
          state = START;
     break; 
/*......................................................................................................................*/
 
  }

}

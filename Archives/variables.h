#ifndef variables_h
#define variables_h
#include <SharpIR.h>
#include <VarSpeedServo.h>
VarSpeedServo servo1; // grip servo
VarSpeedServo servo2; // shoulder servo
VarSpeedServo servo3; // elbow servo
VarSpeedServo servo4; // base servo  
#define IRPin A15                                          
#define model 1080   
SharpIR mySensor = SharpIR(IRPin,model); 
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


#endif
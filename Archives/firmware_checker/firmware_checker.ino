#include <VarSpeedServo.h>
//#include "Adafruit_VL53L0X.h"
/*#define lmotorf 40 //Motor A1
#define lmotorb 42 //Motor A2
#define rmotorf 44 //Motor B1
#define rmotorb 46 //Motor B2 ` 
#define l_pwm 13//Motor B1
#define r_pwm  12//Motor B2*/
// New pins
//Adafruit_VL53L0X lox = Adafruit_VL53L0X();
#define rmotorf 30 //Motor A1
#define rmotorb 32 //Motor A2
#define lmotorf 26 //Motor B1
#define lmotorb 28 //Motor B2 ` 
#define r_pwm 3//Motor B1
#define l_pwm  2//Motor B2

#define trigPin1 20// utrasonic
#define echoPin1 21 // ultra sonic
#define BAS_SERVO 8/* Base Servo HS */
#define WRI_SERVO 9 /* Wrist servo HS */
//#define WRO_SERVO 10/* Wrist rotate servo HS*/
#define GRI_SERVO 10/* Grpper servo HS left */
VarSpeedServo servo1,servo2,servo3,servo4;
/*
int l_max_speedJ = 70;
int r_max_speedJ =70;
int l_max_speedf = 120; 
int r_max_speedf =105; 
int l_max_speedr = 122;
int r_max_speedr =90; 
int l_max_speedt = 255;
int r_max_speedt =250;

*/
//new value palulu
 int l_max_speedf = 90; 
int r_max_speedf =90; 
int l_max_speedr = 30;
int r_max_speedr =31; 
int l_max_speedJ = 30;
int r_max_speedJ =31;
int l_max_speedt = 255;
int r_max_speedt =250;

int sensor1=0;//sensor1
int sensor2=0;//sensor2
int sensor3=0;//sensor3
int sensor4=0;//sensor4
int dist1; //variable to store distance from ultrasonic sensor
int counts=0;
long duration1;
//
int pwm =0 ;

bool ex1 = false;
bool ex2 = false;
bool ex3 = false;
bool ex4 = false;
bool ex5 = false;
bool ex6=false;
bool ex7=false;
bool ex8=false;
bool line_check=false;
bool line_check2=false;
bool line_check3=false;
bool white_M2=false;
bool white_J1=false;
bool white_J2=false;
bool white_rock2=false;
bool tracking=false;
bool dis=false;
bool dis2=false;
void setup() 
{
Serial.begin(9600);
pinMode(lmotorf,OUTPUT);
pinMode(rmotorf,OUTPUT);
pinMode(lmotorb,OUTPUT);
pinMode(rmotorb,OUTPUT);
pinMode(l_pwm,OUTPUT);
pinMode(r_pwm,OUTPUT);
pinMode(rmotorb,OUTPUT);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(39,INPUT);// sensors 1
pinMode(26,OUTPUT);// sensors 1
pinMode(38,INPUT);// sensors 2
pinMode(41,INPUT);// sensor 3swap with 4
pinMode(42,INPUT);// sensor 3swap with 4
pinMode(43,INPUT);// sensor 3swap with 4
pinMode(36,INPUT);// sensor 4 swap with sensor  3
pinMode(34,INPUT);// right middle sensor
pinMode(35,INPUT);// left middle sensor
 // wait until serial port opens for native USB devices


servo1.attach(BAS_SERVO, 544,2400);
servo2.attach( WRI_SERVO, 544, 2400 );
servo3.attach(  GRI_SERVO, 544, 2400);
//arm_park();
//pick_yellow();
delay(1000);
//packing_yellow();
//servo3.write(70,40);
 //  servo2.write(110,40);
 //   servo3.write(120,40);
               ex1=false;
              ex2=false;
              ex3=false;
              ex4=false;
              ex5=false;
              ex6=false;
              ex7=false;
              ex8=false;   
             
                 
}

void loop() 
{
 // read_sensor();

//distance1();
tracking2();
//forward();
}
//read_sensor();
 //
//tracking_reverse();

//pick_yellow();

//
/*while(ex1==false&&ex2==false&&ex3==false&&ex4==false&&ex5==false)//   [/]
{
int sensor1=digitalRead(34);//sensor1
int sensor2=digitalRead(36);//sensor2
int sensor3=digitalRead(38);//sensor3
int sensor4=digitalRead(40);//sensor4
int sensor5=digitalRead(42);//sensor5

 if((sensor1==1)&&(sensor2==1)&&(sensor3==1)&&(sensor4==1)&&(sensor5==1))// white line >>move forward&&(sensor3==0)&&(sensor4==0)&&(sensor5==0)
{ 
 stop_r();
 delay(1000); 
 //forward();
//delay (1000);  
                              ex1=false;
                              ex2=false;
                              ex3=false;
                              ex4=true; 
                              ex5=false;
                              ex7=false;
                              ex8=false;  
}
else 
{

tracking2();
} 
}


while (ex1==false&&ex2==false&&ex3==false&&ex4==true&&ex5==false) //  [/] find ing white line
{
 turn_left1();
 

}

while (ex1==false&&ex2==false&&ex3==false&&ex4==true&&ex5==true)//[/] finding the first white line
{  
int sensor1=digitalRead(34);//sensor1
int sensor2=digitalRead(36);//sensor2
int sensor3=digitalRead(38);//sensor3
int sensor4=digitalRead(40);//sensor4
int sensor5=digitalRead(42);//sensor5

 if((sensor1==0)&&(sensor2==0)&&(sensor3==0)&&(sensor4==0)&&(sensor5==0))// black line >>move forward&&(sensor3==0)&&(sensor4==0)&&(sensor5==0)//**********
{ 
stop_r();
 delay(500); 

tracking2();
delay(300);

                              ex1=false;
                              ex2=false;
                              ex3=true;
                              ex4=false; 
                              ex5=true;
                              ex7=false;
                              ex8=false;  
}
else 
{
 tracking2();
}
}

while (ex1==false&&ex2==false&&ex3==true&&ex4==false&&ex5==true)//2ns white line
{
int sensor1=digitalRead(34);//sensor1
int sensor2=digitalRead(36);//sensor2
int sensor3=digitalRead(38);//sensor3
int sensor4=digitalRead(40);//sensor4
int sensor5=digitalRead(42);//sensor5

 if((sensor1==0)&&(sensor2==0)&&(sensor3==0)&&(sensor4==0)&&(sensor5==0))// black line >>move forward&&(sensor3==0)&&(sensor4==0)&&(sensor5==0)//**********
{ 
 stop_r();
 delay(500); 
tracking2();
delay(300);

                         ex1=false;
                              ex2=true;
                              ex3=true;
                              ex4=true; 
                              ex5=false;
                              ex7=false;
                              ex8=false;  
}
else 
{
 tracking2();
} }
//delay(750);
                      
           


 while (ex1==false&&ex2==true&&ex3==true&&ex4==true&&ex5==false)// heading for first white line//[/]
{
int sensor1=digitalRead(34);//sensor1
int sensor2=digitalRead(36);//sensor2
int sensor3=digitalRead(38);//sensor3
int sensor4=digitalRead(40);//sensor4
int sensor5=digitalRead(42);//sensor5
if((sensor1==0)&&(sensor2==0)&&(sensor3==0)&&(sensor4==0)&&(sensor5==0))//white line at the centre . >>forward
{ 
stop_r();
delay(1000);
    analogWrite(l_pwm, r_max_speedf);
analogWrite(r_pwm, l_max_speedf);
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
delay(500);
              ex1=false;
              ex2=true;
              ex3=true;
              ex4=false;
              ex5=false;
              ex6=true;
              ex7=true;
              ex8=true;}
else
{
 tracking2();

}
 }


while(ex1==false&&ex2==true&&ex3==true&&ex4==false&&ex5==false&&ex6==true&&ex7==true&&ex8==true) //turn right to face yellow
if (sensor3==1)
{
analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm, r_max_speedf);
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}
else if((sensor3==0))//white line at the centre . >>forward
{ 
  stop_r();
  //
    //          ex1=false;
      //        ex2=true;
        //      ex3=true;
          //    ex4=false;
            //  ex5=false;
              //ex6=true;
              //ex7=false;
              //ex8=true;
    
}     

while (ex1==false&&ex2==true&&ex3==true&&ex4==false&&ex5==false&&ex6==true&&ex7==false&&ex8==true)// [/] find white line to face yellow
{
int a=  distance1();
 if ((a<=40))
 
 { 
  l_max_speedf = 130; 
  r_max_speedf =130;
                 //  pick_yellow(); 

}
else{
   l_max_speedf = 155; 
r_max_speedf =155;
tracking2();
}
}
while (ex1==false&&ex2==true&&ex3==true&&ex4==false&&ex5==false&&ex6==true&&ex7==true&&ex8==false)// [/]/************
{
     l_max_speedf = 155; 
r_max_speedf =155;
analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm, r_max_speedf);
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
delay(700);
             ex1=false;
              ex2=false;
              ex3=true;
              ex4=false;
              ex5=false;
              ex6=true;
              ex7=false;
              ex8=true;  

}

while (ex1==false&&ex2==false&&ex3==true&&ex4==false&&ex5==false&&ex6==true&&ex7==false&&ex8==true)// having about turn.
{
int sensor1=digitalRead(34);//sensor1
int sensor2=digitalRead(36);//sensor2
int sensor3=digitalRead(38);//sensor3
int sensor4=digitalRead(40);//sensor4
int sensor5=digitalRead(42);//sensor5
if((sensor3==1))//white line at the centre . >>forward
{ 

  analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm, r_max_speedf+20);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,HIGH);

}
              else  if((sensor3==0))
              {
                stop_r();
                        ex1=false;
              ex2=false;
              ex3=true;
              ex4=true;
              ex5=true;
              ex6=true;
              ex7=false;
              ex8=true;  
              }
              }

while (ex1==false&&ex2==false&&ex3==true&&ex4==true&&ex5==true&&ex6==true&&ex7==false&&ex8==true)// about turn after picking yellow to offtrack //[/]
{
int sensor1=digitalRead(34);//sensor1
int sensor2=digitalRead(36);//sensor2
int sensor3=digitalRead(38);//sensor3
int sensor4=digitalRead(40);//sensor4
int sensor5=digitalRead(42);//sensor5

 if((sensor1==0)&&(sensor2==0)&&(sensor3==0)&&(sensor4==0)&&(sensor5==0))// black line >>move forward&&(sensor3==0)&&(sensor4==0)&&(sensor5==0)//**********
{ 
stop_r();
 delay(500); 

tracking2();
delay(300);

                              ex1=false;
                              ex2=true;
                              ex3=false;
                              ex4=false; 
                              ex5=false;
                              ex6=true;
                              ex7=false;
                              ex8=true;  
}
else 
{
 tracking2();
}
 }            

while (ex1==false&&ex2==true&&ex3==false&&ex4==false&&ex5==false&&ex6==true&&ex7==false&&ex8==true)// getting off the track heading to pack yellow //[/]
{
int sensor1=digitalRead(34);//sensor1
int sensor2=digitalRead(36);//sensor2
int sensor3=digitalRead(38);//sensor3
int sensor4=digitalRead(40);//sensor4
int sensor5=digitalRead(42);//sensor5
  
  if((sensor1==0)&&(sensor2==0)&&(sensor3==0)&&(sensor4==0)&&(sensor5==0))// black line >>move forward&&(sensor3==0)&&(sensor4==0)&&(sensor5==0)//**********
{ 
analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm, r_max_speedf+20);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
delay(600);
                              ex1=false;
                              ex2=true;
                              ex3=false;
                              ex4=false; 
                              ex5=true;
                              ex6=true;
                              ex7=false;
                              ex8=true;  
}
else 
{
 tracking2();
}
 }  
 while (ex1==false&&ex2==true&&ex3==false&&ex4==false&&ex5==true&&ex6==true&&ex7==false&&ex8==true)// back to track heading 1st white line. //[/]
{
    int sensor1=digitalRead(37);//sensor1
    int sensor2=digitalRead(39);//sensor2
    int sensor3=digitalRead(41);//sensor3
 
  if((sensor3==0))//TO RIGHT JERK

{ 
 stop_r();
 delay(1000); 
 
                              ex1=false;
                              ex2=true;
                              ex3=false;
                              ex4=true; 
                              ex5=false;
                              ex6=true;
                              ex7=false;
                              ex8=true;  
                           
}
else if(sensor3==1)
{
analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm, r_max_speedf-10);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}

 }               
 
while (ex1==false&&ex2==true&&ex3==false&&ex4==true&&ex5==false&&ex6==true&&ex7==false&&ex8==true)// heading for 2nd white line//[/]
{

// packing_yellow();
 }   

while (ex1==false&&ex2==true&&ex3==false&&ex4==true&&ex5==true&&ex6==true&&ex7==false&&ex8==true)//About turn reversing[/]
{
 
//placing_yellow_park();
 //turn_left2();
 
 }   
      
 while (ex1==true&&ex2==true&&ex3==true&&ex4==false&&ex5==false&&ex6==true&&ex7==true&&ex8==true)// heading for first white line//[/] turning after packing object1
{
analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm, r_max_speedf);
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
delay(700);

             ex1=false;
              ex2=true;
              ex3=true;
              ex4=true;
              ex5=true;
              ex6=true;
              ex7=true;
              ex8=true;  
}

 while (ex1==false&&ex2==true&&ex3==true&&ex4==true&&ex5==true&&ex6==true&&ex7==true&&ex8==true)// heading for first white line after container//[/]
{
int sensor1=digitalRead(34);//sensor1
int sensor2=digitalRead(36);//sensor2
int sensor3=digitalRead(38);//sensor3
int sensor4=digitalRead(40);//sensor4
int sensor5=digitalRead(42);//sensor5
if((sensor3==1))//white line at the centre . >>forward
{ 

  analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm, r_max_speedf);
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);

}
              else  if((sensor3==0))
              {
                stop_r();
                  ex1=true;
              ex2=false;
              ex3=false;
              ex4=true;
              ex5=true;
              ex6=true;
              ex7=true;
              ex8=true;
              }
}
 while (ex1==true&&ex2==false&&ex3==false&&ex4==false&&ex5==false&&ex6==true&&ex7==true&&ex8==true)// heading for fsecond white line after container//[/]
{
  int sensor1=digitalRead(34);//sensor1
int sensor2=digitalRead(36);//sensor2
int sensor3=digitalRead(38);//sensor3
int sensor4=digitalRead(40);//sensor4
int sensor5=digitalRead(42);//sensor5
  
  if((sensor1==0)&&(sensor2==0)&&(sensor3==0)&&(sensor4==0)&&(sensor5==0))// black line >>move forward&&(sensor3==0)&&(sensor4==0)&&(sensor5==0)//**********
{ 
                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                delay(600);
                 ex1=true;
              ex2=false;
              ex3=false;
              ex4=false;
              ex5=false;
              ex6=true;
              ex7=true;
              ex8=true;
}
else{
  tracking2();
}

}
 while (ex1==true&&ex2==false&&ex3==false&&ex4==false&&ex5==true&&ex6==true&&ex7==true&&ex8==true)// heading for first white line//[/]
{
   int sensor1=digitalRead(34);//sensor1
int sensor2=digitalRead(36);//sensor2
int sensor3=digitalRead(38);//sensor3
int sensor4=digitalRead(40);//sensor4
int sensor5=digitalRead(42);//sensor5
if((sensor3==1))//white line at the centre . >>forward
{ 

  analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm, r_max_speedf+20);
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);

}
              else  if((sensor3==0))
              {
                stop_r();
              ex1=true;
              ex2=false;
              ex3=false;
              ex4=true;
              ex5=false;
              ex6=true;
              ex7=true;
              ex8=true;  
              }
}

 while (ex1==true&&ex2==false&&ex3==false&&ex4==true&&ex5==false&&ex6==true&&ex7==true&&ex8==true)// heading for first white line//[/]
{
  int sensor1=digitalRead(34);//sensor1
int sensor2=digitalRead(36);//sensor2
int sensor3=digitalRead(38);//sensor3
int sensor4=digitalRead(40);//sensor4
int sensor5=digitalRead(42);//sensor5
  
  if((sensor1==0)&&(sensor2==0)&&(sensor3==0)&&(sensor4==0)&&(sensor5==0))// black line >>move forward&&(sensor3==0)&&(sensor4==0)&&(sensor5==0)//**********
{ 
                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                delay(500);
                 ex1=true;
              ex2=false;
              ex3=false;
              ex4=true;
              ex5=true;
              ex6=true;
              ex7=true;
              ex8=true;
}
else{
  tracking2();
}

}
 while (ex1==true&&ex2==false&&ex3==false&&ex4==true&&ex5==true&&ex6==true&&ex7==true&&ex8==true)// heading for first white line//[/]
{
 forward();
 delay(200);
                 ex1=true;
              ex2=true;
              ex3=false;
              ex4=false;
              ex5=true;
              ex6=true;
              ex7=true;
              ex8=true;
 
}
 while (ex1==true&&ex2==true&&ex3==false&&ex4==false&&ex5==true&&ex6==true&&ex7==true&&ex8==true)// heading for first white line//[/]
{
stop_r();
}//

}*/

void forward ()
{
  analogWrite(l_pwm, l_max_speedf+10);
analogWrite(r_pwm, r_max_speedf+10);
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}
void reverse ()
{
 
  analogWrite(l_pwm, r_max_speedf);
analogWrite(r_pwm, l_max_speedf);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,HIGH);
digitalWrite(rmotorb,HIGH);
}
void reverse_2 ()
{
  analogWrite(l_pwm, 95);
analogWrite(r_pwm, 87);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,HIGH);
digitalWrite(rmotorb,HIGH);
}

int distance1() // Distance from the ultra sonic sensor
{
  digitalWrite (trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite (trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  dist1 = duration1 * 0.034 / 2;
      Serial.print("dist1");
      Serial.print("= ");
Serial.println(dist1);
  return dist1 = duration1 * 0.034 / 2;

}
void read_sensor()
{
  int sensor1=digitalRead(34);//sensor1
  Serial.print("sensor 1");
      Serial.print("= ");
Serial.print(sensor1);



Serial.print("\t");
int sensor2=digitalRead(36);//sensor3
Serial.print("sensor 2");
      Serial.print("= ");
Serial.print(sensor2);

Serial.print("\t");
int sensor3=digitalRead(38);//sensor2
Serial.print("sensor 3");
      Serial.print("= ");
Serial.print(sensor3);

Serial.print("\t");
Serial.print("");


int sensor4=digitalRead(40);//sensor5
Serial.print("sensor 4");
      Serial.print("= ");
Serial.print(sensor4);

Serial.print("\t");
Serial.print("");
//delay(1000);

int sensor5=digitalRead(42);//sensor5
Serial.print("sensor 5");
      Serial.print("= ");
Serial.print(sensor5);

Serial.print("\t");
Serial.println("");
//delay(1000);

}
void stop_r()
{
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}

#include "variables.h"
int Counter()
{
  if(digitalRead(sensor7)==LOW)
  {
    count = count+1;
    //lineTrack_PID();
    //Track_line();
    Delay(1000);
  }
  return count;
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

void Track_line() // Using five channel sensor
{
U1 = digitalRead(sensor1);  U2 = digitalRead(sensor2);   U3 = digitalRead(sensor3);  U4 = digitalRead(sensor4);   U5 = digitalRead(sensor5);
      
if (U1 == HIGH && U2 == HIGH && U3 == HIGH && U4 == HIGH && U5 == HIGH)
{//error = 0
  digitalWrite(rightIN1, HIGH);
  digitalWrite(rightIN2, LOW);
  analogWrite(PWM_Right,60 );
  digitalWrite(leftIN3, HIGH);
  digitalWrite(leftIN4, LOW);
  analogWrite(PWM_Left,60);
}
else if  (U1 == HIGH && U2 == HIGH && U3 == HIGH && U4 == LOW && U5 == LOW)
{//error = 0
  digitalWrite(rightIN1, HIGH);
  digitalWrite(rightIN2, LOW);
  analogWrite(PWM_Right,60 );
  digitalWrite(leftIN3, HIGH);
  digitalWrite(leftIN4, LOW);
  analogWrite(PWM_Left,60);
}
else if  (U1 == LOW && U2 == LOW && U3 == HIGH && U4 == HIGH && U5 == HIGH)
{//error = 0
  digitalWrite(rightIN1, HIGH);
  digitalWrite(rightIN2, LOW);
  analogWrite(PWM_Right,60 );
  digitalWrite(leftIN3, HIGH);
  digitalWrite(leftIN4, LOW);
  analogWrite(PWM_Left,60);
}
else if  (U1 == LOW && U2 == LOW && U3 == HIGH && U4 == LOW && U5 == LOW)
{//error = 0
  digitalWrite(rightIN1, HIGH);
  digitalWrite(rightIN2, LOW);
  analogWrite(PWM_Right,60 );
  digitalWrite(leftIN3, HIGH);
  digitalWrite(leftIN4, LOW);
  analogWrite(PWM_Left,60);
}
else if  (U1 == LOW && U2 == LOW && U3 == HIGH && U4 == HIGH && U5 == LOW)
{//error = 1;
  digitalWrite(rightIN1, HIGH);
  digitalWrite(rightIN2, LOW);
  analogWrite(PWM_Right,60 );
  digitalWrite(leftIN3, HIGH);
  digitalWrite(leftIN4, LOW);
  analogWrite(PWM_Left,70);
}
else if  (U1 == LOW && U2 == LOW && U3 == LOW && U4 == HIGH && U5 == LOW)
{//error = 2;
  digitalWrite(rightIN1, HIGH);
  digitalWrite(rightIN2, LOW);
  analogWrite(PWM_Right,0 );
  digitalWrite(leftIN3, HIGH);
  digitalWrite(leftIN4, LOW);
  analogWrite(PWM_Left,60);
}
else if  (U1 == LOW && U2 == LOW && U3 == LOW && U4 == HIGH && U5 == HIGH)
{//error = 3;
  digitalWrite(rightIN1, HIGH);
  digitalWrite(rightIN2, LOW);
  analogWrite(PWM_Right,0 );
  digitalWrite(leftIN3, HIGH);
  digitalWrite(leftIN4, LOW);
  analogWrite(PWM_Left,80);
}
else if  (U1 == LOW && U2 == LOW && U3 == LOW && U4 == LOW && U5 == HIGH)
{//error = 4;
  digitalWrite(rightIN1, HIGH);
  digitalWrite(rightIN2, LOW);
  analogWrite(PWM_Right,0 );
  digitalWrite(leftIN3, HIGH);
  digitalWrite(leftIN4, LOW);
  analogWrite(PWM_Left,100);
}
else if  (U1 == LOW && U2 == HIGH && U3 == HIGH && U4 == LOW && U5 == LOW)
{//error = -1;
  digitalWrite(rightIN1, HIGH);
  digitalWrite(rightIN2, LOW);
  analogWrite(PWM_Right,70 );
  digitalWrite(leftIN3, HIGH);
  digitalWrite(leftIN4, LOW);
  analogWrite(PWM_Left,60);
}
else if  (U1 == LOW && U2 == HIGH && U3 == LOW && U4 == LOW && U5 == LOW)
{//error = -2;
  digitalWrite(rightIN1, HIGH);
  digitalWrite(rightIN2, LOW);
  analogWrite(PWM_Right,60 );
  digitalWrite(leftIN3, HIGH);
  digitalWrite(leftIN4, LOW);
  analogWrite(PWM_Left,0);
}
else if  (U1 == HIGH && U2 == HIGH && U3 == LOW && U4 == LOW && U5 == LOW)
{//error = -3;
  digitalWrite(rightIN1, HIGH);
  digitalWrite(rightIN2, LOW);
  analogWrite(PWM_Right,80 );
  digitalWrite(leftIN3, HIGH);
  digitalWrite(leftIN4, LOW);
  analogWrite(PWM_Left,0);
}
else if  (U1 == HIGH && U2 == LOW && U3 == LOW && U4 == LOW && U5 == LOW)
{//error = -4;
  digitalWrite(rightIN1, HIGH);
  digitalWrite(rightIN2, LOW);
  analogWrite(PWM_Right,0 );
  digitalWrite(leftIN3, HIGH);
  digitalWrite(leftIN4, LOW);
  analogWrite(PWM_Left,100);
}
else if (U1 == LOW && U2 == LOW && U3 == LOW && U4 == LOW && U5 == LOW)
{
 analogWrite(PWM_Right,0); analogWrite(PWM_Left,0);
}

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
 analogWrite(PWM_Right,0); analogWrite(PWM_Left,0); 
}

 power = (Kp*error) + (Kd*(error-previousError)) + (Ki*totalError);
 previousError = error; // save previous error for differential 
 totalError += error; // Accumulate error for integral
     
    if(power<0) // Turn left
    {
      Right_Speed = R_speed - power;
      Left_Speed = L_speed -5;
      analogWrite(PWM_Left,Left_Speed );
      analogWrite( PWM_Right,Right_Speed);
      digitalWrite(leftIN3, HIGH);
      digitalWrite(leftIN4, LOW);
      digitalWrite(rightIN1, HIGH);
      digitalWrite(rightIN2, LOW); 
    }
    
   else if(power>0) // Turn right
    {
      Right_Speed = R_speed - power;
      Left_Speed = L_speed + 5;
      analogWrite(PWM_Left,Left_Speed );
      analogWrite( PWM_Right,Right_Speed);
      digitalWrite(leftIN3, HIGH);
      digitalWrite(leftIN4, LOW);
      digitalWrite(rightIN1, HIGH);
      digitalWrite(rightIN2, LOW);     
    }
    
   else if(power==0)
    {
      Right_Speed = R_speed;
      Left_Speed = L_speed;
      analogWrite(PWM_Left,Left_Speed );
      analogWrite( PWM_Right,Right_Speed);
      digitalWrite(leftIN3, HIGH);
      digitalWrite(leftIN4, LOW);
      digitalWrite(rightIN1, HIGH);
      digitalWrite(rightIN2, LOW);
    }
}

void tracksensors_testing()
{
U1 = digitalRead(sensor1);  U2 = digitalRead(sensor2);  U3 = digitalRead(sensor3);   U4 = digitalRead(sensor4);   U5 = digitalRead(sensor5); U6 = digitalRead(sensor6);   U7 = digitalRead(sensor7);
    
if (U1 == HIGH && U2 == HIGH && U3 == HIGH && U4 == HIGH && U5 == HIGH)
{ error = 0;}
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
 analogWrite(PWM_Right,0); analogWrite(PWM_Left,0);
}
      
 power = (Kp*error) + (Kd*(error-previousError)) + (Ki*totalError);
 previousError = error; // save previous error for differential 
 totalError += error; // Accumulate error for integral

 Serial.print(U1);
 Serial.print("\t");
 Serial.print(U2);
 Serial.print("\t");
 Serial.print(U3);
 Serial.print("\t");
 Serial.print(U4);
 Serial.print("\t");
 Serial.print(U5);
 Serial.print("\t");
 Serial.print(U6);
 Serial.print("\t");
 Serial.print(U7);
 Serial.print("\t");
 Serial.print(error);
 Serial.print("\t");
 Serial.print( power );
 Serial.print("\t");
 Serial.print(Left_Speed );
 Serial.print("\t");
 Serial.print(Right_Speed);
 Serial.print("\n");
 Delay (2000);
}

int distance1()
{
  int dist = 0;
  dist = mySensor.distance();
  return dist;
}

void forward()
{
  digitalWrite(rightIN1, HIGH);
  digitalWrite(rightIN2, LOW);
  analogWrite(PWM_Right,80 );
  digitalWrite(leftIN3, HIGH);
  digitalWrite(leftIN4, LOW);
  analogWrite(PWM_Left,82);
 // using balanced speeds 
}

void reverse()
{
  digitalWrite(rightIN1, LOW);
  digitalWrite(rightIN2, HIGH);
  analogWrite(PWM_Right,80 );
  digitalWrite(leftIN3, LOW);
  digitalWrite(leftIN4, HIGH);
  analogWrite(PWM_Left,82 );
  // using balanced speeds
}

void Stop()
{analogWrite(PWM_Right,0 );
 analogWrite(PWM_Left,0);
}

void turn_left()
{ digitalWrite(rightIN1, HIGH);
  digitalWrite(rightIN2, LOW);
  analogWrite(PWM_Right,90 );
  digitalWrite(leftIN3, LOW);
  digitalWrite(leftIN4, HIGH);
  analogWrite(PWM_Left,90);
}

void turn_right()
{ digitalWrite(rightIN1, LOW);
  digitalWrite(rightIN2, HIGH);
  analogWrite(PWM_Right,90 );
  digitalWrite(leftIN3, HIGH);
  digitalWrite(leftIN4, LOW);
  analogWrite(PWM_Left,90);
}

void SendData_2pi(int a1, int b2, int c3)
{
  // Function tested and working
 int a=a1;
 int b=b2;
 int c=c3;

 while(!Serial){};
 Serial.print(a);
 Serial.print(",");
 Serial.print(b);
 Serial.print(",");
 Serial.println(c);
 Delay(500); // delay can be commented or removed to prevent the micro_p from slowing down
}

int GetData_from_pi()
{
  int a=0;
  int b=0;
  int c=0;
  
  while(!Serial){}
  if(Serial.available()>0)
  {
    a = Serial.parseInt();
    b = Serial.parseInt();
    c = Serial.parseInt();
  }
  return (a+b+c);
}

void Search_container()
{
while (Serial.available()>0)
  {
    int p = Serial.parseInt();
    int pwm = Serial.parseInt();
    
    if (pwm==0)
    {
        digitalWrite(rightIN1, HIGH);
        digitalWrite(rightIN2, LOW);
        analogWrite(PWM_Right,0 );
        digitalWrite(leftIN3, HIGH);
        digitalWrite(leftIN4, LOW);
        analogWrite(PWM_Left,0);
    }
   else if (pwm>0)
   {
       digitalWrite(rightIN1, HIGH);
       digitalWrite(rightIN2, LOW);
       analogWrite(PWM_Right,90 );
       digitalWrite(leftIN3, LOW);
       digitalWrite(leftIN4, HIGH);
       analogWrite(PWM_Left,94);
   }
  else
  {
      digitalWrite(rightIN1, LOW);
      digitalWrite(rightIN2, HIGH);
      analogWrite(PWM_Right,90 );
      digitalWrite(leftIN3, HIGH);
      digitalWrite(leftIN4, LOW);
      analogWrite(PWM_Left,94);
  }
  
  }

}

void Trackobject()
{
  if (Serial.available()>0)
  {
    int p = Serial.parseInt();
    int pwm = Serial.parseInt();
    
    if (pwm==0)
       {
        digitalWrite(rightIN1, HIGH);
        digitalWrite(rightIN2, LOW);
        analogWrite(PWM_Right,90 );
        digitalWrite(leftIN3, HIGH);
        digitalWrite(leftIN4, LOW);
        analogWrite(PWM_Left,94);
       }
   else if (pwm>0)
      {
       digitalWrite(rightIN1, LOW);
       digitalWrite(rightIN2, HIGH);
       analogWrite(PWM_Right,90 );
       digitalWrite(leftIN3, HIGH);
       digitalWrite(leftIN4, LOW);
       analogWrite(PWM_Left,94);
      }
  else
    {
      digitalWrite(rightIN1, HIGH);
      digitalWrite(rightIN2, LOW);
      analogWrite(PWM_Right,90 );
      digitalWrite(leftIN3, LOW);
      digitalWrite(leftIN4, HIGH);
      analogWrite(PWM_Left,94);
    }
  
  }

}

void Trackobject_PID(int p,int d, int i)
{
  int KP = p; int KD = d; int KI = i;
  if (Serial.available()>0)
  {
    int p = Serial.parseInt();
    int error = Serial.parseInt();
    power = (KP*error)+(KD*(error-previousError))+(KD*totalError);
    previousError = error;
    totalError += error;
    if (power<0) // Turn left
     {
      Right_Speed = 60 - power;
      Left_Speed = 60;
      analogWrite(PWM_Left,Left_Speed);
      analogWrite(PWM_Right,Right_Speed);
      digitalWrite(leftIN3, HIGH);
      digitalWrite(leftIN4,LOW);
      digitalWrite(rightIN1,HIGH);
      digitalWrite(rightIN2,LOW);
     }
    else if  (power>0) // Turn right
     {
      Right_Speed = 60 - power;
      Left_Speed = 60;
      analogWrite(PWM_Left,Left_Speed);
      analogWrite(PWM_Right,Right_Speed);
      digitalWrite(leftIN3, HIGH);
      digitalWrite(leftIN4,LOW);
      digitalWrite(rightIN1,HIGH);
      digitalWrite(rightIN2,LOW);
     }
    else
     {
      Right_Speed = 60;
      Left_Speed = 60;
      analogWrite(PWM_Left,Left_Speed);
      analogWrite(PWM_Right,Right_Speed);
      digitalWrite(leftIN3, HIGH);
      digitalWrite(leftIN4,LOW);
      digitalWrite(rightIN1,HIGH);
      digitalWrite(rightIN2,LOW);
     }
  }
}

void armcontrol_FromPi()
{
  if(Serial.available()>0)
     {
  
      int angle_1 = Serial.parseInt();
      int angle_2 = Serial.parseInt() ;
      int angle_3 = Serial.parseInt();     
      servo1.write(5,20); // base servo
      delay(1000);
      servo2.write(120,20); // shoulder servo
      delay(1000);
      servo3.write(150,20); // grip servo
      delay(1000);

    }
}

void armobject_Search()
{
  int angle4 = 175;
  servo4.write(angle4,10);
  Delay(3000);
  while(Serial.available() != 0)
  {
    int y = Serial.parseInt();
    y = Serial.parseInt();
    if (y == 0)
    {break;}
    else
    {
      servo4.write((angle4-=2),12); // base servo
      Delay(500);
      if(angle4<10)
      {break;}
    }
       
  }
}
    

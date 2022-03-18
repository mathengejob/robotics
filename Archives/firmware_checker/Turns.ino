void turn_right_off()// RIGHT turn on second turn. check that.
{
 
              reduce_speed();
                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                delay(500);

  
}
void turn_left_off()// RIGHT turn on second turn. check that.
{
 
            //  reduce_speed();
                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                delay(500);

  
}
void turn_right1()// RIGHT turn on second turn.
{
 int sensor1=digitalRead(43);//sensor1
int sensor2=digitalRead(42);//sensor2
int sensor3=digitalRead(37);//sensor3
int sensor4=digitalRead(41);//sensor4
int sensor5=digitalRead(39);//sensor5
//
 
  if (sensor3==1)
  {
  
                  analogWrite(l_pwm,l_max_speedf-5);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);

   }
else if (sensor3==0)
              {
                 /*              ex1=false;
              ex2=false;
              ex3=true;
              ex4=true;
              ex5=false;                
                   */
                   stop_r();
                                                  ex1=true;
                              ex2=true;
                              ex3=true;
                              ex4=true; 
                              ex5=true;
 
}
}
void turn_right2()// RIGHT turn on second turn.
{
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
 
  if (sensor3==LOW)
  {
  
                  analogWrite(l_pwm,l_max_speedf-5);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);

   }
else if (sensor3==HIGH)
              {
                stop_r();
              ex1=false;
              ex2=false;
              ex3=true;
              ex4=true;
              ex5=false;                
                   
 
}
}
void turn_right3()// RIGHT turn on second turn.
{
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
 
  if (sensor3==LOW)
  {
  
                  analogWrite(l_pwm,l_max_speedf-5);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);

   }
else if (sensor3==HIGH)
              {
                stop_r();
              ex1=true;
              ex2=false;
              ex3=true;
              ex4=false;
              ex5=false;                
                   
 
}
}

void turn_left1()// RIGHT turn on second turn.
{
 // forward();
  //delay(1000);
  //stop_r();
 int sensor1=digitalRead(43);//sensor1
int sensor2=digitalRead(42);//sensor2
int sensor3=digitalRead(37);//sensor3
int sensor4=digitalRead(41);//sensor4
int sensor5=digitalRead(39);//sensor5

  if (sensor3==1){
  
                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);

                      }
                      else if (sensor3==0)
                      {
                        stop_r();
                        delay(2000);
                        ex1=false;
              ex2=false;
              ex3=false;
              ex4=true;
              ex5=true;
                      }

}
void turn_left2a()// RIGHT turn on second turn.
{

 int sensor1=digitalRead(43);//sensor1
int sensor2=digitalRead(42);//sensor2
int sensor3=digitalRead(37);//sensor3
int sensor4=digitalRead(41);//sensor4
int sensor5=digitalRead(39);//sensor5

  if (sensor3==1){
  
                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);

                      }
                      else if (sensor3==0)
                      {
                        stop_r();
                        delay(1000);
                        ex1=false;
              ex2=true;
              ex3=true;
              ex4=false;
              ex5=false;
              ex6=true;
              ex7=false;
              ex8=false;
                      }

}
void turn_left2b()// RIGHT turn on second turn.
{

 int sensor1=digitalRead(43);//sensor1
int sensor2=digitalRead(42);//sensor2
int sensor3=digitalRead(37);//sensor3
int sensor4=digitalRead(41);//sensor4
int sensor5=digitalRead(39);//sensor5

  if (sensor3==1){
  
                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);

                      }
                      else if (sensor3==0)
                      {
                        stop_r();
                        delay(1000);
                        ex1=false;
              ex2=true;
              ex3=true;
              ex4=false;
              ex5=false;
              ex6=true;
              ex7=false;
              ex8=true;
                      }

}
void turn_L_M2()// RIGHT turn on second turn.
{
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
  if (((sensor2==LOW)&& (sensor3==LOW))||((sensor3==LOW))){
  
                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);

                      }

}
void turn_L_rock1a()// turn to face block
{
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
  if ((sensor5==LOW)&& (sensor5==LOW)){
  
                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);

                      }
else if ((sensor5==HIGH)&& (sensor5==HIGH))
              {
                       
                       Serial.print("counts");
                       Serial.print("= ");
                       Serial.println( counts);
                         stop_r(); 
                           
 ex1=false;
              ex2=false;
              ex3=true;
              ex4=false;
              ex5=false;
              ex7=true;
              ex8=true;
 
}
}
void turn_L_rock1()// turn to face block
{
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
  if (((sensor3==LOW)&& (sensor4==LOW))||((sensor3==LOW))){
  
                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);

                      }
else if (((sensor3==HIGH)&& (sensor4==HIGH))||((sensor3==HIGH)))
              {
                       
                       Serial.print("counts");
                       Serial.print("= ");
                       Serial.println( counts);
                         stop_r(); 
                           
 ex1=false;
              ex2=false;
              ex3=false;
              ex4=false;
              ex5=true;
              ex7=false;
              ex8=true;     
 
}
}

void turn_LEFTM()// RIGHT turn on second turn. awl
{
  //bool track=false;
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
  
   if((sensor5==HIGH)&&(sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH)&&(sensor1==HIGH))
  {
  
                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                delay(700);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                  delay(1200);
                   digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                delay(700);
               ex1=false;
              ex2=true;
              ex3=false;
              ex4=true;
              ex5=false;
              ex7=false;
              ex8=false;
                      }
                      
 else
     {                                
                       Serial.print("counts");
                       Serial.print("= ");
                       Serial.println( counts);
        //
}
}
void turn_LEFTM2()// so as to place m1 awl
{
  //bool track=false;
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
  
   if(sensor3==LOW)
  {
  
                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                //stop_r();
                //delay (600);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,HIGH);
                
           
                      }
 else if (sensor3==HIGH)

{ 
  stop_r();
  delay(1000);
  ex1=false;
              ex2=true;
              ex3=true;
              ex4=false;
              ex5=false;
              ex7=false;
              ex8=false;
                    

}
}
void turn_LEFT_Motor2()// 
{
  //bool track=false;
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
  
   if((sensor5==HIGH)&&(sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH)&&(sensor1==HIGH))
  {
  
                  analogWrite(l_pwm,l_max_speedf);// REVERSE FOR .THREE SEC
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,HIGH);
                digitalWrite(rmotorb,HIGH);
                delay(300);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                  delay(500);
                 ex1=false;
            ex2=true;
            ex3=false;
            ex4=true; 
            ex5=false;
            ex7=true; 
                      }
  else if((sensor5==LOW)&&(sensor4==LOW)&&(sensor3==LOW)&&(sensor2==LOW)&&(sensor1==LOW))
  {
  
                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
              
                      }           
        else 
        {
                Serial.print("counts");
                       Serial.print("= ");
                       Serial.println( counts);
                          tracking2();       
        }
}

void tun_left_off()
{

  if (sensor3==LOW)
  {
     analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
  }
  else if(sensor4==HIGH)
  {
    forward;
   // place_m1();
  }
           
}
void tun_left_off_rock2()
{
                 analogWrite(l_pwm,l_max_speedf-10);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,HIGH);
                digitalWrite(rmotorb,LOW);
                delay(1000);
                
               ex1=false;
              ex2=false;
              ex3=false;
              ex4=true;
              ex5=true;
           
              ex7=true;
              ex8=true;
               
}
void tun_left_off2()// turn to place motor 2
{
    /*  int sensor1=digitalRead(37);//sensor1
int sensor2=digitalRead(39);//sensor2
int sensor3=digitalRead(41);//sensor3
int sensor4=digitalRead(43);//sensor4
int sensor5=digitalRead(45);//sensor5
 // tracking2();
          if(sensor3==LOW)
             {                    // arm_park(); 

              stop_r();
              delay(200)
              ex1=true;
              ex2=false;
              ex3=true;
              ex4=false;
              ex5=true;
              ex7=true;
             }
             else if (sensor3==HIGH)
          {
             analogWrite(l_pwm,100);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
          }*/
              analogWrite(l_pwm,l_max_speedf-10);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                delay(500);
                         
}
void turn_RIGHT2()// RIGHT turn on second turn.
{
  bool track=false;
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
  
   if((sensor5==HIGH)&&(sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH)&&(sensor1==HIGH))
  {
  
                  analogWrite(l_pwm,l_max_speedf-10);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                delay(300);
               
                      }
else if ((sensor5==LOW)&&(sensor4==LOW)&&(sensor3==HIGH)&&(sensor2==LOW)&&(sensor1==LOW))
              {   
                                     
                       Serial.print("counts");
                       Serial.print("= ");
                       Serial.println( counts);
                          tracking2();
                       //
                       
              
              }
              else 
              {
                turn_LEFT2();
              }
}
void turn_LEFT()// RIGHT turn on second turn.
{
  bool track=false;
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
  
   if((sensor5==HIGH)&&(sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH)&&(sensor1==HIGH))
  {
  
                  analogWrite(l_pwm,l_max_speedf-10);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                delay(500);
                stop_r();

                      }
else if ((sensor5==LOW)&&(sensor4==LOW)&&(sensor3==HIGH)&&(sensor2==LOW)&&(sensor1==LOW))
              {
                       
                       Serial.print("counts");
                       Serial.print("= ");
                       Serial.println( counts);
                          tracking2();
                          
                          
              
              }
                    
 

}
void turn_LEFT2()//  WHEN PLACING MOTOR 1 Rt on st
{
  bool track=false;
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
  
   if((sensor5==LOW)&&(sensor4==LOW)&&(sensor3==LOW)&&(sensor2==LOW)&&(sensor1==LOW))
  {
  
                  analogWrite(l_pwm,l_max_speedf-10);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                
                

                      }
else if ((sensor5==LOW)&&(sensor4==LOW)&&(sensor3==HIGH)&&(sensor2==LOW)&&(sensor1==LOW)||(sensor5==LOW)&&(sensor4==LOW)&&(sensor3==HIGH)&&(sensor2==HIGH)&&(sensor1==LOW)||(sensor5==LOW)&&(sensor4==LOW)&&(sensor3==HIGH)&&(sensor2==LOW)&&(sensor1==LOW))
              {
                stop_r();   
                ex1=false;
ex2=true;
ex3=true;
ex4=false;
ex5=true; 
      
ex7=false;
ex8=true; 
               }
                    
 

}
void turn_R_1()// RIGHT turn on second turn.
{
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
 
  
                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
      delay(1000);
         turn_R_R();                            
}
void turn_R_R()// RIGHT turn on second turn.
{
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
  if (sensor3==LOW){
  
                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);

                      }
else if (sensor3==HIGH)
              {
                        counts+=1;
                       Serial.print("counts");
                       Serial.print("= ");
                       Serial.println( counts);
                        ex1=true;
                              ex2=true;
                              ex3=true;
                              ex4=false; 
                          
              }

                    
 
}
void turn_R_1_rock1()// RIGHT turn on second turn.
{
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
 
  
                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
      delay(1000);
         turn_R_R_rock1();                            
}
void turn_R_R_rock1()// RIGHT turn on second turn.
{
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
  if (sensor3==LOW){
  
                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);

                      }
else if (sensor3==HIGH)
              {
                        counts+=1;
                       Serial.print("counts");
                       Serial.print("= ");
                       Serial.println( counts);
                        ex1=false;
    ex2=false;
    ex3=false;
    ex4=true; 
    ex5=false;
    ex7=false;
    ex8=true;   
              }

                    
 
}
void turn_R_off()// RIGHT turn on second turn.
{
                  analogWrite(l_pwm,l_max_speedf-10);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                  delay(1000);
                              ex1=true;
                              ex2=true;
                              ex3=false;
                              ex4=false; 
                          
}   
void turn_R_off2()// RIGHT turn on second turn.
{
                  analogWrite(l_pwm,l_max_speedf-10);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                  delay(1000);
ex1=true;
ex2=true;
ex3=true;
ex4=false;
ex5=true; 
}   
void turn_R_off3()// RIGHT turn on second turn.
{
                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                  delay(1000);
    ex1=false;
    ex2=true;
    ex3=true;
    ex4=true; 
    ex5=true;
    ex7=true;
     ex8=true;
}                    
void turn_L_M1()// when picking M1
{  
   int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
  if (sensor3==LOW){
//while (line_check3==false)

                analogWrite(l_pwm,l_max_speedf+3 );
                analogWrite(r_pwm,r_max_speedf+3);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);

                      }
else if (sensor3==HIGH)
              {

                stop_r();
                 ex1=false;
            ex2=true;
            ex3=false;
            ex4=true; 
            ex5=true;
            ex7=true;
            ex8=true; 
              }
              
}
void turn_Lb()// left turn on second turn.
{
  
   analogWrite(l_pwm,l_max_speedf );
analogWrite(r_pwm,r_max_speedf);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}

void r_perfect_turn()
{
  resume_speed();
    int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
  if (sensor3==LOW){
  
                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm,r_max_speedf);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,HIGH);
                      }
else if (sensor3==HIGH)
              {
                 ex1=false;
                 ex2=false;
                 ex3=true;
                 ex4=false;           
              }
}

/*void turn_right1()
{  
    analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm,r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                delay (1000);
                 
               

                
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
  ex1=true;
    ex2=false;
    ex3=false;
    ex4=true; 
    ex5=false;
    ex7=true;
    ex8=true;
}*/
/*void turn_right2()
{  
while (ex6==false)
{
    analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm,r_max_speedf);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                delay (1000);
                 
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,HIGH);

                delay(800);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                delay(800);
                 ex6=true;  
}
}*/
/*void turn_right3()
{  
while (ex6==true)
{
    analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm,r_max_speedf);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                delay (1000);
                 
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,HIGH);

                delay(800);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                delay(800);
                 ex6=false;  
}
}*/
void turn_R_M2a()// RIGHT turn on second turn.
{ 
 
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
  if(((sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH)&&(sensor1==HIGH))||((sensor5==HIGH)&&(sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH))||((sensor5==HIGH)&&(sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH)&&(sensor1==HIGH)))
{ stop_r();
  delay(500);
  forward();
  delay(300);
  turn_Rb();
  delay (600);
 
   ex1=false;
    ex2=false;
    ex3=false;
    ex4=false; 
    ex5=false;
    ex7=true;
}

    reverse();
   
   
}

void turn_Rb()// left turn on second turn.
{
analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm,r_max_speedf);
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
 
}
void turn_Rbc()// left turn on second turn.
{
analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm,r_max_speedf);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,HIGH);
 delay(500);
}
void turn_Rock1c()// left turn on second turn.
{
analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm,r_max_speedf);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,HIGH);
 delay(500);
}
void turn_R_M2b()// hea ding to pick m2
{
   int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
  if (sensor3==LOW)
  {
  
               analogWrite(l_pwm, l_max_speedf);
                analogWrite(r_pwm,r_max_speedf);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);

                      }
else if (sensor3==HIGH)
              {
                       
                       Serial.print("counts");
                       Serial.print("= ");
                       Serial.println( counts);
                      start_ra();
             //          pick_M2();
                     
                                 
              }
}
void turn_Lm2p()// left turn to find white line
{
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
  if (sensor3==LOW){
  
                 analogWrite(l_pwm, l_max_speedf-10);
                 analogWrite(r_pwm,r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);

                      }
else if (sensor3==HIGH)
              {
                       
                       Serial.print("counts");
                       Serial.print("= ");
                       Serial.println( counts);
                          tracking2();
                   delay(300);
                      ex1=false;
    ex2=true;
    ex3=false;
    ex4=true; 
    ex5=false;
    ex7=true;
                    
 
}
}
void turn_LEFTrock1()// RIGHT turn on second turn. awl
{
  //bool track=false;
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
  
   if(((sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH)&&(sensor1==HIGH))||((sensor5==HIGH)&&(sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH))||((sensor5==HIGH)&&(sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH)&&(sensor1==HIGH)))

  {
     resume_speed();
                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                delay(700);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                  delay(500);
              ex1=false;
    ex2=false;
    ex3=false;
    ex4=true; 
    ex5=false;
    ex7=true;
    ex8=true;
                      }
 
   else if (sensor3==LOW)
              {
                   reduce_speed();    
               //                                     
              }
   else
   {                                  
                       Serial.print("counts");
                       Serial.print("= ");
                       Serial.println( counts);
                       reduce_speed();
                          tracking2();
   }
}

void turn_LEFTrock1b()// SEE SECOND WHITE LINE when with rock 1
{
  //bool track=false;
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
  
   if(((sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH)&&(sensor1==HIGH))||((sensor5==HIGH)&&(sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH))||((sensor5==HIGH)&&(sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH)&&(sensor1==HIGH)))

  {
       stop_r();
       delay(300);
       resume_speed();
                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                delay(500);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                  delay(500);
               ex1=false;
    ex2=false;
    ex3=true;
    ex4=false; 
    ex5=false;
    ex7=false;
    ex8=true;
                      }
 else if (sensor3==LOW)
              {
                reduce_speed();       
               //                                     
              }
   else
   {        
                                     
                       Serial.print("counts");
                       Serial.print("= ");
                       Serial.println( counts);
                       reduce_speed();
                          tracking2();

}}
void turn_LEFTrock2c()// SEE SECOND WHITE LINE
{
  //bool track=false;
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
  
   if(((sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH)&&(sensor1==HIGH))||((sensor5==HIGH)&&(sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH))||((sensor5==HIGH)&&(sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH)&&(sensor1==HIGH)))

  {
  
                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                  delay(200);
                         analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                delay (500);     
               ex1=false;
    ex2=true;
    ex3=false;
    ex4=false; 
    ex5=false;
    ex7=true;
    ex8=true;
                      }
 else if (sensor3==LOW)
              {
                       
       //        //                                     
              }
   else
   {        
                                     
                       Serial.print("counts");
                       Serial.print("= ");
                       Serial.println( counts);
                          tracking2();

}}
void turn_rock2b()// moving foward to pick  block 1
{
 forward();
//pick_rock2();
  
}
void turn_LEFTrock1c()// SEE YELLOW LINE
{
  //bool track=false;
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
  
   if(((sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH)&&(sensor1==HIGH))||((sensor5==HIGH)&&(sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH))||((sensor5==HIGH)&&(sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH)&&(sensor1==HIGH)))

  {
  
                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                  delay(500);
               ex1=false;
    ex2=false;
    ex3=false;
    ex4=true; 
    ex5=true;
    ex7=true;
    ex8=true;
                      }
 else if (sensor3==LOW)
              {
                       
      //         //                                     
              }
   else
   {        
                                     
                       Serial.print("counts");
                       Serial.print("= ");
                       Serial.println( counts);
                          tracking2();

}}
void turn_LEFTrock2d()// heading to pick rock 2
{
  //bool track=false;
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
  

 if (sensor3==LOW)
              {
                       
               analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm,r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                                                   
              }
   else if (sensor3==HIGH)
   {        
                                     
                       Serial.print("counts");
                       Serial.print("= ");
                       Serial.println( counts);
                         
}}

void turn_L_M3a()
{
//reduce_speed();
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
  if (sensor3==LOW)
  {
   reduce_speed();
                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);

   }
else if ((sensor3==HIGH))
              {
                stop_r();
                delay(1000);
 ex1=true;
  ex2=false;
  ex3=false;
  ex4=false; 
  ex5=true;
  ex7=true;
  ex8=true;                       
 
}
}
void turn_L_M3b()
{
reduce_speed();
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
 if(((sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH)&&(sensor1==HIGH))||((sensor5==HIGH)&&(sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH))||((sensor5==HIGH)&&(sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH)&&(sensor1==HIGH)))

  {
         resume_speed();
         stop_r();
         delay(1000);
               // forward();
               // delay(300);
               
               
                stop_r();
                ex1=true;
                ex2=true;
                ex3=false;
                ex4=false; 
                ex5=false;
                ex7=true;
                ex8=true;
               
               
   }

else
{
   reduce_speed();
  // tracking1();
}
}

void turn_L_M3bb()
{
  resume_speed();
 analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                delay(1500);
ex1=true;
  ex2=false;
  ex3=false;
  ex4=true; 
  ex5=false;
  ex7=false;
  ex8=true;   

}
void turn_L_M3c()
{
reduce_speed();
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
 if(sensor3==HIGH)

  {
         stop_r();
                delay(300);
 ex1=true;
  ex2=false;
  ex3=true;
  ex4=true; 
  ex5=false;
  ex7=true;
  ex8=true;

   }
else if (sensor3==LOW)
              {
                       
             reduce_speed();
             analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
}
}
void turn_L_M3c_tillblack()
{
reduce_speed();
  
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
  if((sensor5==LOW)&&(sensor4==LOW)&&(sensor3==LOW)&&(sensor2==LOW)&&(sensor1==LOW))
  { 
  stop_r();
  delay(500);
  forward();
  delay(200);
   reduce_speed();
             analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
  delay (800);
 ex1=true;
                ex2=false;
                ex3=true;
                ex4=false; 
                ex5=true;
                ex7=true;
                ex8=true;
 
}
 else
 {
    tracking2();
   
 }  
}
void turn_L_M3d()
{
reduce_speed();
   tracking2();
//  pick_m4();
}
void turn_R_M3a()
{
int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
 if(((sensor4==LOW)&&(sensor3==HIGH)&&(sensor2==HIGH)&&(sensor1==HIGH))||((sensor5==LOW)&&(sensor4==LOW)&&(sensor3==HIGH)&&(sensor2==HIGH))||((sensor5==HIGH)&&(sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH)&&(sensor1==HIGH)))

  {
         resume_speed();
                forward();
                delay(200);
                analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                delay(700);
               
                stop_r();
               ex1=true;
                ex2=false;
                ex3=true;
                ex4=false; 
                ex5=true;
                ex7=false;
                ex8=true;
   }
   else 
   {
    reduce_speed();
    reverse();
   }
}
void turn_R_M3b()
{
   int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
 if(sensor3==HIGH)

  {
                
                stop_r();
                delay(300);
             ex1=true;
                ex2=false;
                ex3=true;
                ex4=false; 
                ex5=true;
                ex7=true;
                ex8=true;
              

   }
else if (sensor3==LOW)
              {
                       
             reduce_speed();
              analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm, r_max_speedf);
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}
}

void turn_L_M3e() //after seeing white line
{
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
 if(((sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==LOW)&&(sensor1==LOW))||((sensor5==HIGH)&&(sensor4==HIGH)&&(sensor3==LOW)&&(sensor2==LOW))||((sensor5==HIGH)&&(sensor4==HIGH)))

  {
         resume_speed();
                forward();
                delay(200);
                analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                delay(500);
               
                stop_r();
                ex1=true;
                ex2=false;
                ex3=true;
                ex4=true; 
                ex5=false;
                ex7=false;
                ex8=true;
   }
   else 
   {
    reduce_speed();
    tracking2();
   }
}
void turn_L_M3f() 
{
  int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
   if(sensor3==HIGH)

  {
                
                stop_r();
                delay(300);
              ex1=true;
                ex2=true;
                ex3=false;
                ex4=false; 
                ex5=false;
                ex7=false;
                ex8=true;              

   }
else if (sensor3==LOW)
              {
                       
             reduce_speed();
              analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm, r_max_speedf);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}
 
}
void turn_R_M3d() //after seeing white line
{
 int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
 if(sensor3==HIGH)

  {
                
                stop_r();
                delay(300);
               ex1=true;
                ex2=false;
                ex3=true;
                ex4=false; 
                ex5=true;
                ex7=true;
                ex8=true; 
              

   }
else if (sensor3==LOW)
              {
                       
             reduce_speed();
              analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm, r_max_speedf);
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}
}
void turn_L_M3c_fac_m4()
{
   int sensor1=digitalRead(37);//sensor1
  int sensor2=digitalRead(39);//sensor2
  int sensor3=digitalRead(41);//sensor3
//
  int sensor5=digitalRead(45);//sensor5
 if(sensor3==HIGH)

  {
                
                stop_r();
                delay(300);
              ex1=false;
                ex2=true;
                ex3=false;
                ex4=true; 
                ex5=true;
                ex7=false;
                ex8=true;
              

   }
else if (sensor3==LOW)
              {
                       
             reduce_speed();
              analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm, r_max_speedf);
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}
}

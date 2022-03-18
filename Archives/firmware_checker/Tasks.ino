void reduce_speed()
{
   l_max_speedf = 35; 
r_max_speedf =35;
}
void reduce_speed2()
{
   l_max_speedf = 35; 
r_max_speedf =35;
}
void resume_speed()
{
   l_max_speedf =45; 
r_max_speedf =44;
}
void start_ra()
{
  Serial.print("counts");
                          Serial.print("= ");
                        Serial.println( counts);
       //
      int sensor1=digitalRead(37);//sensor1
int sensor2=digitalRead(39);//sensor2
int sensor3=digitalRead(41);//sensor3
int sensor4=digitalRead(43);//sensor4
int sensor5=digitalRead(45);//sensor5
 // tracking2();
          if( (sensor5==LOW)&&(sensor4==LOW)&&(sensor3==LOW)&&(sensor2==LOW)&&(sensor1==LOW))
             {    
              dis=false; 
              //line_check=false;
        while(white_J2==false)
               {
                stop_r();
                delay(1000);
                white_J2=true;
               }
            
               reduce_speed();
                  //
                 }
                 
             else
          {
            
         //
           
          }


}
void start_rb()
{

        
  Serial.print("counts");
                          Serial.print("= ");
                        Serial.println( counts);
       //servo_park();
      int sensor1=digitalRead(37);//sensor1
int sensor2=digitalRead(39);//sensor2
int sensor3=digitalRead(41);//sensor3
int sensor4=digitalRead(43);//sensor4
int sensor5=digitalRead(45);//sensor5
  tracking2();
          

}
void start_rock1()
{
  Serial.print("counts");
                          Serial.print("= ");
                        Serial.println( counts);
    //  arm_park();
      int sensor1=digitalRead(37);//sensor1
int sensor2=digitalRead(39);//sensor2
int sensor3=digitalRead(41);//sensor3
int sensor4=digitalRead(43);//sensor4
int sensor5=digitalRead(45);//sensor5
  
          if( (sensor5==LOW)&&(sensor4==LOW)&&(sensor3==LOW)&&(sensor2==LOW)&&(sensor1==LOW))
             {                    // arm_park(); 

           
              //
             }
             else
          {
            tracking2();
          }


}
void start_M2()
{
    

  Serial.print("counts");
                          Serial.print("= ");
                        Serial.println( counts);
      //arm_park();
      int sensor1=digitalRead(37);//sensor1
int sensor2=digitalRead(39);//sensor2
int sensor3=digitalRead(41);//sensor3
int sensor4=digitalRead(43);//sensor4
int sensor5=digitalRead(45);//sensor5
 // tracking2();
          if((sensor3==HIGH))
             {                    // arm_park(); 

           resume_speed();
           ex1=true;
              ex2=true;
              ex3=true;
              ex4=true;
              ex5=true;
               ex7=true;
              ex8=false;
            
             }
         
          /*   else if (sensor3==HIGH)
          {
            while(white_M2==false)
            { 
           analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);  
                delay(800);
                reduce_speed();
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,HIGH);
                digitalWrite(rmotorb,HIGH);
                delay(500);  
                white_M2=true; 
           }*/
else if (sensor3==LOW)
{           
  reduce_speed();
          analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);  
          }
}
void start_rock2()
{

                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                delay(1500);
                analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,HIGH);
                digitalWrite(rmotorb,LOW);
                  delay(1500);
                 ex1=false;
              ex2=false;
              ex3=true;
              ex4=true;
              ex5=true;
              ex7=true;
              ex8=true;
               
}
void start_rock2_back()
{

                  analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,HIGH);
                delay(1700);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                  delay(1700);
              ex1=false;
              ex2=true;
              ex3=false;
              ex4=false;
              ex5=false;
              ex7=true;
              ex8=true;
               
}


  
void pick_ai()
{
 

          int a=  distance1();

          if( (a<=35)&&(a>=26))
          {
            while (dis==false)
            {
          stop_r();     
         delay(00);
         reduce_speed2();
           ex1=false;
          ex2=true;
          ex3=true;
          ex4=true; 
          ex5=true;
          ex7=true;
          ex8=true;
         dis=true;
            }
          }
       
        

 }
           
 
void pick_aii()
{
int a=  distance1();
if(a<=18)
{
  stop_r();
delay(1000);
 pick_b(); 
                                 

} 
}
void pick_b()
{  int sensor1=digitalRead(37);//sensor1
int sensor2=digitalRead(39);//sensor2
int sensor3=digitalRead(41);//sensor3
int sensor4=digitalRead(43);//sensor4
int sensor5=digitalRead(45);//sensor5

  //delay(1000); 
   //arm_park();
    delay(1000);   
 
    delay(500);
   //arm_grip_v_1();
    delay(2000); 
  //
 delay(1000);
  ex1=true;
  ex2=false;
  ex3=false;
  ex4=false; 
ex5=false;
ex7=false;
ex8=false;
}
void obstacle_m2()
{
  int obs=distance1();
  if (obs<=30)
  {
    stop_r();
    ex1=true;
    ex2=true;
    ex3=true;
    ex4=true; 
    ex5=true;
    ex7=true;
    ex8=false;
    
  }
}

void start_M2Pc()
{
 

  Serial.print("counts");
                          Serial.print("= ");
                        Serial.println( counts);
       //servo_park();
      int sensor1=digitalRead(37);//sensor1
int sensor2=digitalRead(39);//sensor2
int sensor3=digitalRead(41);//sensor3
int sensor4=digitalRead(43);//sensor4
int sensor5=digitalRead(45);//sensor5
 
          if((sensor3==LOW))
             {                    // arm_park();         
                analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
             }
          else if(sensor3==HIGH)
             {                    // arm_park(); 
              stop_r();
              ex1=true;
              ex2=false;
              ex3=false;
              ex4=false; 
              ex5=true;
              ex7=true; 
               ex8=false;          
             }
         
}
void reverse2 ()
{
  analogWrite(l_pwm, l_max_speedf-10);
analogWrite(r_pwm, r_max_speedf-10);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,HIGH);
digitalWrite(rmotorb,HIGH);
}
void start_rock1a()
{
    
bool wl=false;
  Serial.print("counts");
                          Serial.print("= ");
                        Serial.println( counts);
      //arm_park();
      int sensor1=digitalRead(37);//sensor1
int sensor2=digitalRead(39);//sensor2
int sensor3=digitalRead(41);//sensor3
int sensor4=digitalRead(43);//sensor4
int sensor5=digitalRead(45);//sensor5
 
      if(((sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH)&&(sensor1==HIGH))||((sensor5==HIGH)&&(sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH))||((sensor5==HIGH)&&(sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==HIGH)&&(sensor1==HIGH)))
         {                    // arm_park(); 
  stop_r();       
  ex1=false;
  ex2=true;
  ex3=false;
  ex4=true; 
  ex5=false;
  ex7=false; 
  ex8=true;  
              
             }
         
             else
          {
            reduce_speed2();
           reverse();
          }          
 }
 void start_M4()
{
    

  Serial.print("counts");
                          Serial.print("= ");
                        Serial.println( counts);
      //arm_park();
      int sensor1=digitalRead(37);//sensor1
int sensor2=digitalRead(39);//sensor2
int sensor3=digitalRead(41);//sensor3
int sensor4=digitalRead(43);//sensor4
int sensor5=digitalRead(45);//sensor5
  //tracking2();
             // arm_park(); 

                  reduce_speed();
              reverse();
              delay(800);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                delay(1000);
                resume_speed();
               analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,HIGH);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                delay(800);
                              ex1=true;
              ex2=false;
              ex3=false;
              ex4=false; 
              ex5=true;
              ex7=false; 
              ex8=true;  
               //turn_L(); 
           
         
            
              reduce_speed();
              reverse();
           
}
 void start_M4b()
{
    

  Serial.print("counts");
                          Serial.print("= ");
                        Serial.println( counts);
     
      int sensor1=digitalRead(37);//sensor1
int sensor2=digitalRead(39);//sensor2
int sensor3=digitalRead(41);//sensor3
int sensor4=digitalRead(43);//sensor4
int sensor5=digitalRead(45);//sensor5
  tracking2();
          if(( (sensor5==LOW)&&(sensor4==LOW)&&(sensor3==LOW)&&(sensor2==LOW)&&(sensor1==LOW))||( (sensor5==LOW)&&(sensor4==LOW)&&(sensor3==LOW)&&(sensor2==LOW)&&(sensor1==HIGH)))
             {                    // arm_park(); 
reduce_speed();
              analogWrite(l_pwm,l_max_speedf);
                analogWrite(r_pwm, r_max_speedf);
                digitalWrite(lmotorf,LOW);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,HIGH);
                digitalWrite(rmotorb,HIGH);
                delay(500);
                digitalWrite(lmotorf,HIGH);
                digitalWrite(rmotorf,LOW);
                digitalWrite(lmotorb,LOW);
                digitalWrite(rmotorb,LOW);
                delay(500);
                              ex1=true;
              ex2=false;
              ex3=false;
              ex4=false; 
              ex5=true;
              ex7=false; 
              ex8=true;  
               //turn_L(); 
             }
         
             else {
              reduce_speed();
          //    tracking3();
             }
}

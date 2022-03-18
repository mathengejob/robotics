
void tracking2() 
{
  //digitalWrite(26,HIGH);
 analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm, r_max_speedf);
int sensor1=digitalRead(34);//sensor1
int sensor2=digitalRead(36);//sensor2
int sensor3=digitalRead(38);//sensor3
int sensor4=digitalRead(40);//sensor4
int sensor5=digitalRead(42);//sensor5
int pre_l_value;
int pre_r_value;
int cur_l_value=sensor1;
int cur_r_value=sensor5;
if((sensor1==0)&&(sensor2==0)&&(sensor3==1)&&(sensor4==0)&&(sensor5==0))//white line at the centre . >>forward
{ 
 analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm, r_max_speedf);
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}
//>>>>>>>>>>>>>>>right
else if((sensor1==0)&&(sensor2==1)&&(sensor3==1)&&(sensor4==0)&&(sensor5==0))// slight to right>> move foward)
{ 
 analogWrite(l_pwm, l_max_speedf-20);
analogWrite(r_pwm, r_max_speedf+0);
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}

else if((sensor1==0)&&(sensor2==1)&&(sensor3==0)&&(sensor4==0)&&(sensor5==0))// far to the right>> turn left
{ 
 analogWrite(l_pwm, l_max_speedf-20);//30
analogWrite(r_pwm, r_max_speedf);//30
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}
else if((sensor1==1)&&(sensor2==1)&&(sensor3==1)&&(sensor4==0)&&(sensor5==0))// far to the right>> turn left
{ 
 analogWrite(l_pwm, l_max_speedf-20);//30
analogWrite(r_pwm, r_max_speedf);//30
digitalWrite(lmotorf,HIGH);///  WAS at lows
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}
else if((sensor1==1)&&(sensor2==1)&&(sensor3==0)&&(sensor4==0)&&(sensor5==0))// far to the right>> turn left
{ 
 analogWrite(l_pwm, l_max_speedf-20);//30
analogWrite(r_pwm, r_max_speedf);//30
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}
else if((sensor1==1)&&(sensor2==0)&&(sensor3==0)&&(sensor4==0)&&(sensor5==0))// far to the right>> turn left
{ 
 analogWrite(l_pwm, l_max_speedf-20);//30
analogWrite(r_pwm, r_max_speedf+20);//30
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
pre_l_value=cur_l_value;
pre_r_value=cur_r_value;
}
//>>>>>>>>>>>>>>>>>>> Left
else if((sensor1==0)&&(sensor2==0)&&(sensor3==1)&&(sensor4==1)&&(sensor5==0))// slight to the left >>move forward
{ 
 analogWrite(l_pwm, l_max_speedf+0);
analogWrite(r_pwm, r_max_speedf-20);
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}
else if((sensor1==0)&&(sensor2==0)&&(sensor3==0)&&(sensor4==1)&&(sensor5==0))//far to the left >> right turn
{ 
 analogWrite(l_pwm, l_max_speedf+0);//30//50
analogWrite(r_pwm, r_max_speedf-20);//30//50
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}
else if((sensor1==0)&&(sensor2==0)&&(sensor3==1)&&(sensor4==1)&&(sensor5==1))//far to the left >> right turn
{ 
 analogWrite(l_pwm, l_max_speedf);//30//50
analogWrite(r_pwm, r_max_speedf-20);//30//50
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}
else if((sensor1==0)&&(sensor2==0)&&(sensor3==0)&&(sensor4==1)&&(sensor5==1))//far to the left >> right turn
{ 
 analogWrite(l_pwm, l_max_speedf+20);//30//50
analogWrite(r_pwm, r_max_speedf-20);//30//50
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}
else if((sensor1==0)&&(sensor2==0)&&(sensor3==0)&&(sensor4==0)&&(sensor5==1))//far to the left >> right turn
{ 
 analogWrite(l_pwm, l_max_speedf+20);//30//50
analogWrite(r_pwm, r_max_speedf-20);//30//50
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
pre_l_value=cur_l_value;
pre_r_value=cur_r_value;
}


else if((sensor1==1)&&(sensor2==1)&&(sensor3==1)&&(sensor4==1)&&(sensor5==1))// white line >>move forward&&(sensor3==0)&&(sensor4==0)&&(sensor5==0)
{ 
 analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm, r_max_speedf);
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}
else if((sensor1==0)&&(sensor2==0)&&(sensor3==0)&&(sensor4==0)&&(sensor5==0))// white line >>move forward&&(sensor3==0)&&(sensor4==0)&&(sensor5==0)
{ 
 analogWrite(l_pwm, l_max_speedf-30);
analogWrite(r_pwm, r_max_speedf-30);

digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);

}
//delay(

}
void tracking_reverse() 
{
  digitalWrite(26,HIGH);
 analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm, r_max_speedf);
int sensor1=digitalRead(34);//sensor1
int sensor2=digitalRead(36);//sensor2
int sensor3=digitalRead(38);//sensor3
int sensor4=digitalRead(40);//sensor4
int sensor5=digitalRead(42);//sensor5
int pre_l_value;
int pre_r_value;
int cur_l_value=sensor1;
int cur_r_value=sensor5;
if((sensor1==1)&&(sensor2==1)&&(sensor3==0)&&(sensor4==1)&&(sensor5==1))//white line at the centre . >>forward
{ 
 analogWrite(l_pwm, l_max_speedf+30);
analogWrite(r_pwm, r_max_speedf+30);
digitalWrite(lmotorb,HIGH);
digitalWrite(rmotorb,HIGH);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,LOW);
}

else if((sensor1==1)&&(sensor2==0)&&(sensor3==0)&&(sensor4==1)&&(sensor5==1))// slight to right>> move foward)
{ 
 analogWrite(l_pwm, l_max_speedf+30);
analogWrite(r_pwm, r_max_speedf+30);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,HIGH);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,LOW);
}
else if((sensor1==1)&&(sensor2==1)&&(sensor3==0)&&(sensor4==0)&&(sensor5==1))// slight to the left >>move forward
{ 
 analogWrite(l_pwm, l_max_speedf+30);
analogWrite(r_pwm, r_max_speedf+30);
digitalWrite(lmotorb,HIGH);
digitalWrite(rmotorb,LOW);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,LOW);
}
else if((sensor1==1)&&(sensor2==0)&&(sensor3==1)&&(sensor4==1)&&(sensor5==1))// far to the right>> turn left
{ 
 analogWrite(l_pwm, l_max_speedf+30);//30
analogWrite(r_pwm, r_max_speedf+30);//30
digitalWrite(rmotorb,LOW);
digitalWrite(lmotorb,HIGH);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,LOW);
}
else if((sensor1==0)&&(sensor2==0)&&(sensor3==1)&&(sensor4==1)&&(sensor5==1))// far to the right>> turn left
{ 
 analogWrite(l_pwm, l_max_speedf+30);//30
analogWrite(r_pwm, r_max_speedf+30);//30
digitalWrite(rmotorb,LOW);
digitalWrite(lmotorb,HIGH);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,LOW);
}
else if((sensor1==0)&&(sensor2==0)&&(sensor3==0)&&(sensor4==1)&&(sensor5==1))// far to the right>> turn left
{ 
 analogWrite(l_pwm, l_max_speedf+30);//30
analogWrite(r_pwm, r_max_speedf+30);//30
digitalWrite(rmotorb,LOW);
digitalWrite(lmotorb,HIGH);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,LOW);
}
else if((sensor1==0)&&(sensor2==1)&&(sensor3==1)&&(sensor4==1)&&(sensor5==1))// far to the right>> turn left
{ 
 analogWrite(l_pwm, l_max_speedf+30);//30
analogWrite(r_pwm, r_max_speedf+30);//30
digitalWrite(rmotorb,LOW);
digitalWrite(lmotorb,HIGH);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,LOW);
pre_l_value=cur_l_value;
pre_r_value=cur_r_value;
}
else if((sensor1==1)&&(sensor2==1)&&(sensor3==1)&&(sensor4==0)&&(sensor5==1))//far to the left >> right turn
{ 
 analogWrite(l_pwm, l_max_speedf+30);//30//50
analogWrite(r_pwm, r_max_speedf+30);//30//50
digitalWrite(rmotorb,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,LOW);
}
else if((sensor1==1)&&(sensor2==1)&&(sensor3==1)&&(sensor4==0)&&(sensor5==0))//far to the left >> right turn
{ 
 analogWrite(l_pwm, l_max_speedf+30);//30//50
analogWrite(r_pwm, r_max_speedf+30);//30//50
digitalWrite(rmotorb,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,LOW);
}
else if((sensor1==1)&&(sensor2==1)&&(sensor3==0)&&(sensor4==0)&&(sensor5==0))//far to the left >> right turn
{ 
 analogWrite(l_pwm, l_max_speedf+30);//30//50
analogWrite(r_pwm, r_max_speedf+30);//30//50
digitalWrite(rmotorb,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,LOW);
}
else if((sensor1==1)&&(sensor2==1)&&(sensor3==1)&&(sensor4==1)&&(sensor5==0))//far to the left >> right turn
{ 
 analogWrite(l_pwm, l_max_speedf+30);//30//50
analogWrite(r_pwm, r_max_speedf+30);//30//50
digitalWrite(rmotorb,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,LOW);
pre_l_value=cur_l_value;
pre_r_value=cur_r_value;
}


else if((sensor1==0)&&(sensor2==0)&&(sensor3==0)&&(sensor4==0)&&(sensor5==0))// white line >>move forward&&(sensor3==0)&&(sensor4==0)&&(sensor5==0)
{ 
 analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm, r_max_speedf);
digitalWrite(lmotorb,HIGH);
digitalWrite(rmotorb,HIGH);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,LOW);
}
}

/*
else if((sensor5==HIGH)&&(sensor4==HIGH)&&(sensor3==HIGH)&&(sensor2==LOW)&&(sensor1==LOW))//RIGHT JERK
{ 
analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm, r_max_speedf);
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}

else if((sensor5==LOW)&&(sensor4==LOW)&&(sensor3==HIGH)&&(sensor2==HIGH)&&(sensor1==HIGH))//LEFT JERK
{
  analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm, r_max_speedf);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}
else if((sensor5==LOW)&&(sensor4==LOW)&&(sensor3==LOW)&&(sensor2==HIGH)&&(sensor1==HIGH))//TO LEFT JERK

{ 
  analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm, r_max_speedf);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}
else if((sensor5==HIGH)&&(sensor4==HIGH)&&(sensor3==LOW)&&(sensor2==LOW)&&(sensor1==LOW))//TO RIGHT JERK

{ 
 analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm, r_max_speedf);
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}

else if((sensor5==LOW)&&(sensor4==LOW)&&(sensor3==LOW)&&(sensor2==LOW)&&(sensor1==HIGH))// TO LEFT JERK

{ 
  analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm, r_max_speedf);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}
else if((sensor5==HIGH)&&(sensor4==LOW)&&(sensor3==LOW)&&(sensor2==LOW)&&(sensor1==LOW))//TO RIGHT JERK

{ 
   analogWrite(l_pwm, l_max_speedf);
analogWrite(r_pwm, r_max_speedf);
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}

}

/*else if( (sensor5==LOW)&&(sensor4==LOW)&&(sensor3==LOW)&&(sensor2==LOW)&&(sensor1==LOW))
          {
                stop_r();
                delay (5000);
                //forward ();
                  //
 

          }}*/

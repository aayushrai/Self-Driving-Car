
int state=0;
int sp = 50;

#define left_motor_forward 10
#define left_motor_backward 9
#define right_motor_forward 6
#define right_motor_backward 5

void setup() {

  // put your setup code here, to run once:

  Serial.begin(9600);
}

void calc_turn() 
{  
                                              //Restricting the error value between +256. 
if (error_value< -256)     
  { 
error_value = -256; 
  }  
if (error_value> 256) 
  { 
error_value = 256; 
  }  
                                              // If error_value is less than zero calculate right turn speed values 
if (error_value< 0) 
  { 
right_speed = max_speed + error_value; 
left_speed = max_speed; 
  } 
  else 
  { 
right_speed = max_speed; 
left_speed = max_speed - error_value; 
  } 
}

void motor_drive (int right_speed,int left_speed)
{
  if (right_speed>255)
      right_speed=255;
  if (right_speed<0)
      right_speed=0;
  if (left_speed>255)
      left_speed=255;
  if (left_speed<0)
      left_speed=0;
   
  analogWrite(left_motor_forward,left_speed);
  analogWrite(right_motor_forward,right_speed);
  analogWrite(left_motor_backward,0);
  analogWrite(right_motor_backward,0);
  delay(100);
}


void loop() {

  // put your main code here, to run repeatedly:
  if (Serial.available()>0){
  error_value = Serial.read();
  if(error_value > 50 or error_value < 50)
  calc_turn();
  motor_drive(right_speed,left_speed);
}
}

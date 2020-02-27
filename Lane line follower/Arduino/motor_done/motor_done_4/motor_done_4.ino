
int state=0;
int sp = 50;
int error_value=0;
int right_speed=0;
int left_speed=0;
#define left_motor_forward 9
#define left_motor_backward 10
#define right_motor_forward 5
#define right_motor_backward 6
#define max_speed 200
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
 
right_speed = max_speed; 
left_speed = max_speed + error_value; 
  } 
  else 
  { 
right_speed = max_speed - error_value; 
left_speed = max_speed;
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
  state = Serial.read();
  error_value = state;
  calc_turn();
  motor_drive(right_speed,left_speed);
}
}

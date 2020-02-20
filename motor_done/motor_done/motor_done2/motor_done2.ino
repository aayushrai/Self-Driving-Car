int led=13;
int state=0;
int r1=5;
int r2=6;
int l1=9;
int l2=10;
int sp = 100;
void setup() {

  // put your setup code here, to run once:

  pinMode(led,OUTPUT);
  Serial.begin(9600);


}



void loop() {

  // put your main code here, to run repeatedly:
  if (Serial.available()>0){
  state = Serial.read();
  }
  else if( state == 'f')
  forward();

  else if ( state == 's')
  stopp();
  
  else if( state == 'r')
  right();
  
  else if( state == 'l')
  left();
  
  else if( state == 'b')
  backward();
 

}

void forward(){
analogWrite(r1,sp);
analogWrite(r2,0);
analogWrite(l1,sp);
analogWrite(l2,0);
}

void backward(){
analogWrite(r1,0);
analogWrite(r2,sp);
analogWrite(l1,0);
analogWrite(l2,sp);
}

void right(){
analogWrite(r1,0);
analogWrite(r2,0);
analogWrite(l1,sp);
analogWrite(l2,0);
}

void left(){
analogWrite(r1,sp);
analogWrite(r2,0);
analogWrite(l1,0);
analogWrite(l2,0);
}

void stopp(){
analogWrite(r1,0);
analogWrite(r2,0);
analogWrite(l1,0);
analogWrite(l2,0);
}

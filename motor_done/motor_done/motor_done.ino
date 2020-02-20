int led=13;
int state=0;
int r1=6;
int r2=5;
int l1=10;
int l2=9;
int sp = 50;
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
digitalWrite(r1,HIGH);
digitalWrite(r2,LOW);
digitalWrite(l1,HIGH);
digitalWrite(l2,LOW);
}

void backward(){
digitalWrite(r1,LOW);
digitalWrite(r2,HIGH);
digitalWrite(l1,LOW);
digitalWrite(l2,HIGH);
}

void right(){
digitalWrite(r1,LOW);
digitalWrite(r2,LOW);
digitalWrite(l1,HIGH);
digitalWrite(l2,LOW);
}

void left(){
digitalWrite(r1,HIGH);
digitalWrite(r2,LOW);
digitalWrite(l1,LOW);
digitalWrite(l2,LOW);
}

void stopp(){
digitalWrite(r1,LOW);
digitalWrite(r2,LOW);
digitalWrite(l1,LOW);
digitalWrite(l2,LOW);
}

//MOTOR Right
const int IN_3=12;
const int IN_4=13;
const int EN_right=11; //speed control
const int offset_right = 0;

//MOTOR Left
const int IN_1=8;
const int IN_2=9;
const int EN_left=10; //speed control
const int offset_left = 0;

//Variable
char command;
const int speed_ =110;

void setup() {
 Serial.begin(9600);
 
}

void loop() {
if(Serial.available()>0) { 
  break_();
  command = Serial.read();
  switch(command)
  {
   case 'F':
    forward();
    break;
   case 'L':
    left();
    break;
   case 'R':
    right();
    break;
   case 'B':
    break_();
    break;

  }
 }

}


void forward()
{
  digitalWrite(IN_1,HIGH);
  digitalWrite(IN_2,LOW);
  analogWrite(EN_left,speed_+offset_left);
  
  digitalWrite(IN_3,HIGH);
  digitalWrite(IN_4,LOW);
  analogWrite(EN_right,speed_+offset_right);
  
}
void left()
{
  digitalWrite(IN_1,LOW);
  digitalWrite(IN_2,HIGH);
  analogWrite(EN_left,speed_+offset_left);
  
  digitalWrite(IN_3,HIGH);
  digitalWrite(IN_4,LOW);
  analogWrite(EN_right,speed_+offset_right);
}
void right()
{
  digitalWrite(IN_1,HIGH);
  digitalWrite(IN_2,LOW);
  analogWrite(EN_left,speed_+offset_left);
  
  digitalWrite(IN_3,LOW);
  digitalWrite(IN_4,HIGH);
  analogWrite(EN_right,speed_+offset_right);
}
void break_()
{
//  digitalWrite(IN_1,LOW);
//  digitalWrite(IN_2,HIGH);
//  analogWrite(EN_left,speed_);
//  
//  digitalWrite(IN_3,LOW);
//  digitalWrite(IN_4,HIGH);
//  analogWrite(EN_right,speed_);
//  delay(10);

  digitalWrite(IN_1,HIGH);
  digitalWrite(IN_2,LOW);
  analogWrite(EN_left,0);
  
  digitalWrite(IN_3,HIGH);
  digitalWrite(IN_4,LOW);
  analogWrite(EN_right,0);
  
}
void reverse()
{
  digitalWrite(IN_1,LOW);
  digitalWrite(IN_2,HIGH);
  analogWrite(EN_left,speed_+offset_left);
  
  digitalWrite(IN_3,LOW);
  digitalWrite(IN_4,HIGH);
  analogWrite(EN_right,speed_+offset_right);
  
}

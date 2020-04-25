char t;

#define lm1 3
#define lm2 4
#define rm1 5
#define rm2 6
 
void setup() {
pinMode(lm1,OUTPUT);   
pinMode(lm2,OUTPUT);   
pinMode(rm1,OUTPUT);   
pinMode(rm2,OUTPUT);   
 
Serial.begin(9600);
 
}

void forward()
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
}

void right()
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
}

void left()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
}

void Stop()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
}

void reverse()
{
    digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
}
 
void loop() 
{
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == '1')  //move forward(all motors rotate in forward direction)
{
  forward();         
}
 
else if(t == '2')      //move reverse (all motors rotate in reverse direction)
{
  reverse();
  
}
 
else if(t == '3')      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
 {
  right();
}
 
else if(t == '4')      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
 {
  left();
}
 
else if(t == '5')     //STOP (all motors stop)
{ 
  Stop();
}
delay(100);
}

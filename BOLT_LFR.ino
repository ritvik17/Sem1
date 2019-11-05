int R_speed = 11; // speed of right motor 
int L_speed = 10; // speed of left motor 
int motor_r1 = 2; // motor right = +
int motor_r2 = 3; // motor right = -
int motor_l1 = 4; // motor left = -
int motor_l2 = 5; // motor left = +

int R_S = A0;// right infrared sensor
int L_S = A2;// left infrared sensor


int C_S = A1;// centre infrared sensor

void setup(){
  pinMode(R_speed,OUTPUT);
  pinMode(L_speed,OUTPUT);
  pinMode(motor_r1,OUTPUT);
  pinMode(motor_r2,OUTPUT);
  pinMode(motor_l1,OUTPUT);
  pinMode(motor_l2,OUTPUT);
  
  pinMode(R_S,INPUT);

  pinMode(L_S,INPUT);
  pinMode(C_S,INPUT);
  analogWrite(R_speed,150);

                                 
  analogWrite(L_speed,150);
  delay(200);
  }

void loop(){
 if ((digitalRead(L_S) == 1)&&(digitalRead(C_S) == 0)&&(digitalRead(R_S) == 1)){forward();}//move forward
 //if ((digitalRead(L_S) == 0)&&(digitalRead(C_S) == 0)&&(digitalRead(R_S) == 0)){forward();}//move forward  
 
 
 
 if ((digitalRead(L_S) == 0)&&(digitalRead(C_S) == 0)&&(digitalRead(R_S) == 1)){turnLeft();}//move left 
 if ((digitalRead(L_S) == 0)&&(digitalRead(C_S) == 1)&&(digitalRead(R_S) == 1)){turnLeft();}//move left

 
 if ((digitalRead(L_S) == 1)&&(digitalRead(C_S) == 1)&&(digitalRead(R_S) == 0)){turnRight();}//move right
 if ((digitalRead(L_S) == 1)&&(digitalRead(C_S) == 0)&&(digitalRead(R_S) == 0)){turnRight();}//move right
 
  if ((digitalRead(L_S) == 1)&&(digitalRead(C_S) ==1)&&(digitalRead(R_S) == 1)){stop();}
 
}
void forward()
{
  digitalWrite(motor_r1,LOW);
  digitalWrite(motor_r2,HIGH);
  digitalWrite(motor_l1,HIGH);
  digitalWrite(motor_l2,LOW); 
}

void turnRight()
{
  digitalWrite(motor_r1,LOW);
  digitalWrite(motor_r2,LOW);
  digitalWrite(motor_l1,HIGH);
  digitalWrite(motor_l2,LOW);
}
void turnLeft()
{
  digitalWrite(motor_r1,LOW);
  digitalWrite(motor_r2,HIGH);
  digitalWrite(motor_l1,LOW);
  digitalWrite(motor_l2,LOW);
  
}
void stop()
{
  digitalWrite(motor_r1,LOW);
  digitalWrite(motor_r2,LOW);
  digitalWrite(motor_l1,LOW);
  digitalWrite(motor_l2,LOW);
}

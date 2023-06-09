
void motorStop()
{
  digitalWrite(rmf, LOW);
  digitalWrite(rmb, LOW);
  digitalWrite(lmf, LOW);
  digitalWrite(lmb, LOW);
  delay(200);
}

//--------------------------------------------- 
void motorForward()
{
  digitalWrite(rmf, HIGH);
  digitalWrite(rmb, LOW);
  digitalWrite(lmf, HIGH);
  digitalWrite(lmb, LOW);
  delay(20);
}

//---------------------------------------------
void motorBackward()
{
  digitalWrite(rmf, LOW);
  digitalWrite(rmb, HIGH);
  digitalWrite(lmf, LOW);
  digitalWrite(lmb, HIGH);
  delay(20);
}

//---------------------------------------------
void motorFwTime (unsigned int time)
{
  motorForward();
  delay (time);
  motorStop();
}

//---------------------------------------------
void motorBwTime (unsigned int time)
{
  motorBackward();
  delay (time);
  motorStop();
}

//------------------------------------------------
/*void motorTurn(int direction, int degrees)
{
  leftServo.writeMicroseconds(1500 - iniMotorPower*direction);
  rightServo.writeMicroseconds(1500 - iniMotorPower*direction);
  delay (round(adjTurn*degrees+1));
  motorStop();
}*/

void motorTurnRight() 
{
    digitalWrite(rmf, HIGH);
  digitalWrite(rmb, LOW);
  digitalWrite(lmf, LOW);
  digitalWrite(lmb, LOW);
  delay(20);
  }
void motorTurnLeft()
{
    digitalWrite(rmf, LOW);
  digitalWrite(rmb, LOW);
  digitalWrite(lmf, HIGH);
  digitalWrite(lmb, LOW);
  delay(20);
  
  }

//---------------------------------------------------
void motorPIDcontrol()
{
  
  int leftMotorSpeed = 1500 - iniMotorPower - PIDvalue;
  int rightMotorSpeed = 1500 + iniMotorPower*adj - PIDvalue;
  
  // The motor speed should not exceed the max PWM value
   constrain(leftMotorSpeed, 1000, 2000);
   constrain(rightMotorSpeed, 1000, 2000);
  
  leftServo.writeMicroseconds(leftMotorSpeed);
  rightServo.writeMicroseconds(rightMotorSpeed);
  
  //Serial.print (PIDvalue);
  //Serial.print (" ==> Left, Right:  ");
  //Serial.print (leftMotorSpeed);
  //Serial.print ("   ");
  //Serial.println (rightMotorSpeed);
}

//-----------------------------
void drivePolygon(unsigned int time, int sides) // for motor test only
{
    for (int i = 0; i<sides; i++)
    {
        motorFwTime (time);
        motorTurn(RIGHT, 360/sides);
    }

}

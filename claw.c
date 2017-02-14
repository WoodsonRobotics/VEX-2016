// Claw Speed
#define ClSpd 50




#define ScrUpLmt 4000
#define ScrLowLmt -175

void srsetup()
{
	slaveMotor(ScissorSlave,Scissor);
<<<<<<< HEAD
=======
  slaveMotor(RightClawSlave,RightClaw);
  slaveMotor(LeftClawSlave,LeftClaw);
>>>>>>> parent of b43e24b... Raymond's ready for Hey-Day!


	motor[LeftClaw]=ClSpd;
	motor[RightClaw]=ClSpd;
}



// Scissor Hold
void srhold(int power)
{
<<<<<<< HEAD


	int motorBuffer = 50;
	if((power < motorBuffer && power > -motorBuffer)||(nMotorEncoder[Scissor]<ScrLowLmt&&power<0)||(nMotorEncoder[Scissor]>ScrUpLmt&&power>0)) power = 0;

=======
	int motorBuffer = 50;
	if((power < motorBuffer && power > -motorBuffer)||(SensorValue(ScissorDownS)&&power<0)/*||(SensorValue(ScissorUpS)&&power>0)*/) power = 0;
>>>>>>> parent of b43e24b... Raymond's ready for Hey-Day!

	motor[Scissor] = power;
}

// Left Claw Stop
void LClS(){
motor[LeftClaw]=0;
}

// Left Claw In
void LClI(){
motor[LeftClaw]=ClSpd;
}

// Left Claw Out
void LClO(){
motor[LeftClaw]=-ClSpd;
}


// Right Claw Stop
void RClS(){
motor[RightClaw]=0;
}

// Right Claw In
void RClI(){
motor[RightClaw]=ClSpd;
}

// Right Claw Out
void RClO(){
motor[RightClaw]=-ClSpd;
<<<<<<< HEAD
=======
}

void RCC(){
	int S = SensorValue(RightClawRot);
if(S<(inR-clB)) RClI();
else if(S>(inR+clB)) RClO();
else RClS();
>>>>>>> parent of b43e24b... Raymond's ready for Hey-Day!
}

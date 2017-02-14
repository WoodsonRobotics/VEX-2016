// Claw Speed
#define ClSpd 50




#define ScrUpLmt 4000
#define ScrLowLmt -175

void srsetup()
{
	slaveMotor(ScissorSlave,Scissor);


	motor[LeftClaw]=ClSpd;
	motor[RightClaw]=ClSpd;
}



// Scissor Hold
void srhold(int power)
{


	int motorBuffer = 50;
	if((power < motorBuffer && power > -motorBuffer)||(nMotorEncoder[Scissor]<ScrLowLmt&&power<0)||(nMotorEncoder[Scissor]>ScrUpLmt&&power>0)) power = 0;


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
}

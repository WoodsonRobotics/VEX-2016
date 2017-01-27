// Claw Speed
#define ClSpd 50





void srsetup()
{
	slaveMotor(ScissorSlave,Scissor);


	motor[LeftClaw]=ClSpd;
	motor[RightClaw]=ClSpd;
}



// Scissor Hold
void srhold(int power)
{
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

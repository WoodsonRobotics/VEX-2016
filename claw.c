// Claw Speed
#define ClSpd 75

#define inSpot 1000
#define outSpot 50




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

void LCC(){
	int S = SensorValue(LeftClawRot);
if(S<inSpot) LClI();
else if(S>(inSpot+5)) LClO();
else LClS();
}

void LCO(){
int S = SensorValue(LeftClawRot);
if(S<outSpot) LClI();
else if(S>(outSpot+5)) LClO();
else LClS();
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

void RCC(){
	int S = SensorValue(LeftClawRot);
if(S<inSpot) RClI();
else if(S>(inSpot+5)) RClO();
else RClS();
}

void RCO(){
int S = SensorValue(LeftClawRot);
if(S<outSpot) RClI();
else if(S>(outSpot+5)) RClO();
else RClS();
}

// Claw Speed
#define ClSpd 75

#define outR 1750
#define outL 1650

#define inR 3100
#define inL 3000

#define clB 250


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
	if(power < motorBuffer && power > -motorBuffer) power = 0;

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
if(S<(inL-clB)) LClI();
else if(S>(inL+clB)) LClO();
else LClS();
}

void LCO(){
int S = SensorValue(LeftClawRot);
if(S<(outL-clB)) LClI();
else if(S>(outL+clB)) LClO();
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
	int S = SensorValue(RightClawRot);
if(S<(inR-clB)) RClI();
else if(S>(inR+clB)) RClO();
else RClS();
}

void RCO(){
int S = SensorValue(RightClawRot);
if(S<(outR-clB)) RClI();
else if(S>(outR+clB)) RClO();
else RClS();
}

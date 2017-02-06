// Claw Speed
#define ClSpd 75

#define inR 3100
#define inL 2925

#define clB 10


void srsetup()
{
	slaveMotor(ScissorSlave,Scissor);
  slaveMotor(RightWheelsSlave,RightWheels);
  slaveMotor(LeftWheelsSlave,LeftWheels);


}



// Scissor Hold
void srhold(int power)
{
	if(SensorValue(Falling0)||SensorValue(Falling1)||SensorValue(Falling2)||SensorValue(Falling3)) power = -127;
	int motorBuffer = 50;
	if((power < motorBuffer && power > -motorBuffer)||(SensorValue(RightClawRot)<180)||(SensorValue(LeftClawRot)<180)||(SensorValue(ScissorDownT)&&power<0)||(SensorValue(ScissorUpT)&&!SensorValue(ScissorDownT)&&power>0)) power = 0;
  //if(power<0&&SensorValue(RightClawRot)>=1200&&SensorValue(RightClawRot)<=2200) power=0;
  //if(power<0&&SensorValue(LeftClawRot)>=1700&&SensorValue(LeftClawRot)<=2200) power=0;
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

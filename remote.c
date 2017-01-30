// Rotation
#define Rotation 	vexRT[Ch2Xmtr2]
// Front-Back Drive
#define FBdrive 	vexRT[Ch1Xmtr2]
// Scissor
#define ScissorMove	vexRT[Ch3Xmtr2]
// LeftClaw
#define LeftClawOut	vexRT[Btn5DXmtr2]
#define LeftClawIn  vexRT[Btn5UXmtr2]
// RightClaw
#define RightClawOut vexRT[Btn6UXmtr2]
#define RightClawIn  vexRT[Btn6DXmtr2]
// Freak Out
#define FreakOut vexRT[Btn8RXmtr2]

void remote()
{
	// Motors running at speeds less than 20 make a whining sound that is not great for the motor.
	int motorBuffer = 20;
	srsetup();
	while (true)
	{
		int Right = (FBdrive - Rotation)/2;
		int Left = (FBdrive + Rotation)/2;


		if(Right < motorBuffer && Right > -motorBuffer) Right = 0;
		if(Left < motorBuffer && Left > -motorBuffer) Left = 0;


		motor[LeftWheels] = Left;
		motor[RightWheels] = Right;

		// Scissor Control
		srhold(ScissorMove);
		// Left Claw Control
		if(LeftClawOut) LClO();
		else if(LeftClawIn)  LClI();
		else LClS();
		// Right Claw Control
		if(RightClawOut) RClO();
		else if(RightClawIn)  RClI();
		else RClS();

		if(FreakOut) stopAllMotors();
	}
}

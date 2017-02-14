// Rotation
#define Rotation 	vexRT[Ch2]
// Front-Back Drive
#define FBdrive 	vexRT[Ch1]
// Scissor
#define ScissorMove	vexRT[Ch3]
// LeftClaw
#define LeftClawOut	vexRT[Btn5D]
#define LeftClawIn  vexRT[Btn5U]
// RightClaw
#define RightClawOut vexRT[Btn6U]
#define RightClawIn  vexRT[Btn6D]
// shortcut quick-key for closing the claw
#define ClawClose vexRt[Btn7U]
// Freak Out
#define FreakOut vexRT[Btn8R]

void remote()
{
	// Motors running at speeds less than 20 make a whining sound that is not great for the motor.
	int motorBuffer = 20;
	srsetup();
<<<<<<< HEAD
	bool btnChange = true;
=======
	bool clawClose = true;
	bool clawCloseBtnChng = true;
>>>>>>> parent of 99610ba... we competed with this code
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
		// claw shortcut btns
		if(clawClose)

		// Left Claw Control
		if(LeftClawOut) LClO();
		else if(LeftClawIn)  LClI();
		else if(clawClose)
		else LClS();
		// Right Claw Control
		if(RightClawOut) RClO();
		else if(RightClawIn)  RClI();
		else RClS();

		if(FreakOut) stopAllMotors();
	}
}

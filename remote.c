// Rotation
#define Rotation 	vexRT[Ch2]
// Front-Back Drive
#define FBdrive 	vexRT[Ch1]
// Scissor
#define ScissorMove	vexRT[Ch3]
// LeftClaw
<<<<<<< HEAD
#define LeftClawOut	vexRT[Btn5D]
#define LeftClawIn  vexRT[Btn5U]
// RightClaw
#define RightClawOut vexRT[Btn6U]
#define RightClawIn  vexRT[Btn6D]
// shortcut quick-key for closing the claw
#define ClawClose vexRt[Btn7U]
=======
#define LeftClawOut	vexRT[Btn5U]
#define LeftClawIn  vexRT[Btn5D]
// RightClaw
#define RightClawOut vexRT[Btn6U]
#define RightClawIn  vexRT[Btn6D]
// CloseClaw
#define clawCloseToggle vexRT[Btn7U]
#define clawOpen vexRT[Btn7D]
>>>>>>> parent of b43e24b... Raymond's ready for Hey-Day!
// Freak Out
#define FreakOut vexRT[Btn8R]

void remote()
{
	// Motors running at speeds less than 20 make a whining sound that is not great for the motor.
	int motorBuffer = 20;
	srsetup();

	bool btnChange = true;

	bool clawClose = true;
	bool clawCloseBtnChng = true;

	while (true)
	{
		int Right = (FBdrive - Rotation)/2;
		int Left = (FBdrive + Rotation)/2;


		if(Right < motorBuffer && Right > -motorBuffer) Right = 0;
		if(Left < motorBuffer && Left > -motorBuffer) Left = 0;


		motor[LeftWheels] = Left;
		motor[RightWheels] = Right;
if(FreakOut) stopAllMotors();
		// Scissor Control
		srhold(ScissorMove);
<<<<<<< HEAD
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
=======
		if(FreakOut) stopAllMotors();
		if(clawCloseToggle){
			if(clawCloseBtnChng){
				clawClose=!clawClose;
				clawCloseBtnChng=false;
			}
			}else{
			clawCloseBtnChng=true;
		}



if(FreakOut) stopAllMotors();
		// Left Claw Control
		if(LeftClawOut || clawOpen) LClO();
		else if(LeftClawIn)  LClI();
		else if(clawClose) LCC();
		else LClS();
		if(FreakOut) stopAllMotors();
		// Right Claw Control
		if(RightClawOut || clawOpen) RClO();
		else if(RightClawIn)  RClI();
		else if(clawClose) RCC();
		else RClS();

		if(FreakOut) stopAllMotors();
		sleep(1);
>>>>>>> parent of b43e24b... Raymond's ready for Hey-Day!
	}
}

// partner or no?
#define part vexRT[Btn8L]
// Rotation
#define Rotation 	((part)?(vexRT[Ch2Xmtr2]):(vexRT[Ch2]))
// Front-Back Drive
#define FBdrive 	((part)?(vexRT[Ch1Xmtr2]):(vexRT[Ch1]))
// Scissor
#define ScissorMove	((part)?(vexRT[Ch3Xmtr2]):(vexRT[Ch3]))
// LeftClaw
#define LeftClawOut	((part)?(vexRT[Btn5UXmtr2]):(vexRT[Btn5U]))
#define LeftClawIn  ((part)?(vexRT[Btn5DXmtr2]):(vexRT[Btn5D]))
// RightClaw
#define RightClawOut ((part)?(vexRT[Btn6UXmtr2]):(vexRT[Btn6U]))
#define RightClawIn  ((part)?(vexRT[Btn6DXmtr2]):(vexRT[Btn6D]))
// CloseClaw
#define clawCloseToggle ((part)?(vexRT[Btn8UXmtr2]):(vexRT[Btn8U]))
#define clawCloseB ((part)?(vexRT[Btn7UXmtr2]):(vexRT[Btn7U]))
#define clawOpenB ((part)?(vexRT[Btn7DXmtr2]):(vexRT[Btn7D]))


void remote()
{
	// Motors running at speeds less than 20 make a whining sound that is not great for the motor.
	int motorBuffer = 20;
	srsetup();
	bool clawClose = false;
	bool clawCloseBtnChng = true;
	while (true)
	{
		int Right = (FBdrive - Rotation)/2;
		int Left = (FBdrive + Rotation)/2;


		if(Right < motorBuffer && Right > -motorBuffer) Right = 0;
		if(Left < motorBuffer && Left > -motorBuffer) Left = 0;


		motor[LeftWheels] = Left;
		motor[RightWheels] = Right;

		// Scissor Control
		if(SensorValue(ScissorDownT)) {nMotorEncoder[ScissorLift]=0;}

		srhold(ScissorMove);

		if(clawCloseToggle){
			if(clawCloseBtnChng){
				clawClose=!clawClose;
				clawCloseBtnChng=false;
			}
			}else{
			clawCloseBtnChng=true;
		}




		// Left Claw Control
		if(LeftClawOut || clawOpenB) LClO();
		else if(LeftClawIn || clawCloseB)  LClI();
		else if(clawClose) LCC();
		else LClS();

		// Right Claw Control
		if(RightClawOut || clawOpenB) RClO();
		else if(RightClawIn || clawCloseB)  RClI();
		else if(clawClose) RCC();
		else RClS();


		sleep(1);
	}
}

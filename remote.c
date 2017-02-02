// Rotation
#define Rotation 	vexRT[Ch2]
// Front-Back Drive
#define FBdrive 	vexRT[Ch1]
// Scissor
#define ScissorMove	vexRT[Ch3]
// LeftClaw
#define LeftClawOut	vexRT[Btn5U]
#define LeftClawIn  vexRT[Btn5D]
// RightClaw
#define RightClawOut vexRT[Btn6U]
#define RightClawIn  vexRT[Btn6D]
// CloseClaw
#define clawCloseToggle vexRT[Btn7U]
#define clawOpenToggle vexRT[Btn7D]
// Freak Out
#define FreakOut vexRT[Btn8R]

void remote()
{
	// Motors running at speeds less than 20 make a whining sound that is not great for the motor.
	int motorBuffer = 20;
	srsetup();
	bool clawClose = false;
	bool clawOpen = true;
	bool clawCloseBtnChng = true;
	bool clawOpenBtnChng = true;
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
		if(FreakOut) stopAllMotors();
		if(clawCloseToggle){
			if(clawCloseBtnChng){
				if(clawClose){
					clawClose=false;
					}else{
					clawClose=true;
					clawOpen=false;
				}
				clawCloseBtnChng=false;
			}
			}else{
			clawCloseBtnChng=true;
		}
		if(FreakOut) stopAllMotors();
		if(clawOpenToggle){
			if(clawOpenBtnChng){
				if(clawOpen){
					clawOpen=false;
					}	else{
					clawOpen=true;
					clawClose=false;
				}


				clawOpenBtnChng=false;
			}
			}else{
			clawOpenBtnChng=true;
		}

if(FreakOut) stopAllMotors();
		// Left Claw Control
		if(LeftClawOut) LClO();
		else if(LeftClawIn)  LClI();
		else if(clawClose) LCC();
		else if(clawOpen) LCO();
		else LClS();
		if(FreakOut) stopAllMotors();
		// Right Claw Control
		if(RightClawOut) RClO();
		else if(RightClawIn)  RClI();
		else if(clawClose) RCC();
		else if(clawOpen) RCO();
		else RClS();

		if(FreakOut) stopAllMotors();
		sleep(1);
	}
}

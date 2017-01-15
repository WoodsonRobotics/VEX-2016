
#define Rotation 	vexRT[Ch4]
// Left-Right Strafe
#define LRstraif 	vexRT[Ch1]
// Front-Back Drive
#define FBdrive 	vexRT[Ch2]
#define ClawOpen	vexRT[Btn6U]
#define ClawClose	vexRT[Btn6D]
#define ScissorUp		vexRT[Btn5U]
#define ScissorDown	vexRT[Btn5D]
#define ClawUp vexRT[Btn7D]
#define ClawDown vexRT[Btn7U]
#define FreakOut vexRT[Btn8L]


void remote()
{
	// Motors running at speeds less than 20 make a whining sound that is not great for the motor.
	int motorBuffer = 20;
	srsetup();
	while (true)
	{
		int Mfr = -FBdrive + Rotation + LRstraif;
		int Mbr = -FBdrive + Rotation - LRstraif;
		int Mfl = -FBdrive - Rotation - LRstraif;
		int Mbl = -FBdrive - Rotation + LRstraif;

		if(Mfr < motorBuffer && Mfr > -motorBuffer) Mfr = 0;
		if(Mbr < motorBuffer && Mbr > -motorBuffer) Mbr = 0;
		if(Mfl < motorBuffer && Mfl > -motorBuffer) Mfl = 0;
		if(Mbl < motorBuffer && Mbl > -motorBuffer) Mbl = 0;

		motor[FrontRight] = Mfr;
		motor[BackRight] = Mbr;
		motor[FrontLeft] = Mfl;
		motor[BackLeft] = Mbl;

		// Scissor Control
		if(ScissorUp) srup();
		if(ScissorDown) srdown();
		if( !(ScissorUp || ScissorDown) ) srhold();
		// Claw Control
		if(ClawOpen) clopen();
		if(ClawClose) clclose();
		if(!(ClawOpen || ClawClose)) clstop();
		if(ClawUp) clup();
		if(ClawDown) cldown();
		if( !(ClawUp || ClawDown) ) clrothold();
		if(FreakOut) stopAllMotors();
	}
}

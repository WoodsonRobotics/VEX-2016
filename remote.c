

#define Rotation 	vexRT[Ch4]/2
// Left-Right Strafe
#define LRstraif 	vexRT[Ch1]/2
// Front-Back Drive
#define FBdrive 	vexRT[Ch2]/2
#define ClawOpen	vexRT[Btn6U]
#define ClawClose	vexRT[Btn6D]
#define ScissorUp		vexRT[Btn5U]
#define ScissorDown	vexRT[Btn5D]
#define ClawUp vexRT[Btn8D]
#define ClawDown vexRT[Btn8U]


void remote()
{
	// Motors running at speeds less than 20 make a whining sound that is not great for the motor.
	int motorBuffer = 20;
	clsetup();
	while (true)
	{
		int Mfr = -FBdrive + Rotation - LRstraif;
		int Mbr = -FBdrive + Rotation + LRstraif;
		int Mfl = -FBdrive - Rotation + LRstraif;
		int Mbl = -FBdrive - Rotation - LRstraif;

		if(Mfr < motorBuffer && Mfr > -motorBuffer) Mfr = 0;
		if(Mbr < motorBuffer && Mbr > -motorBuffer) Mbr = 0;
		if(Mfl < motorBuffer && Mfl > -motorBuffer) Mfl = 0;
		if(Mbl < motorBuffer && Mbl > -motorBuffer) Mbl = 0;

		motor[FR] = Mfr;
		motor[BR] = Mbr;
		motor[FL] = Mfl;
		motor[BL] = Mbl;

		// Claw Control
		if(ClawOpen) clopen();
		if(ClawClose) clclose();
		if(ScissorUp) srup();
		if(ScissorDown)srdown();
		if(ClawUp) clup();
		if(ClawDown) cldown();
		sleep(100);
	}
}

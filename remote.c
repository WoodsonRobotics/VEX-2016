#define Rotation 	vexRT[Ch4]/2
// Left-Right Strafe
#define LRstraif 	vexRT[Ch1]
// Front-Back Drive
#define FBdrive 	vexRT[Ch2]/2
#define ClawOpen	vexRT[Btn6U]
#define ClawClose	vexRT[Btn6D]
#define ClawUp		vexRT[Btn5U]
#define ClawDown	vexRT[Btn5D]

void remote()
{
	// Motors running at speeds less than 20 make a whining sound that is not great for the motor.
	int motorBuffer = 20;
	clsetup();
	while (true)
	{
		/*
		motor[FL] = FBdrive + LRstraif + Rotation;
		motor[FR] = -FBdrive + LRstraif + Rotation;
		motor[BL] = FBdrive - LRstraif + Rotation;
		motor[BR] = -FBdrive - LRstraif + Rotation;
		//*/

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
		if(ClawUp) clup();
		if(ClawDown)cldown();
		sleep(100);
	}
}

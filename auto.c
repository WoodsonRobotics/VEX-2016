void drive (int FB, int LR, int RO)
{
	int motorBuffer = 20;
	int Mfr = -FB + RO + LR;
	int Mbr = -FB + RO - LR;
	int Mfl = -FB - RO - LR;
	int Mbl = -FB - RO + LR;

	if(Mfr < motorBuffer && Mfr > -motorBuffer) Mfr = 0;
	if(Mbr < motorBuffer && Mbr > -motorBuffer) Mbr = 0;
	if(Mfl < motorBuffer && Mfl > -motorBuffer) Mfl = 0;
	if(Mbl < motorBuffer && Mbl > -motorBuffer) Mbl = 0;

	motor[FrontRight] = Mfr;
	motor[BackRight] = Mbr;
	motor[FrontLeft] = Mfl;
	motor[BackLeft] = Mbl;
}

void auto()
{
	srsetup();
	//int temp = ((SensorValue(LeftOrRight)/4095.0)*3);//potentiometer values range from 0 to 4095 with leftmost being 0 and rightmost being 4095

	// Fully Extend Scissor
	srup();
	sleep(4000);
	srhold();
	// Drive forward
	drive(120,0,0);
	sleep(3000);
	drive(0,0,0);
}

// Motors running at speeds less than 20 make a whining sound that is not great for the motor.

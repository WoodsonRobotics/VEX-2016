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
	int temp = ((SensorValue(LeftOrRight)/4095.0)*3);//potentiometer values range from 0 to 4095 with leftmost being 0 and rightmost being 4095
	if(temp == 0)
	{
		// Move forward and slightly left
		drive(127,-50,0);
		clopen();
		sleep(1000);
		clstop();
		// Fully extend scissor
		srup();
		sleep(5000);
		// Move forward
		drive(127,0,0);
		srhold();
		sleep(750);
		// Stop driving
		drive(0,0,0);
		drive(0,32,0);
		while(1)
		{
			clup();
			sleep(250);
			cldown();
			sleep(250);
		}
	}
	else if(temp == 2)
	{
		// Move forward and slightly left
		drive(127,50,0);
		clopen();
		sleep(500);
		clstop();
		// Fully extend scissor
		srup();
		sleep(5000);
		// Move forward
		drive(127,0,0);
		srhold();
		sleep(750);
		// Stop driving
		drive(0,0,0);
		drive(0,-32,0);
		while(1)
		{
			clup();
			sleep(250);
			cldown();
			sleep(250);
		}
	}
	else if (temp == 1)
	{
		sleep(15000);
	}
}

// Motors running at speeds less than 20 make a whining sound that is not great for the motor.

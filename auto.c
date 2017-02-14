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


}

void auto()
{
	srsetup();
<<<<<<< HEAD
	//int temp = ((SensorValue(LeftOrRight)/4095.0)*3);//potentiometer values range from 0 to 4095 with leftmost being 0 and rightmost being 4095

	// Fully Extend Scissor
	//srup();
	sleep(3500);
	//srhold();
	// Drive forward
	drive(120,0,0);
	sleep(3000);
	drive(0,0,0);
=======
	for(int i=0;i<500;i++)
	{
		LCC();
		RCC();
		srhold(127);
		sleep(1);
	}
	for(int i=0;i<500;i++)
	{
		motor[LeftWheels] = 127;
		motor[RightWheels] = 127;
		srhold(127);
		LCC();
		RCC();
		sleep(1);
	}
	for(int i=0;i<2500;i++)
	{
		motor[LeftWheels] = 127;
		motor[RightWheels] = 127;
		srhold(0);
		LCC();
		RCC();
		sleep(1);
	}
	stopAllMotors();

>>>>>>> parent of 99610ba... we competed with this code
}

// Motors running at speeds less than 20 make a whining sound that is not great for the motor.

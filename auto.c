void auto()
{
	srsetup();
	int temp = ((SensorValue(LeftOrRight)/4095.0)*3);//potentiometer values range from 0 to 4095 with leftmost being 0 and rightmost being 4095
	if(temp==0){
		while(1){
//drive(127,-50,0);
clopen();
sleep(500);
clstop();
sleep(2000);
//drive(0,0,0);
clclose();
sleep(1000);
srup();
sleep(500);
//drive(127,0,0);
srhold();

		}
		}else if(temp==1){
		while(1){



		}
		}else{

	}
	sleep(1000);
}

// Motors running at speeds less than 20 make a whining sound that is not great for the motor.


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

		void jkfdsl(){
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
		sleep(100);
	}

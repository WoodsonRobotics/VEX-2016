
void auto()
{
	srsetup();
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

}

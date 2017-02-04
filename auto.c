
void auto()
{
	srsetup();
	for(int i=0;i<250;i++)
	{
		LCC();
		RCC();
		srhold(127);
		sleep(1);
	}
	for(int i=0;i<3000;i++)
	{

		srhold(127);
		LClS();
		RClS();
		sleep(1);
	}
	for(int i=0;i<2000;i++)
	{
		motor[LeftWheels] = 127;
		motor[RightWheels] = -127;
		srhold(0);
		LClS();
		RClS();
		sleep(1);
	}
	motor[LeftWheels] = 0;
		motor[RightWheels] = 0;
  for(int i=0;i<500;i++){
	RCC();
	sleep(1);
}
}

// Speed difference to change height
#define SpdDif 50
// Scissor Base Speed
#define SciBase 25
// Speed to open/close claw
#define OpClSpd 50
// Speed to lift/lower claw
#define LiftLow 75

void srsetup()
{
	motor[ScissorRight] = SciBase;
	motor[ScissorLeft] = SciBase;
	// Set motor encoders to zero to ensure good operation
	nMotorEncoder[ScissorLeft] = 0;
	nMotorEncoder[ClawRotation] = 0;
}
// Scissor Up
void srup()
{
	motor[ScissorLeft] = SciBase + SpdDif;
	motor[ScissorRight] = SciBase + SpdDif;
}
// Scissor Down
void srdown()
{
	motor[ScissorLeft] = SciBase - SpdDif;
	motor[ScissorRight] = SciBase - SpdDif;
}
// Scissor Hold
void srhold()
{
	motor[ScissorLeft] = SciBase;
	motor[ScissorRight] = SciBase;
}
// Claw Hold
task clhold()
{
	int clawCurrent = nMotorEncoder[ClawRotation];
	motor[ClawRotation] = 0;
	while(1)
	{
		if(nMotorEncoder[ClawRotation] > clawCurrent)
		{
			motor[ClawRotation] = LiftLow;
			sleep(50);
			motor[ClawRotation] = 0;
		}
	}
}
// Claw Open
void clopen()
{
	motor[ClawGrab] = OpClSpd;
	sleep(500);
	motor[ClawGrab] = 0;
}
// Claw Close
void clclose()
{
	motor[ClawGrab] = -OpClSpd;
	sleep(500);
	motor[ClawGrab] = 0;
}
// Claw Up
void clup()
{
	stopTask(clhold);
	motor[ClawRotation] = LiftLow;
	sleep(100);
	startTask(clhold);
}
// Claw Down
void cldown()
{
	StopTask(clhold);
	motor[ClawRotation] = -LiftLow;
	sleep(100);
	startTask(clhold);
}


// Motor Encoder
// 627.2 per full rotation of the gear
// Initial position is zero

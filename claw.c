// Speed difference to change height
#define SpdDif 50
// Scissor Base Speed
#define SciBase 25
// Speed to open/close claw
#define OpClSpd 50
// Speed to lift/lower claw
#define LiftLow 75

#define ClawUp 1000
#define ClawDown 1000

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
	motor[ClawRotation] = LiftLow;
	sleep(100);
	startTask(clhold(nMotorEncoder[ClawRotation]));
}
// Claw Down
void cldown()
{
	motor[ClawRotation] = -LiftLow;
	sleep(100);
	startTask(clhold(nMotorEncoder[ClawRotation]));
}
// Claw Hold
task clhold(int clawCurrent)
{
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

// Motor Encoder
// 627.2 per full rotation of the gear
// Initial position is zero

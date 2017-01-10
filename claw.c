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
	startTask(rotateClaw(ClawUp));
}
// Claw Down
void cldown()
{
	motor[ClawRotation] = -LiftLow;
	startTask(rotateClaw(ClawDown));
}
// Claw Hold
void clhold()
{
	motor[ClawRotation] = 0;
}
task rotateClaw(int end)
{
	while(nMotorEncoder[ClawRotation] < end)
	{

	}
}

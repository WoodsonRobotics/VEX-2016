// Speed difference to change height
#define SpdDif 50
// Scissor Base Speed
#define SciBase 25
// Speed to open/close claw
#define OpClSpd 50
// Speed to lift/lower claw
#define LiftLow 75
bool ClawOpen = false;

void clsetup()
{
	motor[SR] = SciBase;
	motor[SL] = SciBase;
}
// Scissor Up
void srup()
{
	motor[SL] = SciBase + SpdDif;
	motor[SR] = SciBase + SpdDif;
}
// Scissor Down
void srdown()
{
	motor[SL] = SciBase - SpdDif;
	motor[SR] = SciBase - SpdDif;
}
// Scissor Hold
void srhold()
{
motor[SL] = SciBase;
motor[SR] = SciBase;
}
// Claw Open
void clopen()
{
	motor[CG] = OpClSped;
	sleep(500);
	motor[CG] = 0;
	ClawOpen = true;
}
// Claw Close
void clclose()
{
	motor[CG] = -OpClSped;
	sleep(500);
	motor[CG] = 0;
	ClawOpen = false;
}
// Claw Up
void clup()
{
motor[CR] = LiftLow;
}
// Claw Down
void cldown()
{
motor[CR] = -LiftLow;
}
// Claw Hold
void clhold()
{
motor[CR] = 0;
}
// Claw Open or Close
void clopcl()
{
	if(ClawOpen) clclose();
	else clopen();
}

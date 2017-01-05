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
	motor[CG] = OpClSpd;
	sleep(500);
	motor[CG] = 0;
}
// Claw Close
void clclose()
{
	motor[CG] = -OpClSpd;
	sleep(500);
	motor[CG] = 0;
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

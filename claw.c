// Fill out later
//#define SL 0
//#define SR 0
//#define CF 0
//#define CL 0
//#define CR 0
// Speed difference to change height
#define SDU 50
// Scissor Base Speed
#define SB 25
// Speed to open/close claw
#define CS 50
// Speed to lift/lower claw
#define CRS 75
bool ClawOpen = false;

void clsetup()
{
	motor[SR] = SB;
	motor[SL] = SB;
}
// Scissor Up
void srup()
{
	motor[SL] = SB + SDU;
	motor[SR] = SB + SDU;
}
// Scissor Down
void srdown()
{
	motor[SL] = SB - SDU;
	motor[SR] = SB - SDU;
}
// Scissor Hold
void srhold()
{
motor[SL] = SB;
motor[SR] = SB;
}
// Claw Open
void clopen()
{
	motor[CG] = CS;
	sleep(500);
	motor[CG] = 0;
	ClawOpen = true;
}
// Claw Close
void clclose()
{
	motor[CG] = -CS;
	sleep(500);
	motor[CG] = 0;
	ClawOpen = false;
}
// Claw Up
void clup()
{
motor[CR] = CRS;
}
// Claw Down
void cldown()
{
motor[CR] = -CRS;
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

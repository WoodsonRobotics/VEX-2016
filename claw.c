// Fill out later
#define SL 0
#define SR 0
#define CF 0
#define CL 0
#define CR 0
// Speed difference to change height
#define SDU 10
// Scissor Base Speed
#define SB 150
// Speed to open/close claw
#define CS 50
bool ClawOpen = false;

void clsetup()
{
	motor[SR] = SB;
	motor[SL] = SB;
}
// Scissor Up
void srup()
{
	motor[SL] += SDU;
	motor[SR] += SDU;
}
// Scissor Down
void srdown()
{
	motor[SL] -= SDU;
	motor[SR] -= SDU;
}
// Claw Open
void clopen()
{
	motor[CF] = CS;
	sleep(500);
	motor[CF] = 0;
	ClawOpen = true;
}
// Claw Close
void clclose()
{
	motor[CF] = -CS;
	sleep(500);
	motor[CF] = 0;
	ClawOpen = false;
}
// Claw Open or Close
void clopcl()
{
	if(ClawOpen) clclose();
	else clopen();
}

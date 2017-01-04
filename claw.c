// Fill out later
//#define SL 0
//#define SR 0
//#define CF 0
//#define CL 0
//#define CR 0
// Speed difference to change height
#define SDU 10
// Scissor Base Speed
#define SB 150
// Speed to open/close claw
#define CS 50
// Speed to lift/lower claw
#define CR 50
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
void clup()//                                 reverse one of the motors wires so they turn in different directions
{
motor[CR] = CR;
}
// Claw Down
void cldown()//                               reverse one of the motors wires so they turn in different directions
{
motor[CR] = -CR;
}
// Claw Open or Close
void clopcl()
{
	if(ClawOpen) clclose();
	else clopen();
}

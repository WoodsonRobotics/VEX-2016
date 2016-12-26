// Fill out later
//#define CL 0
//#define CR 0
#define CF 0
// Amount to change height
#define CDU 10
#define CB 25
#define CS 50
bool ClawOpen = false;

void clsetup()
{
	motor[CR] = CB;
	motor[CL] = CB;
}
// Claw Up
void clup()
{
	motor[CL] += CDU;
	motor[CR] += CDU;
}
// Claw Down
void cldown()
{
	motor[CL] -= CDU;
	motor[CR] -= CDU;
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

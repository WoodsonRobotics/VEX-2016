// Fill out later
#define CL 0
#define CR 0
#define CF 0
// Claw Speed
#define CS 50
bool ClawOpen = false;

// Claw Up
void clup()
{
	motor[CL] = CS;
	motor[CR] = CS;
	sleep(500);
	motor[CL] = 0;
	motor[CR] = 0;
}
// Claw Down
void cldown()
{
	motor[CL] = -CS;
	motor[CR] = -CS;
	sleep(500);
	motor[CL] = 0;
	motor[CR] = 0;
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

// max speed difference to change height
#define MaxSpdDifScr 50
// scissor height unit to change by each tick
#define ScrHitUnit 25
// Speed to open/close claw
#define OpClSpd 75
// max speed to rotate claw
#define MaxSpdDifClw 75
// claw height unit to change by each tick
#define ClwHitUnit 25
// claw hold power constant
#define ClwHld 100
// claw move power constant
#define ClwMve 10
// encoder clicks per full rotation according to
// "http://help.robotc.net/WebHelpVEX/index.htm#Resources/topics/VEX_Cortex/ROBOTC/Motor_and_Servo/nMotorEncoder.htm"
#define EncClk 627

#define SpdDif 25
#define SciBase 25

void srsetup()
{
	slaveMotor(ScissorSlave,Scissor);
	nMotorEncoder[Scissor] = EncClk * (-60 * 7) / 360;
	nMotorEncoder[Claw] = EncClk * (180) / 360;
	motor[Scissor] = SciBase;
	while(nMotorEncoder[Claw]>10){
		motor[ClawRotation] = ClwHld * cosDegrees(((360 * nMotorEncoder[Scissor] / EncClk) / 7) + (360 * nMotorEncoder[Claw] / EncClk)) - ClwMve;
	}
	motor[ClawRotation] = ClwHld * cosDegrees(((360 * nMotorEncoder[Scissor] / EncClk) / 7) + (360 * nMotorEncoder[Claw] / EncClk));
}

// Scissor Up
void srup()
{
	motor[Scissor] = SciBase + SpdDif;
}

// Scissor Down
void srdown()
{
	motor[Scissor] = SciBase - SpdDif;
}

// Scissor Hold
void srhold()
{
	motor[Scissor] = SciBase;
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
	motor[ClawRotation] = ClwHld * cosDegrees(((360 * nMotorEncoder[Scissor] / EncClk) / 7) + (360 * nMotorEncoder[Claw] / EncClk)) + ClwMve;
}

// Claw Down
void cldown()
{
	motor[ClawRotation] = ClwHld * cosDegrees(((360 * nMotorEncoder[Scissor] / EncClk) / 7) + (360 * nMotorEncoder[Claw] / EncClk)) - ClwMve;
}

// Claw hold
void clhold()
{
	motor[ClawRotation] = ClwHld * cosDegrees(((360 * nMotorEncoder[Scissor] / EncClk) / 7) + (360 * nMotorEncoder[Claw] / EncClk));
}

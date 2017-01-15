// max speed difference to change height
#define MaxSpdDifScr 50
// scissor height unit to change by each tick
#define ScrHitUnit 25
// Speed to open/close claw
#define OpClSpd 75
// max speed to rotate claw
#define MaxSpdDifClw 75
// claw height unit to change by each tick
#define ClwHitUnit 50
// claw hold power constant
#define ClwHld 25
// claw move power constant
#define ClwMve 50
// encoder clicks per full rotation according to
// "http://help.robotc.net/WebHelpVEX/index.htm#Resources/topics/VEX_Cortex/ROBOTC/Motor_and_Servo/nMotorEncoder.htm"
#define EncClk 627

#define SpdDif 100
#define SciBase 0

#define RotMath (ClwHld * cosDegrees(((360 * nMotorEncoder[Scissor]/ 21) / EncClk) + ((360 * nMotorEncoder[ClawRotation] / 3) / EncClk)))

void srsetup()
{
	slaveMotor(ScissorSlave,Scissor);
	slaveMotor(ClawRotationSlave1,ClawRotation);
	slaveMotor(ClawRotationSlave2,ClawRotation);
	nMotorEncoder[Scissor] = EncClk * (-60 * 21) / 360;
	nMotorEncoder[ClawRotation] = EncClk * (180 * 3) / 360;
	motor[Scissor] = SciBase;
	while((EncClk * nMotorEncoder[ClawRotation] * 3 / 360)>90){
		motor[ClawRotation] = RotMath - ClwMve;
	}
	motor[ClawRotation] = RotMath;
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
}

// Claw Close
void clclose()
{
	motor[ClawGrab] = -OpClSpd;
}
// Claw grab stop
void clstop()
{
	motor[ClawGrab]=0;
}
// Claw Up
void clup()
{
	motor[ClawRotation] = RotMath + ClwMve;
}

// Claw Down
void cldown()
{
	motor[ClawRotation] = RotMath - ClwMve;
}

// Claw hold
void clrothold()
{
	motor[ClawRotation] = RotMath;
}

#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    RightClawRot,   sensorPotentiometer)
#pragma config(Sensor, in2,    LeftClawRot,    sensorPotentiometer)
#pragma config(Sensor, dgtl1,  ScissorUpT,     sensorTouch)
#pragma config(Sensor, dgtl2,  ScissorDownT,   sensorTouch)
#pragma config(Sensor, dgtl3,  Falling0,       sensorTouch)
#pragma config(Sensor, dgtl4,  Falling1,       sensorTouch)
#pragma config(Sensor, dgtl11, Falling2,       sensorTouch)
#pragma config(Sensor, dgtl12, Falling3,       sensorTouch)
#pragma config(Sensor, I2C_1,  ScissorLift,    sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           LeftWheelsSlave, tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           LeftWheels,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           RightWheels,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           Scissor,       tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port5,           ScissorSlave,  tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           LeftClaw,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           RightClaw,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          RightWheelsSlave, tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// UNCOMMENT NEXT LINE FOR COMPETITIONS
// COMMENT OUT MAIN FOR COMPETITIONS
/*
#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"
//*/
#include "claw.c"
#include "remote.c"
#include "auto.c"
void debug()
{
	while(1)
	{
		writeDebugStreamLine("ScissorEncoder: ", nMotorEncoder[ScissorLift]);

		sleep(500);
	}
}

void pre_auton() {}


task autonomous()  { auto(); }
task usercontrol() { remote(); }

task main() { remote(); }
//task main() { auto(); }
//task main() { debug(); }

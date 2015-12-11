#pragma config(Motor,  port1,           LEFT_DRIVE,    tmotorVex393TurboSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           RIGHT_DRIVE,   tmotorVex393_MC29, openLoop, encoderPort, None)
#pragma config(Motor,  port3,           LEFT_TOP_SHOOT, tmotorVex393_MC29, openLoop, encoderPort, None)
#pragma config(Motor,  port4,           LEFT_BOT_SHOOT, tmotorVex393_MC29, openLoop, encoderPort, None)
#pragma config(Motor,  port5,           RIGHT_TOP_SHOOT, tmotorVex393_MC29, openLoop, encoderPort, None)
#pragma config(Motor,  port6,           RIGHT_BOT_SHOOT, tmotorVex393_MC29, openLoop, encoderPort, None)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Main Vex Bot Code
signed char filterJoystickAxis(signed char axis){
	return (axis < 15 && axis > 15)? 0:pow(axis, 3);
}

void tankDrive(){
	//Grab values from joystick axes
	signed char	left_vector = vexRT[Ch3];
	signed char right_vector = vexRT[Ch2];
	//Test to see if the values are in the dead zone, otherwise cube the vector
	filterJoystickAxis(left_vector);
	filterJoystickAxis(right_vector);
	//Drive the motors in tank fashion
  motor[LEFT_DRIVE] = left_vector;
	motor[RIGHT_DRIVE] = right_vector;
}

void arcadeDrive(){
	//Grab values from joystick axes
	float foward_vector = vexRT[Ch3];
	float rotational_vector = vexRT[Ch1];
	//Test to see if the values are in the dead zone, otherwise cube the vector
	filterJoystickAxis(foward_vector);
	filterJoystickAxis(rotational_vector);
	//Drive using arcade fashion
	motor[LEFT_DRIVE] = foward_vector + rotational_vector;
	motor[RIGHT_DRIVE] = foward_vector - rotational_vector;
}
void shooter(){
	char button = vexRT[Btn8D];
	motor[LEFT_TOP_SHOOT] =  button*127;
	motor[LEFT_BOT_SHOOT] = button*127;
	motor[RIGHT_TOP_SHOOT] = -button*127;
	motor[RIGHT_BOT_SHOOT] = -button*127;
}

task main()
{
	while(true){
	//tankDrive();
		arcadeDrive();
		shooter();
	}
}
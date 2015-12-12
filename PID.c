
struct PIDList{
	double pre_error;
	double integral;
	double error_band;
	double time_step;
	double MAX;
	double MIN;
	double kp;
	double ki;
	double kd;
};

double PidFunction(struct PIDList* pid, double input, double target ){
	double output;
	double error = target - input;

	double proportional = error * pid->kp;
	double derivative = (error - pid->pre_error/pid->time_step)*pid->kd;

	if(abs(error) > pid->error_band){
		pid->integral = pid->integral + (error*pid->time_step);
	}

	double integral = pid->integral * pid->ki;

	output = integral + proportional + derivative

	if(output > pid->MAX){
		output = pid->MAX;
	}
	else if(output < pid->MIN){
		output = pid->MIN;
	}

	return output;
}

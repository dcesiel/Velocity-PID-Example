#ifndef __PID_H__
#define __PID_H__

#define CONTROL_LOOP_TIME 0.02 //20 Millisecond loop time
#define MOTOR_CONV_FACTOR 0.1 //Number or equation that converts +/- RPM to 
							  //motor speed (0.10) is just a dummy number
							  //that I added here
#define KP 5
#define KI 2
#define KD 1

class pidInstace{

	double error;             //Proportional (P)
	double previousError;
	double errorSum;          //Integral     (I)
	double errorRateOfChange; //Derivative   (D)

	public:
	int pidCalc(double currentRPM);
	//EFFECTS: Returns motor speed based on PID calculation using current
	//         motor RPM
	
	pidInstance(double currentRPM);
	//CONSTRUCTOR
	//EFFECTS:  Initializes PID instance
};

#endif /* __PID_H__ */

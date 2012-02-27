#ifndef __PID_H__
#define __PID_H__

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

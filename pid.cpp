#include "pid.h"

#define CONTROL_LOOP_TIME 0.02 //20 Millisecond loop time
#define KP 0.00001
#define KI 0.0000001
#define KD 0.00001

pidInstance::pidInstance(double desiredRPM, double currentRPM){
//CONSTRUCTOR
//EFFECTS: Initializes PID instance
    previousError = desiredRPM - currentRPM;
    errorSum = 0;
}

int pidInstance::pidCalc(double desiredRPM, double currentRPM){
//EFFECTS: Returns motor speed based on PID calculation using current
//         motor RPM (I'm assuming that this function will be executed
//         during each control loop
    error = desiredRPM - currentRPM;
    errorSum = errorSum + (error*CONTROL_LOOP_TIME);
    errorRateOfChange = (error - previousError)/CONTROL_LOOP_TIME;
    previousError = error;
    //Note: I'm adding the output of the PID to itself because with velocity pid
    //      as error goes to 0 P becomes very small. The velocity will decrease
    //      when you want it to stay at a constant high speed. This works because
    //      your taking the derivative of both sides of the equation
    output += ((KP*error)+(KI*errorSum)+(KD*errorRateOfChange));
}

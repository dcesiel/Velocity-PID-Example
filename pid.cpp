#include "pid.h"

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
    return ((KD*error)+(KI*errorSum)+(KD*errorRateOfChange))*MOTOR_CONV_FACTOR;
}

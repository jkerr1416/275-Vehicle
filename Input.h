#ifndef INPUT_H
#define INPUT_H
/*************/
/*
 * File: Input.h
 * Author: Your Name
 * NetID: Your NetID
 * Date:
 *
 * Description: The Input class holds the values for the u variables used in the kinematic model.
 */
using namespace std;
/* Note: comments in this file thusfar are insufficient for
   a perfect grade in comments */
#include <string>
// M_PI and other variables are defined in here
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <math.h>

// the MAX and MIN values for tire angle are used
// in the setTireAngle method
#define MAX_TIRE_ANGLE_RATE 0.5236
#define MIN_TIRE_ANGLE_RATE -0.5236


/* Class comment goes here */
class Input{
private:
    double _velocity; // commanded vehicle velocity (u1)
    double _tire_angle_rate; // commanded tire angle rate (u2)
    double _timestamp; // time stamp at which this command is valid
    
public:
    // constructs a new Input object with these initial values
    Input(double vel, double tireAngleRate, double timestamp);
    // constructs an empty Input object
    Input();

    double getVelocity() const; // returns the _velocity
    void setVelocity(double vel); // sets the _velocity
    double getTireAngleRate() const; // returns the _tire_angle_rate
    void setTireAngleRate(double angle); // sets the _tire_angle_rate
    double getTimeStamp() const; // gets the _timestamp
    void setTimeStamp(double timestamp); // sets the _timestamp

};

#endif // INPUT_H

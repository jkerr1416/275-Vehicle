#include "Vehicle.h"
#include <string>
#include <math.h>
#include "Input.h"
#include "State.h"


Vehicle::Vehicle() {
	_state.setHeading(0);
	_state.setTimeStamp(0);
	_state.setTireAngle(0);
	_state.setXPos(0);
	_state.setYPos(0);
}

void Vehicle::setState(State x) {
	_state = x;
}

/*x1 is translational forward motion(position x
x2 is translational left / right motion(position y)
x3 is the tire angle
x4 is the heading of the vehicle
u1  vehicle velocity
u2  tire angle
L is wheelbase

x1(t + ∆t) = x1(t) + ∆tu1(t)cos(x3(t)) cos(x4(t))      
x2(t + ∆t) = x2(t) + ∆tu1(t)cos(x3(t)) sin(x4(t))
x3(t + ∆t) = x3(t) + ∆t u2(t)
x4(t + ∆t) = x4(t) + ∆t u1(t) (1 / L) sin(x3(t))  */

State Vehicle::getState() const {
	return _state;
}

void Vehicle::stateUpdate(Input u, double duration) {
	double newHeading, newTimeStamp, newTireAngle, newX, newY;
	newHeading = _state.getHeading() + ((duration*(u.getVelocity())) / L)*(sin(_state.getTireAngle()));
	newTimeStamp = _state.getTimeStamp() + duration;
	newTireAngle = _state.getTireAngle() + (duration * u.getTireAngleRate());
	if (newTireAngle < MIN_TIRE_ANGLE) {
		newTireAngle = MIN_TIRE_ANGLE;
	}
	if (newTireAngle > MAX_TIRE_ANGLE) {
		newTireAngle = MAX_TIRE_ANGLE;
	}
	if (newHeading < 0) {
		newHeading = newHeading + (2 * M_PI);
	}
	if (newHeading > 2 * M_PI) {
		newHeading = newHeading - (2 * M_PI);
	}
	newX = _state.getXPos() + (duration * u.getVelocity() * cos(_state.getTireAngle()) * cos(_state.getHeading()));
	newY = _state.getYPos() + (duration * u.getVelocity() * cos(_state.getTireAngle()) * sin(_state.getHeading()));
	State newState(newX, newY, newTireAngle, newHeading, newTimeStamp);
	setState(newState);
}

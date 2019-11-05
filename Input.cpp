#include "Input.h"
#include <string>
#include <math.h>
using namespace std;


	// constructs a new Input object with these initial values
	Input::Input(double vel, double tireAngleRate, double timestamp) {
		_velocity = vel;
		_tire_angle_rate = tireAngleRate;
		_timestamp = timestamp;
	}
	// constructs an empty Input object
	Input::Input() {
		_velocity = 0;
		_tire_angle_rate = 0;
		_timestamp = 0;
	}

	double Input::getVelocity() const {
		return _velocity;
	}
	void Input::setVelocity(double vel) {
		_velocity = vel;
	}
	double Input::getTireAngleRate() const {
		return _tire_angle_rate;
	}
	void Input::setTireAngleRate(double angle) {
		_tire_angle_rate = angle;
	}
	double Input::getTimeStamp() const {
		return _timestamp;
	}
	void Input::setTimeStamp(double timestamp) {
		_timestamp = timestamp;
	}

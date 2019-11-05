#include "State.h"
#include <string>
#include <math.h>
using namespace std;

	State::State(double x1, double x2, double x3, double x4, double timestamp) {
		_xpos = x1;
		_ypos = x2;
		_tire_angle = x3;
		_heading = x4;
		_timestamp = timestamp;
	}

	State::State() {
		_xpos = 0;
		_ypos = 0;
		_tire_angle = 0;
		_heading = 0;
		_timestamp = 0;
	}

	double State::getXPos() const {
		return _xpos;
	}
	void State::setXPos(double xpos) {
		_xpos = xpos;
	}
	double State::getYPos() const {
		return _ypos;
	}
	void State::setYPos(double ypos) {
		_ypos = ypos;
	}
	double State::getTireAngle() const {
		return _tire_angle;
	}
	void State::setTireAngle(double angle) {
		_tire_angle = angle;
	}
	double State::getHeading() const {
		return _heading;
	}
	void State::setHeading(double heading) {
		_heading = heading;
	}
	double State::getTimeStamp() const {
		return _timestamp;
	}
	void State::setTimeStamp(double timestamp) {
		_timestamp = timestamp;
	}



#include "vehicleSimulator.h"
#include <string>
#include <math.h>
#include "Input.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "State.h"
#include "Vehicle.h"
#include <iomanip>
#include <sstream>
using namespace std;


vehicleSimulator::vehicleSimulator(char* input, char*output) {
	inputFile.open(input);
	outputFile.open(output);
}


void vehicleSimulator::setInputList() {
	string inputLine;
	Input temp;
	double a, b, c;
	while (getline(inputFile, inputLine)) {
		stringstream currentLine;
		currentLine << inputLine;
		currentLine >> a >> b >> c;
		temp.setTimeStamp(a);
		temp.setVelocity(b);
		temp.setTireAngleRate(c);
		inputList.push_back(temp);
	}
	inputFile.close();
}



int vehicleSimulator::partition(vector<Input> *x, int low, int high) { //                 vector might need pointer

	bool done = false;
	Input temp;
	Input pivot = (*x).at((high+low)/2);
	while (!done) {
		while ((*x).at(low).getTimeStamp() < pivot.getTimeStamp()) {
			low++;
		}
		while ((*x).at(high).getTimeStamp() > pivot.getTimeStamp()) {
			high--;
		}
		if (low >= high) {
			done = true;
		}
		else {
			temp = (*x).at(low);
			(*x).at(low) = (*x).at(high);
			(*x).at(high) = temp;
			low++;
			high--;
		}
	}
	return high;
}


vector<Input> vehicleSimulator::sort(vector<Input> *x, int low, int high) { //                                                           look at quicksort zybooks
	int j = 0;
	if (low >= high) {
		return *x;
	}
	j = partition(x, low, high);

	sort(x, low, j);
	sort(x, j + 1, high);
	return *x;
}


bool vehicleSimulator::validate() {
	double temp = 0;
	if (inputList.at(0).getTimeStamp() != 0) {
		return false;
	}
	for (int i = 0; i < inputList.size(); i++) {
		if ((inputList.at(i).getTireAngleRate() > .5236) || (inputList.at(i).getTireAngleRate() < -.5236)) {
			return false;
		}
	}
	for (int i = 0; i < inputList.size(); i++) {
		if ((inputList.at(i).getVelocity() > 30) || (inputList.at(i).getVelocity() < 0)) {
			return false;
		}
	}
	for (int i = inputList.size()-1; i > 0; i--) {
		if ((inputList.at(i).getTimeStamp() < 0) || ((inputList.at(i).getTimeStamp() - inputList.at(i-1).getTimeStamp()) < .005) || ((inputList.at(i).getTimeStamp() - inputList.at(i - 1).getTimeStamp()) > .201)) {
			return false;
		}
	}
	return true;
}

vector<Input>vehicleSimulator::getVector() {
	return inputList;
}

vector<State> vehicleSimulator::applyInputs(Vehicle x) {
	vector<State> stateList;
	for (int i = 0; i <= inputList.size(); i++) {
		if (i != 0) {
			stateList.push_back(x.getState());
		}
		if (i < (inputList.size()-1)) {
			x.stateUpdate(inputList.at(i), (inputList.at(i + 1).getTimeStamp() - (inputList.at(i).getTimeStamp())));
		}
		else if (i == (inputList.size()-1)) {
			x.stateUpdate(inputList.at(i), .2);
		}

	}
	return stateList;
}

void vehicleSimulator::writeToFile(vector<State> x) {
	for (int i = 0; i < x.size(); i++) {
		outputFile << x.at(i).getTimeStamp() << ",";
		outputFile << x.at(i).getXPos() << ",";
		outputFile << x.at(i).getYPos() << ",";
		outputFile << x.at(i).getTireAngle() << ",";
		outputFile << x.at(i).getHeading() << endl;
	}
	outputFile.close();
}

void vehicleSimulator::setVector(vector<Input> x) {
	inputList = x;
}
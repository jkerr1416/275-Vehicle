#include <string>
#include <math.h>
#include <vector>
#include "Input.h"
#include <iostream>
#include <fstream>
#include "State.h"
#include "Vehicle.h"
#include <iomanip>
using namespace std;

class vehicleSimulator {

private:

	ifstream inputFile;
	ofstream outputFile;
	vector<Input> inputList;

public:

	vehicleSimulator(char* input, char* output);
	void setInputList();
	int partition(vector<Input> *x, int low, int high);
	vector<Input> sort(vector<Input> *x, int low, int high);
	bool validate();
	vector<Input> getVector();
	void setVector(vector<Input> x);
	vector<State> applyInputs(Vehicle x);
	void writeToFile(vector<State> x);
};




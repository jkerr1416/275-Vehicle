#include <string>
#include <math.h>
#include "vehicleSimulator.h"
#include "State.h"
#include "Input.h"
#include "Vehicle.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main(int argc, char *argv[3]) {

	if (argc != 3) {
		cout << "Error, Usage : program inputFile outputFile";
		return 0;
	}
	ifstream in;
	in.open(argv[1]);
	if (in.is_open() == 0) {
		cout << "Error, input file couldn't be opened" << endl;
		cout << "Usage : program inputFile outputFile";
		return 0;
	}
	ofstream out;
	out.open(argv[2]);
	if (out.is_open() == 0) {
		cout << "Error, output file couldn't be opened" << endl;
		cout << "Usage : program inputFile outputFile";
		return 0;
	}
	in.close();
	out.close();

	vehicleSimulator x(argv[1], argv[2]);
	Vehicle y;
	x.setInputList();
	vector<Input> temp;
	temp = x.getVector();
	x.setVector(x.sort(&(temp), 0, x.getVector().size()-1));
	if (x.validate() == false) {
		return 0;
	}
	x.writeToFile(x.applyInputs(y));
}
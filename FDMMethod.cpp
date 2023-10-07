#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

class FDMMethod {
public:
	virtual const vector<double> solve(int initialval, int constant, int timestep, int maxtime) = 0;
};

class ForwardDifference : FDMMethod {
public:
	const vector<double> solve (int initialval, int constant, int timestep, int maxtime) {

		vector<double> n;
		n.resize(timestep);
		double dt = 1.0/timestep;
		double i=0;
		double t=0.0;

		n[0]=initialval;

		for (i=0; i<timestep-1; i++) {
			n[i+1] = n[i]*(1-constant*dt);
		}
		
		return n;
	}
};

class CentralDifference : FDMMethod {
public:
	const vector<double> solve (int initialval, int constant, int timestep, int maxtime) {

		vector<double> m;
		m.resize(timestep);
		double dt = 1.0/timestep;
		double i=0;
		double t=0.0;

		m[0]=initialval;
		m[1]=initialval*exp(-constant*dt);

		for (i=1; i<timestep-1; i++) {
			m[i+1] = m[i-1]-2*constant*m[i]*dt;
		}
		
		return m;
	}
};

class BackwardDifference : FDMMethod {
public:
	const vector<double> solve (int initialval, int constant, int timestep, int maxtime) {

		vector<double> p;
		p.resize(timestep);
		double dt = 1.0/timestep;
		double i=0;
		double t=0.0;

		p[0]=initialval;

		for (i=0; i<timestep-1; i++) {
			p[i+1] = p[i]/(1+constant*dt);
		}
		
		return p;
	}
};

void write_csv(string filename, string firstcol, vector<double> firstval, string secondcol, vector<double> secondval, string thirdcol, vector<double> thirdval){

	ofstream myFile(filename);
	
	myFile << firstcol << "," << secondcol << "," << thirdcol << endl;
	for (int i =0; i < firstval.size(); ++i)
	{
		myFile << firstval[i] << "," << secondval[i] << "," << thirdval[i] << endl;
	}
	myFile.close();
}

int main() {
	int initialval = 1;
	int constant = 1;
	int timestep = 100;
	int maxtime = 10;

	ForwardDifference ForwardMethod;	
	CentralDifference CentralMethod;
	BackwardDifference BackwardMethod;

	vector<double> forwardResult = ForwardMethod.solve(initialval, constant, timestep, maxtime);
	cout << "FDSolution:" << endl;
	for (int i=0; i<forwardResult.size(); i++) {
		cout << "n[" << i << "] = " << forwardResult[i] <<endl;
	}

	vector<double> centralResult = CentralMethod.solve(initialval, constant, timestep, maxtime);
	cout << "CDSolution:" << endl;
	for (int i=0; i<centralResult.size(); i++) {
		cout << "m[" << i << "] = " << centralResult[i] <<endl;
	}

	vector<double> backwardResult = BackwardMethod.solve(initialval, constant, timestep, maxtime);
	cout << "BDSolution:" << endl;
	for (int i=0; i<backwardResult.size(); i++) {
		cout << "p[" << i << "] = " << backwardResult[i] <<endl;
	}
	

	write_csv("FDMMethod.csv", "FD", forwardResult, "CD", centralResult, "BD", backwardResult);
	
	return 0;
}

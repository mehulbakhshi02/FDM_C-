#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class FDM {
private:
	double initialval;
	double constant;
	int timestep;
	int maxtime;
	vector<double> n;
	vector<double> N;
	vector<double> E;

public:
	FDM(double n0,
	    double a,
	    int nt=74,
	    int tmax=10)
	: initialval(n0), constant(a), timestep(nt), maxtime(tmax) {
	n.resize(nt);
	N.resize(nt);
	E.resize(nt);}

	void solve() {
			double dt = 1.0/timestep;
			double i=0;
			double t=0.0;

			for (i=0; i<timestep; i++) {
				n[i] = initialval*exp(-constant*t);
				t=t+dt;
			}

			N[0]=initialval;

			for (i=0; i<timestep-1; i++) {
				N[i+1] = N[i]*(1-constant*dt);
			}

			for (i=0; i<timestep; i++) {
				E[i] = n[i]-N[i];
			}
		     }
	const vector<double> getDirectSolution() {
		return n;
	}
	const vector<double> getDiscreteSolution() {
		return N;
	}
	const vector<double> getError() {
		return E;
	}
};

int main() {
	double n0=1.0;
	double a=1.0;
	
	FDM solver(n0, a);
	solver.solve();

	vector<double> dsolution = solver.getDirectSolution();
	cout << "Solution:" << endl;
	for (int i=0; i<dsolution.size(); i++) {
		cout << "n[" << i << "] = " << dsolution[i] <<endl;
	}

	vector<double> Dsolution = solver.getDiscreteSolution();
	cout << "Solution:" << endl;
	for (int i=0; i<Dsolution.size(); i++) {
		cout << "N[" << i << "] = " << Dsolution[i] <<endl;
	}

	vector<double> error = solver.getError();
	cout << "Error:" << endl;
	for (int i=0; i<error.size(); i++) {
		cout << "E[" << i << "] = " << error[i] <<endl;
	}
} 

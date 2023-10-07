#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

class oDHT {
private:
	double length;
	double basetemp;
	int nodes;
	int iterations;
	vector<double> T;

public:
	oDHT(double L,
	     double tb,
	     int N=100,
	     int iter=100)
	: length(L), basetemp(tb), nodes(N), iterations(iter) {
	T.resize(N);}

	void solve() {
			double dx = length/(nodes-1);

			for (int i=0; i<iterations; i++) {
				T[0] = basetemp;
				for (int j=1; j<nodes; j++) {
					T[j]=(T[j+1]+T[j-1])/2;
				}
				T[nodes]=T[nodes-1];
			}
		     }
	const vector<double> getSolution() {
		return T;
	}
};

void write_csv(string filename, string col, vector<double> val){

	ofstream myFile(filename);
	
	myFile << col << endl;
	for (int i =0; i < val.size(); ++i)
	{
		myFile << val[i] <<endl;
	}
	myFile.close();
}

int main() {
	double L=100;
	double tb=100;
	
	oDHT solver(L, tb);
	solver.solve();

	vector<double> solution = solver.getSolution();
	cout << "Temperature:" << endl;
	for (int i=0; i<solution.size(); i++) {
		cout << "T[" << i << "] = " << solution[i] <<endl;
	}
	
	write_csv("1DHT.csv", "Temperature", solution);
} 

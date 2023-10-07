#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class GaussSeidel {
private:
	vector<std::vector<double>> coeffMatrix;
	vector<double> rhsvector;
	vector<double> inisol;
	double tol;
	int asize;

public:
	GaussSeidel(vector<vector<double>> A,
		    vector<double> b,
		    vector<double> x,
		    double maxerr,
		    int n)
	: coeffMatrix(A), rhsvector(b), inisol(x), tol(maxerr), asize(n) {}

	void solve() {
	
		float err1 = numeric_limits<float>::infinity();
		vector<double> x_old(asize, 0.0);

		while (err1>tol){
			for (int i=0; i<asize; i++)
			{
				x_old[i]=inisol[i];
			}
		
			for (int i=0; i<asize; i++){
				double sum =0.0;
				for (int j=0; j<i-1; j++){
					sum = sum+coeffMatrix[i][j]*inisol[j];
				}
				for (int j=i+1; j<asize; j++){
					sum = sum+coeffMatrix[i][j]*x_old[j];
				}
				inisol[i] = (1.0/coeffMatrix[i][i])*(rhsvector[i]-sum);
			}
			
			for (int i=0; i<asize; i++){
				err1=abs(x_old[i]-inisol[i]);
			}
		}
		}

	const vector<double> getSolution() {
		return inisol;
	}
};

int main() {
	vector<vector<double>> A = {{27, 6, -1},
                                    {6, 15, 2},
                                    {1, 1, 54}};

	vector<double> b = {85, 72, 110};
	
	vector<double> x = {0, 0, 0};
	
	double maxerr = 0.001;
	
	int n = 3;

	GaussSeidel solver(A, b, x, maxerr, n);
	solver.solve();

	vector<double> solution = solver.getSolution();

	cout << "Solution:" << endl;
	for (int i=0; i<solution.size(); i++) {
		cout << "x[" << i << "] = " << solution[i] <<endl;
	}

	return 0;
} 

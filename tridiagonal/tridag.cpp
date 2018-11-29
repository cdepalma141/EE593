#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <sstream>


using namespace std;


class Spline {

private:
    class Tridiagonal {
    private:

        vector<double> a, b, c, f, ans;


    public:

        Tridiagonal(vector<double> &a, vector<double> &b, vector<double> &c, vector<double> &f) : a(a), b(b), c(c),
                                                                                                  f(f) {
        }

        // Printing vectors
        void print_vector() {
            cout << endl;
            for (int i = 0; i < ans.size(); i++) {
                cout << setprecision(5) << setw(5) << ans[i] << endl;
            }
            cout << endl;
        }

// Solving tridiagonal matrices
        vector<double> solver() {

            int n = f.size();
            vector<double> x(n);

            for (int i = 1; i < n; i++) {

                double m = a[i - 1] / b[i - 1];
                b[i] -= m * c[i - 1];
                f[i] -= m * f[i - 1];
            }
            // solve for last x value
            x[n - 1] = f[n - 1] / b[n - 1];

            // solve for remaining x values by back substitution
            for (int i = n - 2; i >= 0; i--)
                x[i] = (f[i] - c[i] * x[i + 1]) / b[i];

            for (int i = 0; i < x.size(); i++)
                ans.push_back(x[i]);

            return x;



        }
    };


    double* x;
    double* y;

    vector<double> A;
    vector<double> B;
    Tridiagonal *T;
    vector<double> ans;
    int n;

public:
    Spline(int n, const string & s): n(n), x(new double[n]), y(new double[n]) {

        read(s);


        vector<double> a, b, c, f;

        for(int i = 0; i < n; i++){
            if(i == 0){
                b.push_back(2.0/(x[i+1]-x[i]));
                f.push_back(3*((y[i+1]-y[i])/pow((x[i+1]-x[i]),2)));
            }
            else if(i == n-1){
                b.push_back(2.0/(x[i] -x[i-1]));
                f.push_back(3*((y[i]-y[i-1])/pow((x[i]-x[i-1]),2)));
            }
            else {
                b.push_back(2*((1/(x[i]-x[i-1]))+(1/(x[i+1] - x[i]))));
                f.push_back(3*(((y[i]-y[i-1])/pow((x[i]-x[i-1]),2))+((y[i+1]-y[i])/pow((x[i+1]-x[i]),2))));
            }
        }

        for(int i = 0; i < n-1; i++){
            a.push_back(1.0/(x[i+1]-x[i]));
            c.push_back(1.0/(x[i+1]-x[i]));

        }


        cout << "Lower Diagonal\t\t\tMain Diagonal\t\t\tUpper Diagonal\t\t\t\tß\n\n";

        for(int i = 0; i < n; i++){
            if(i != n-1)
                cout << setprecision(5) << a[i] << setw(30) <<  b[i] << setw(25) << c[i] << setw(20) << f[i] << '\n';
            else
            cout << setprecision(5) << setw(34) <<  b[i]  << setw(44) << f[i]<< "\n";
        }
        T = new Tridiagonal(a, b, c, f);
    }

    void printans() {
        ans = T->solver();
        T->print_vector();
    }

    void makecoeff() {

        for(int i = 0; i < n-1; i ++){
           A.push_back(ans[i]*(x[i+1] - x[i])-(y[i+1]-y[i]));
           B.push_back(-1*ans[i+1]*(x[i+1] - x[i])+(y[i+1]-y[i]));
        }

        for(int i = 0 ; i < n-1; i++)
            cout << A[i] << '\t' << B[i] << '\n';

        cout << "\n\n\n";




    }

    void makeCubics() {

        for(int i = 1; i < n; i++) {
            cout << "\n\nSegment " << i << ": \n\n";

            for (double t = 0; t <= 1.0; t += 0.1){
                double val = (1-t)*y[i-1] + t*y[i] + t*(1-t)*(A[i-1]*(1-t)+(B[i-1]*t));
                cout << val << '\n';

            }


        }


        ofstream file;
        file.open("/Users/connordepalma/CLionProjects/tridiagonal/test.csv");

        cout << "\n\n\n";

        for(int i = 1; i < n; i++) {
                for (double t = x[i-1]; t < x[i]; t += 0.1) {
                    double X = (t - x[i - 1]) / (x[i] - x[i - 1]);
                    double val = (1 - X) * y[i - 1] + X * y[i] + X * (1 - X) * (A[i - 1] * (1 - X) + (B[i - 1] * X));
                    file << "0,\t\t\t\t" << t << ",\t\t\t\t" << val << '\n';

                }
        }

        file << "done";

        file.close();


    }

    void read (const string& s) {
        ifstream in(s);
        string line;
        int ct = 0;
        while(getline(in, line)){
            if(line.length() != 0){
                istringstream ls(line);
                double X;
                double Y;
                ls >> X >> Y;
                x[ct] = X;
                y[ct] = Y;


            }
            ct ++;
        }

        for(int i = 0; i < n; i ++)
            cout << x[i] << '\t' << y[i] << '\n';
    }



};



int main(){




    Spline S(4, "/Users/connordepalma/CLionProjects/tridiagonal/hw9.dat");

    S.printans();

    S.makecoeff();

    S.makeCubics();


}
 

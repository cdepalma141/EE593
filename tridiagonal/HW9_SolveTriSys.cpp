/*
 *  HW9 - SolveTridiagonal system
 *  Connor DePalma.
 *  I pledge my honor that I have abided by the Stevens Honor System.
 *
 */


#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <sstream>


using namespace std;
/*
 * IMPORTANT:
 * The format of the hw9.dat file should be as follows for this program:
 * EX:
 * 5 (number of segments)
 * 0 0
 * 2 3
 * 4 5
 * ...
 *
 * This will NOT work if the first number is not the number of segments. This based off of the splinehw.dat file
 * in the github.
 *
 * The following sources were used to assist in this assignment:
 *
 * https://en.m.wikipedia.org/wiki/Spline_interpolation#math_9  -> for the cubic equation
 * The wolfram example was harder to follow compared to this, and with this equation I was
 * able to also generate the full spline and not just the parametric segments between each point.
 * A tridiagonal matrix was still required to use this formula successfully. This does NOT contain
 * c++ code.
 *
 *
 * https://hnagib.com/portfolio/tridiagonal-solver/ -> c++ example for tridiagonal matrices
 * used to help create the tridiagonal matrix solver. There wasn't much to improve/change in this
 * since it is rather simple to solve the matrix other than altering it into a class structure.
 *
 *
 * The output should explain what values are being created.
 *
 * YOU CAN MAKE A GRAPH!
 * I added csv generation for the parametric segments (segments.csv) as well as the
 * full cubic spline (cubicspline.csv). The files should be created in your current directory.
 *
 * If you open the file in a spreadsheet application (Excel, Numbers, Google Sheets, etc.)
 * you should be able to just select the values (excluding the 0s used as a buffer on the left)
 * and create a scatter plot to view the curves!!  The x axis values are the first column on nonzeroes
 * and the y axis values are all other nonzero columns.
 *
 * uncomment the makeCSV method call in main to do this!!!
 *
 */

class Spline {

private:
    class Tridiagonal {
    private:

        vector<double> a, b, c, f, ans;


    public:

        Tridiagonal(vector<double> &a, vector<double> &b, vector<double> &c, vector<double> &f) : a(a), b(b), c(c), f(f) {}

//        void print_vector() {
//            cout << endl;
//            for (int i = 0; i < ans.size(); i++) {
//                cout << setprecision(5) << setw(5) << ans[i] << endl;
//            }
//            cout << endl;
//        }

        vector<double> solver() {

            int n = f.size();
            vector<double> x(n);

            for (int i = 1; i < n; i++) {

                double m = a[i - 1] / b[i - 1];
                b[i] -= m * c[i - 1];
                f[i] -= m * f[i - 1];
            }
            x[n - 1] = f[n - 1] / b[n - 1];

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
    double** values;

public:
    Spline(const string & s)  {

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

        cout << "Tridiagonal Matrix Values: \n\n";

        cout << "Lower Diagonal\t\t\tMain Diagonal\t\t\tUpper Diagonal\t\t\t\tß\n\n";

        for(int i = 0; i < n; i++){
            if(i != n-1)
                cout << setprecision(5) << a[i] << setw(30) <<  b[i] << setw(25) << c[i] << setw(20) << f[i] << '\n';
            else
            cout << setprecision(5) << setw(34) <<  b[i]  << setw(44) << f[i]<< "\n";
        }

        cout << "\n\n\n";

        T = new Tridiagonal(a, b, c, f);

        //display matrix

        cout << "Matrix:\n\n";

        double* tri = new double[n*n];
        int ctA = 0;
        int ctB = 0;
        int ctC = 0;
        int ctF = 0;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j< n; j++) {
                if (i == j)
                    tri[i * n + j] = b[ctB++];
                if (i == j + 1)
                    tri[i * n + j] = a[ctA++];
                if (j == i + 1)
                    tri[i * n + j] = c[ctC++];
            }
        }

        for(int i = 1; i <= n*n; i ++){
            if ((i-1)%n == 0 && (i-1) != 0)
                cout << '\t' << f[ctF++] <<'\n';
            cout << tri[i-1] << setw(8);
        }
        cout << '\t' << f[ctF++] <<"\n\n\n";

    }

    void getVec() {
        ans = T->solver();
       // T->print_vector();
    }

    void makecoeff() {

        for(int i = 0; i < n-1; i ++){
           A.push_back(ans[i]*(x[i+1] - x[i])-(y[i+1]-y[i]));
           B.push_back(-1*ans[i+1]*(x[i+1] - x[i])+(y[i+1]-y[i]));
        }

        cout << "\n\n\n";




    }

    void makeCubics() {

        values = new double*[n-1];

        for (int i = 0; i < n-1; i++){
            values[i] = new double[10];
        }

        for(int i = 1; i < n; i++) {
            cout << "\n\nSegment " << i << ": \n\n";
            int ct = 0;
            for (double t = 0; t <= 0.9; t += 0.1){
                double val = (1-t)*y[i-1] + t*y[i] + t*(1-t)*(A[i-1]*(1-t)+(B[i-1]*t));
                cout << val << '\n';
                values[i-1][ct++] = val;

            }


        }


    }

    void makeCSVs (){
        //make csv for parametric curves of each segment
        ofstream Tfile;
        Tfile.open("segments.csv",fstream::out);
        Tfile << "0\n";
        for(int t = 0; t < 10; t ++){
            Tfile << "0," << t/10.0;
            for (int i = 1; i < n; i++){
                Tfile << "," << values[i-1][t];
            }
            Tfile << '\n';
        }

        Tfile.close();

        //make csv for full cubic spline
        ofstream file;
        file.open("cubicspline.csv",fstream::out);

        cout << "\n\n\n";
        file << "0\n";
        for(int i = 1; i < n; i++) {
            for (double t = x[i-1]; t < x[i]; t += 0.1) {
                double X = (t - x[i - 1]) / (x[i] - x[i - 1]);
                double val = (1 - X) * y[i - 1] + X * y[i] + X * (1 - X) * (A[i - 1] * (1 - X) + (B[i - 1] * X));
                file << "0," << t << "," << val << '\n';

            }
        }

        file.close();
    }

    void read (const string& s) {
        ifstream in(s);
        string line;
        int ct = 0;
        int check = 0;
        while(getline(in, line)){
            if(line.length() != 0){
                istringstream ls(line);
                double X;
                double Y;

                ls >> X >> Y;
                if(check == 0) {
                    n = int(X) + 1;
                    x = new double[n];
                    y = new double[n];
                    check ++;
                }
                else {
                    x[ct] = X;
                    y[ct++] = Y;
                }


            }

        }
    }



};



int main(){


    Spline S("hw9.dat");
    //reads file and creates tridiagonal system of equations

    S.getVec();  //gets K values from tridiagonal matrix;

    S.makecoeff(); //makes A and B coefficients for the cubic equations

    S.makeCubics(); //gets point values from equations and outputs x(t) values for each segment

    S.makeCSVs(); //enable if you want to generate csv files to view the charts as described at the beginning


}
 

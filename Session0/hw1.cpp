//
// Created by Connor DePalma on 8/30/18.
//

#include <iostream>
#include <iomanip>
using namespace std;

/**
	 Make sure your choose function works for test data

                  1
                1   1
              1   2   1
            1   3   3   1
          1   4   6   4   1
        1   5   10  10  5   1
      1   6   15  20  15  6   1

 */

//nCr = n!/(r!(n-r)!)
//52C6 = 52!/6!(46!) = divide by the large fact  n! is O(n)
//worst case is n/2

// make your code work here
double choose(double n, double r){

    double a;
    double d;

    if (n >= r) {
        if (n - r < r && n != r) {
            a = r;
            d = n - r;
            for (int i = n - r - 1; i > 1; i--)
                d *= i;
        } else if (n == r) {
        d = n;
        a = n - 1;
        }
        else {
            a = (n - r);
            d = r;
            for (int i = r - 1; i > 1; i--)
                d *= i;
        }

    }

    else {
        cout <<  "r should not be greater than n";
        return 0;
    }


    for (int i = n-1; i > a; i--){
        n *= i;
    }

    if (d == 0)
        d = 1;
    
    if (n == 0)
        n = 1;

    return n/d;

}

int main() {
	int testCases[][3] = {
		{0, 0, 1},
		
		{1, 0, 1},
		{1, 1, 1},

		{2, 0, 2},
		{2, 1, 2},
		{2, 2, 1},
		
		{5, 0, 5},
		{5, 1, 5},
		{5, 2, 10},

		{6, 3, 20}
	};
	const int numTestCases = 10;
	
	for (int i = 0; i < numTestCases; i++) {
		int n = testCases[i][0];
		int r = testCases[i][1];
		int result = testCases[i][2];
		if (choose(n, r) != result) {
			cerr << "Failed test case: choose(" << n << ", " << r << ") = " << result << '\n';
		}
	}

	cout << "Large number tests\n";
	cout << setprecision(15);
	cout << choose(52, 6) << "\n";
	cout << choose(52, 26) << "\n";
	cout << choose(150, 5) << "\n";
}
// int main(){
//     double n, r;
//     cout << "Enter n and r: \n";
//     cin >> n;
//     cin >> r;
//     cout << choose(n,r) << '\n';

//     //cout << choose(n,r) << '\n'; //nCr // O(n)

//     //n<500 r<n ,
//     //choose (52,10), (52,15) , (52

// }

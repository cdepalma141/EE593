

#include <iostream>
#include <random>
#include <iomanip>

using namespace std;
// 6.5 seconds for choose just returning 0

extern double nCr[][3];
//19.7 seconds for 100 mil trials without memoization
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
            d = ((r == 0)? n : r);
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
    if (d == 0){
        d = 1;

    }
    if (n == 0)
        n = 1;
    
    
    return n/d;

}

int main() {
  int numTrials = 100000000;
	//  cin >> numTrials;
	default_random_engine generator;
	uniform_int_distribution<int> distribution(0,500);	

  for (int i = 0; i < numTrials; i++) {
		int n = distribution(generator);
		uniform_int_distribution<int> rdist(0,n);	
		int r = rdist(generator);
    choose(n,r);
	}
}


#include <iostream>
#include <random>
#include <iomanip>

using namespace std;
// 6.5 seconds for choose just returning 0
//19.7 seconds for 100 mil trials without memoization & non-recursively
//7.14 seconds for 100 mil trials with memoization and recursive
double choose(int n, int r){
    static double nCr[501][501] = {0};


    if (r == 1 || r == n-1)
        return  nCr[n][r] = n;

    if (n == 0)
        return nCr[n][r] = 1;

    if (r == 0)
        return nCr[n][r] = 1;

    if (n==r)
        return nCr[n][r] = 1;

    if (nCr[n][r] != 0) {
        return nCr[n][r];
    }

    return nCr[n][r] = choose(n-1,r) + choose(n-1,r-1); //based off of fibonacci pattern

//return 0;

}
int main() {
  int numTrials = 100000000;
	//  cin >> numTrials;
	default_random_engine generator;
	uniform_int_distribution<int> distribution(0,500);	

  for (int i = 0; i < numTrials; i++) {
		int n = distribution(generator);
		//cout << n << '\n';
		uniform_int_distribution<int> rdist(0,n);	
		int r = rdist(generator);
		//cout << r << '\n';
    choose(n,r);
	}
}
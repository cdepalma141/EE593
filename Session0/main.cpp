#include <iostream>
using namespace std;



//1,1,2,3,5,8...
int fibo(int n){ //O(n)

    int a =1,b =1,c=0; //O(1)
    for (int i = 1; i <= n; i++){ //(O(n)
        b = a+b; //O(1)
        a=b;//O(1)
        b=c;//O(1)
    }
    return c;

}


int main() { //O(m*n)
    const int m =14;
    for(int i=1; i<= m; i++) //O(m)
    cout << i << '\t' << fibo(i)<< '\n';


}
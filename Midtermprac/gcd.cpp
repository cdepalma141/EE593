//
// Created by Connor DePalma on 10/15/18.
//

#include <iostream>

using namespace std;
int gcd (int a, int b) {

   if (b == 0)
       return a;
   return gcd(b, a%b);

}

int lcm(int a , int b){


    return (a * b)/gcd(a,b);
}

int main(){
    cout << gcd(18 , 12) << '\n';
    cout << lcm(12,18);
}


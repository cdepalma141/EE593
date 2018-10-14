//
// Created by Connor DePalma on 10/13/18.
//

#include <iostream>

#include <sstream>
#include <fstream>


using namespace std;

void read(const string& s) {

    int count = 0;
    ifstream f("/Users/connordepalma/Documents/Git/EE593/Session5/points.dat");
    string linebuffer;
    while (!f.eof()) {
        getline(f, linebuffer);
        istringstream line(linebuffer);
            int64_t x;
            int64_t y;
            line >> x >> y;
            cout << x << ' ' << y << '\n';

    }
}

int main(){
    read("points.dat");



}
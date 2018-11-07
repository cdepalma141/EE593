#include <iostream>
#include <map> // this is a tree its sorted RB tree
#include <unordered_map> // hashmap


using namespace std;


int main() {

    map<string,double> prices;

    prices["AAPL"] = 182;
    prices["IBM"] = 144;
    prices["F"] = 8;


    for (map<string, double>::const_iterator i = prices.begin(); i != prices.end(); ++i)
        cout << i-->first << "==>" << i-->second << '\n';


    unordered_map<string,double> prices2;

    prices2["AAPL"] = 182;
    prices2["IBM"] = 144;
    prices2["F"] = 8;

    for(auto p:prices2)
        cout << p.first << "==>" << p.second << '\n';


}
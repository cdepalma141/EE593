//
// Created by Connor DePalma on 11/3/18.
//

#include <iostream>
#include <string>

using namespace std;

const string EMPTY = "";

class Hashmaplinear {
private:

    class Bucket {
    public:
        string key;
        double value;
        Bucket() : key() {}


    };

    Bucket* table;

    uint32_t size;
    uint32_t used;

    uint32_t hash (const string& key) {
        uint32_t sum = key.length();
        for (int i = 0; i < key.length(); ++i){
            sum  = (sum << 5) + (sum >> 17) + key[i];
        }

        return sum & (size-1);
    }

    void grow() {
        Bucket* old = table;
        table = new Bucket[size*=2];
        for (int i = 0; i < used; i++){
            if(old[i].key != EMPTY)
                table[hash(old[i].key)] = old[i];
        }

        delete [] old;
    }

public:
    Hashmaplinear(uint32_t initialsize = 1024) : size(initialsize), used(0), table(new Bucket[initialsize]) {}

    ~Hashmaplinear() {
        delete [] table;
    }

    Hashmaplinear(const Hashmaplinear& orig) : size(orig.size), used(orig.used) {
        table = new Bucket[size];

        for(int i = 0; i < size; i++){
            if(orig.table[i].key != EMPTY)
                table[i]=orig.table[i];
        }
    }

//    Hashmaplinear& operator =(const Hashmaplinear& orig) {
//        Hashmaplinear copy(orig);
//        size = copy.size;
//        used = copy.used;
//        swap(table, copy.table);
//        return *this;
//    }

    double& operator [](const string& key) {

        uint32_t pos = hash(key);

        while(table[pos].key != EMPTY){
            if(table[pos].key == key)
                return table[pos].value;
            pos = (pos + 1) & (size - 1);

        }
        used ++;
        if (used *1.3 > size) {
            grow();
        }
        return table[pos].value;

    }




};

int main() {

    Hashmaplinear stockQuotes(1024); // MUST BE POWER OF 2

    stockQuotes["AAPL"] = 170.5;
    stockQuotes["aapl"] =  142;
    stockQuotes["BIDU"] = 188.2;
    Hashmaplinear stockQuotes2 = stockQuotes;

    cout << stockQuotes["AAPL"] << '\n';
    cout << stockQuotes["BIDU"] << "\n";
    cout << stockQuotes["aapl"] << "\n";
    cout << stockQuotes["fsd"] << "\n";

    //stockQuotes2 = stockQuotes;
    //	stockQuotes2 = stockQuotes2;

}
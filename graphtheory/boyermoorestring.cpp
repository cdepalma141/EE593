#include <iostream>


using namespace std;

// BoyerMoore(search, target)
// for i =0 to 255
// 	table[i] = k
// for i = 0 to k
// 	table[target[i]] = k - i - 1
// i = k-1
// while (i < n)
// 	jump ← table[search[i]]
// 	if (jump == 0) { // possible match
// 		// compare the word letter by letter

// 	}
// 	i ← i + jump
// end

bool BoyerMoore(string search, string target) {
    int table[256];
    for (int i = 0; i < 256; i++){
        table[i] = target.length();
    }
    int remaining = target.length() - 1;
    for (int i =  1; i < target.length(); i++) {
        table[target[i]] = remaining--;
    }
    bool found = false;
    int jump;
    int k, j;
    for(int pos = target.length() - 2; pos < search.length(); pos += jump){
        jump = table[search[pos]];
        if(jump == 0){
            for(j = target.length()-1, k = pos - 1; j >= 0; j--, k--){
                if(search[k] != target[j]){
                    jump = table[search[k]];
                    found = true;
                    break;

                }
            }


        }


    }

    return found;
}


int main() {

    string a = "klmkmkmlkmoelloasdfasdfasdf";
    string b = "oello";

    cout << BoyerMoore(a, b);

}
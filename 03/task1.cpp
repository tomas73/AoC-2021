#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;
int main(void)
{
    string input = "input";
    ifstream in;
    in.open(input);
    if (!in.good()) {
        cout << "Bad input" << endl;
        exit(1);
    }

    string val_as_string;
    int hist[12];
    int count = 0;
    memset(hist, 0, sizeof(int));
    while (in >> val_as_string) {
        count++;
        bitset<12> val(val_as_string);
        for (int i = 0; i < 12; i++) {
            if (val[i]) {
               hist[i]++ ;
            }
        }
    };
    bitset<12> gamma_rate;
    bitset<12> epsilon_rate;
    gamma_rate.reset();
    epsilon_rate.reset();

    for (int i = 0; i < 12; i++) {
        if (hist[i] > (count / 2)) {
            gamma_rate.set(i, true);
        } else {
            epsilon_rate.set(i, true);
        }
    }
    cout << gamma_rate << endl;
    cout << epsilon_rate << endl;
    
    int gr = gamma_rate.to_ullong();
    int er = epsilon_rate.to_ullong();
    cout << "Result = " << gr * er << endl;
    return 0;
}

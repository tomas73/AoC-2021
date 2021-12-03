#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;

int count_bitpos(vector<bitset<12>> v, int pos)
{
    int num_ones = 0;

    for (auto it=v.begin(); it!=v.end(); it++) {
        bitset<12> val = *it;
        if (val[pos]) num_ones++;
    }
    return num_ones;
}

void filter_report(int pos, int criteria, vector<bitset<12>> &v)
{
    int num_tot = v.size();
    int num_ones = count_bitpos(v, pos);
    int num_zeros = num_tot - num_ones;
    bool keep_ones = false;

//    cout << "ones = " << num_ones << " zeros = " << num_zeros << endl;
    if (criteria == 1) {
        keep_ones = (num_ones >= num_zeros) ? true:false;
    } else {
        keep_ones = (num_ones >= num_zeros) ? false:true;
    }
//    cout << "Keep " << ((keep_ones == true) ? "Ones":"Zeros") << " in pos " << pos << endl;

    int cnt=0;
    for (auto it=v.begin(); it!=v.end(); /* Increase iterator only if not removed */) {
        bitset<12> val = *it;
        bool erase_it = false;
        if (val[pos]) {
            if (!keep_ones) {
                erase_it=true;
            }
        } else {
            if (keep_ones) {
                erase_it=true;
            }
        }
        if (erase_it) {
            v.erase(it);
        } else {
            ++it;
        }
    }
}

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
    vector<bitset<12>> original_report;
    while (in >> val_as_string) {
        bitset<12> val(val_as_string);
        original_report.push_back(val);
    };

    vector<bitset<12>> oxygen_report = original_report;
    vector<bitset<12>> co2_report = original_report;

    int pos = 11;
    while (oxygen_report.size() > 1) {
        filter_report(pos--, 1, oxygen_report);
    };
   
    bitset<12> val=*(oxygen_report.begin());
    int oxy= val.to_ullong(); 
    cout << "Oxy: " << oxy << endl;
    pos = 11;
    while (co2_report.size() > 1) {
        filter_report(pos--, 0, co2_report);
    };
    val=*(co2_report.begin());
    int co2= val.to_ullong(); 
    cout << "CO2: " << co2 << endl;

    cout << "Result = " << oxy * co2 << endl;
    return 0;
}

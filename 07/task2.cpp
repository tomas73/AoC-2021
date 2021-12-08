#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;

vector<int> positions;

int cost(int pos, int dest)
{
    int dist=abs(pos-dest);

    int c=0;
    for (int i = 1; i <= dist; i++) {
        c+=i;
    }
    return c;
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

    int i;
    while (in >> i) {
        positions.push_back(i);
        char c;
        in >> c;
    };
    cout << "Num=" << positions.size() << endl; 
    int max_val=0;
    int min_val=100000;
    for (auto it = positions.begin(); it != positions.end(); ++it) {
        if (*it > max_val) max_val=*it;
        if (*it < min_val) min_val=*it;
    }
    cout << "Min = " << min_val << " Max = " << max_val << endl; 
    int least_fuel=1000000000;
    for (int i = min_val; i <= max_val; i++) {
        int sum = 0;
        for (auto it = positions.begin(); it != positions.end(); ++it) {
            sum += cost(*it, i);
        }
        if (sum < least_fuel) least_fuel=sum;
    }
    cout << "Least fuel = " << least_fuel << endl;
    return 0;
}

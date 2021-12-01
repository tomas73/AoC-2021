#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;
int main(void)
{
    string input = "input";
    ifstream in;
    
    int depth=INT_MAX;
    int sum;
    int last_sum=INT_MAX;
    int current = 10000;
    int last1 = 10000;
    int last2 = 10000;
    int num_increase=0;
    in.open(input);
    while (in >> depth) {
        sum = (last2 + last1 + depth);
        if (sum > last_sum) num_increase++;
        last_sum = sum;
        last2 = last1;
        last1 = depth;
    };
    cout << "Num Increase = " << num_increase << endl;
    return 0;
}

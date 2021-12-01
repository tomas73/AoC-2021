#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;
int main(void)
{
    string input = "input";
    ifstream in;
    
    int depth=INT_MAX;
    int last_depth=INT_MAX;
    int num_increase=0;
    in.open(input);
    while (in >> depth) {
        if (depth > last_depth) num_increase++;
        last_depth = depth;
    };
    cout << "Num Increase = " << num_increase << endl;
    return 0;
}

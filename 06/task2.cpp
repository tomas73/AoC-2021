#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;

unsigned long fishes[10];

void printFishes(void)
{
    cout << "print" << endl;
    unsigned long sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += fishes[i];
        cout << "Num " << i << " " << fishes[i] << endl;
    }
    cout << "Sum = " << sum << endl;
}

void handleDay(void)
{
    unsigned long bup[10];
    memcpy(bup, fishes, 10);

    fishes[0] = fishes[1];
    fishes[1] = fishes[2];
    fishes[2] = fishes[3];
    fishes[3] = fishes[4];
    fishes[4] = fishes[5];
    fishes[5] = fishes[6];
    fishes[6] = fishes[7];
    fishes[7] = fishes[8];

    fishes[6] += bup[0];
    fishes[8] = bup[0];
    printFishes();
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
        int *pInt;
        cout << "i=" << i << endl;
        fishes[i]++;
        
        char c;
        in >> c;
    };

    printFishes();
    
    for (int i = 0; i < 256; i++) {
        handleDay();
    }
    return 0;
}

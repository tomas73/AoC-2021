#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;

int field[1000][1000];


int main(void)
{
    memset(field, 0, sizeof(field));
    string input = "input";
    ifstream in;
    in.open(input);
    if (!in.good()) {
        cout << "Bad input" << endl;
        exit(1);
    }

    int x1,x2,y1,y2;
    char c;
    while (in >> x1 >> c >> y1 >> c >> c >> x2 >> c >> y2) {

        if (x1 == x2 || y1 == y2) {
            cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
            if (x1 == x2) {
                int start=y1;
                int stop=y2;
                if (y1 > y2) {
                    start = y2;
                    stop = y1;
                }
                for (int i = start; i <= stop; i++) {
                    field[i][x1]++;
                } 
            }
            if (y1 == y2) {
                int start=x1;
                int stop=x2;
                if (x1 > x2) {
                    start = x2;
                    stop = x1;
                }
                for (int i = start; i <= stop; i++) {
                    field[y1][i]++;
                } 
            }
        }
    }; 
    int sum = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (field[i][j] >= 2) sum++;
        }
    }
    cout << "Res = " << sum << endl;
    return 0;
}

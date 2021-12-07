#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;

vector<int> number_sequence;

typedef vector<vector<pair<int,bool>>> pad;
vector<pad> pads;

int handleBingo(pad &p, int num)
{
    int res=0;
    int sum_unmarked = 0; 
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (p[r][c].second == false) {
                sum_unmarked += p[r][c].first;
            }
        }
    }
    return (num*sum_unmarked);
}

bool markNumber(pad &p, int num)
{
    bool res=false;
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (p[r][c].first == num) {
                p[r][c].second=true;
                return true;
            }
        }
    }
    return false;
}

bool hasBingo(pad p)
{
    bool res=false;
    for (int r = 0; r < 5; r++) {
        bool bingo=true;
        for (int c = 0; c < 5; c++) {
            if (p[r][c].second == false) bingo=false;
        }
        if (bingo) return true;
    }
    for (int c = 0; c < 5; c++) {
        bool bingo=true;
        for (int r = 0; r < 5; r++) {
            if (p[r][c].second == false) bingo=false;
        }
        if (bingo) return true;
    }
    return false;
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

    string s;
    getline(in, s);

    stringstream ss(s);
    int i;
    char c;
    while (ss >> i) {
        number_sequence.push_back(i);
        ss >> c;
    };

    while (in.peek() != EOF) {
        pad p;
        pair<int,bool> n;
        for (int r = 0; r < 5; r++) {
            vector<pair<int,bool>> vc;
            for (int c = 0; c < 5; c++) {
                in >> i;
                n.first=i;
                n.second=false;
                vc.push_back(n);
            }
            p.push_back(vc);
        }
        pads.push_back(p);
    }; 

    for (auto its = number_sequence.begin(); its!=number_sequence.end(); its++) {
        int current_number=*its;
        for (auto itp = pads.begin(); itp != pads.end(); itp++) {
            if (markNumber(*itp, current_number)) {
                if (hasBingo(*itp)) {
                    cout << "Score = " << handleBingo(*itp, current_number) << endl;
                    exit(0);
                }
            }
        }
    }

    cout << "Num Pads = " << pads.size() << endl;
    return 0;
}

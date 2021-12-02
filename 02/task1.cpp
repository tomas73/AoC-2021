#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;
void go_direction(pair<int,int> &position, string direction, int amount)
{
    if (direction.compare("forward") == 0)
    {
        position.first += amount;
    }
    if (direction.compare("down") == 0)
    {
        position.second += amount;
    }
    if (direction.compare("up") == 0)
    {
        position.second -= amount;
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


    int amount;
    string direction;
    pair<int,int> position(0,0);
    while (in >> direction >> amount) {
        go_direction(position, direction, amount);
    };
    cout << "Result = " << position.first * position.second << endl;
    return 0;
}

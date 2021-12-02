#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;

typedef struct {
    int horizontal;
    int depth;
    int aim;
}state; 


void go_direction(state &position, string direction, int amount)
{
    if (direction.compare("forward") == 0)
    {
        position.horizontal += amount;
        position.depth += (position.aim * amount);
    }
    if (direction.compare("down") == 0)
    {
        position.aim += amount;
    }
    if (direction.compare("up") == 0)
    {
        position.aim -= amount;
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
    state position={0,0,0};
    while (in >> direction >> amount) {
        go_direction(position, direction, amount);
    };
    cout << "Result = " << position.horizontal * position.depth << endl;
    return 0;
}

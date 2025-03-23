#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<string>
#include<time.h>
#include<stdlib.h>

using namespace std;

#include "Village.h"

vector<vector<char>> area;

int main() {

    srand(time(NULL));

    //Settings:
    int numberOfPlayers = 2;
    vector<string> colors {"red", "blue", "green", "yellow"};
    bool gameOver = false;
    int turn = 0;
    //End Of Settings

    for (int i=0;i<numberOfPlayers;++i) {

        pair<int, int> capital (rand()%10, rand()%10);
        vector<House> houses {};
        vector<Warrior> warriors {};

        villages.push_back(Village(capital, houses, warriors, colors[i]));

    }

    while (!gameOver) {

        if (turn == numberOfPlayers) {

            turn = 0;

        }

        string command;
        bool haveCommand = false;

        while (!haveCommand) {

            cin >> command;

            int coordinateX, coordinateY;

            if (command == "warrior") {

                    haveCommand = true;

                    cin >> coordinateX >> coordinateY;

                    pair<int, int> position (coordinateX, coordinateY);

                    villages[turn].warriors.push_back(Warrior(position));

            } else if (command == "house") { // are beeeeeee
                                            // muhul
                    haveCommand = true;

                    cin >> coordinateX >> coordinateY;

                    pair<int, int> position (coordinateX, coordinateY);

                    villages[turn].houses.push_back(House(position));

            } else if (command == "move") {

                    haveCommand = true;

                    cin >> coordinateX >> coordinateY;

                    pair<int, int> positionOfWarrior (coordinateX, coordinateY);

                    cout << "Position to move: ";

                    int coordinateXToChange, coordinateYToChange;

                    cin >> coordinateXToChange >> coordinateYToChange;

                    pair<int, int> positionToChange (coordinateXToChange, coordinateYToChange);

                    villages[turn].warriors[getIdOfWarrior(villages[turn], positionOfWarrior)].moveWarrior(positionToChange);

            } else {

                cout << "Invalid command. Please try again!";

            }

        }

        turn++;

        stats();

    }

    return 0;

}

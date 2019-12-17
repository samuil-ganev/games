#include<iostream>
#include<vector>
#include<utility>
#include<string>

using namespace std;

class Warrior {

    public:

    pair<int, int> position;
    int level;

    Warrior (pair<int, int> position, int level=1) :
        position(position),
        level(level) {}

    void killWarrior(vector<Warrior> &warriors) {

        vector<Warrior> newWarriors;

        for (Warrior &warrior : warriors) {

            if (!(warrior.position.first == this->position.first &&
                warrior.position.second == this->position.second)) {

                newWarriors.push_back(warrior);

            }

        }

        warriors = newWarriors;

    }

    void upgradeWarrior(vector<Warrior> &warriors, Warrior &warrior) {

        if (warrior.level + this->level < 5) {

            this->level += warrior.level;

            warrior.killWarrior(warriors);

        } else {

            cout << "Error: Can't upgrade warrior!";

        }

    }

    void moveWarrior(pair<int, int> position) {

        // #TODO

    }

};

class House {

    public:

    pair<int, int> position;
    int goldPerTurn;

    House(pair<int, int> position, int goldPerTurn = 2) :
        position(position),
        goldPerTurn(goldPerTurn) {}

};

class Village {

    public:

    pair<int, int> capital;
    int gold;
    vector<House> houses;
    vector<Warrior> warriors;
    string color;
    int numberOfFields;

    Village (pair<int, int> capital, vector<House> houses, vector<Warrior> warriors, string color, int gold=5, int numberOfFields = 3) :
        capital(capital),
        houses(houses),
        warriors(warriors),
        color(color),
        gold(gold),
        numberOfFields(numberOfFields) {}

    void addCash() {

        int cashFromHouses = 0;

        for (House &house : houses) {

            cashFromHouses += house.goldPerTurn;

        }

        this->gold += numberOfFields + cashFromHouses;

    }

    void buildHouse(int coordinateX, int coordinateY) {

        pair<int, int> coordinates (coordinateX, coordinateY);

        houses.push_back(House(coordinates));

    }

};

int getIdOfWarrior(Village &village, pair<int, int> &positionOfWarrior) {

    int id = 0;

    size_t SIZE = village.warriors.size();

    for (size_t i=0;i<SIZE;++i) {

        if (village.warriors[id].position.first == positionOfWarrior.first &&
            village.warriors[id].position.second == positionOfWarrior.second) {

            return id;

        }

        id++;

    }

    return -1;

}

vector<Village> villages;

void stats() {

    int id = 0;

    for (Village &village : villages) {

        cout << "Player " << id + 1 << ": \n";
        cout << "Gold: " << village.gold << endl;
        cout << "Warriors: \n";

        for (Warrior warrior : village.warriors) {

            cout << " Positions: " << warrior.position.first << " " << warrior.position.second << endl;
            cout << " Level: " << warrior.level << endl;

        }

        cout << "Number Of Houses: " << village.houses.size() << endl;

        id++;

    }

}

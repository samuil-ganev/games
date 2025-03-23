//Creator: Samuil Ganev
//TicTacToe game with C++
#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<ctime>
using namespace std;

vector<int> makeRandomNumbers() {
    vector<int> numbers;
    srand(time(NULL));
    while (numbers.size() != 2) {
        int number = rand() % 3;
        numbers.push_back(number);
    }
    return numbers;
}
// comment
vector<int> makeRandomPositions(const vector<vector<int>> &elements) {
    vector<int> positions;
    while (positions.size() == 0) {
        vector<int> numbers = makeRandomNumbers();
        if (elements[numbers[0]][numbers[1]] != 0 && elements[numbers[0]][numbers[1]] != 1) {
            positions.push_back(numbers[0]);
            positions.push_back(numbers[1]);
        }
    }
    return positions;
}

vector<vector<int>> convertVector(const vector<vector<int>> &elements) {
    int ch = 2;
    vector<vector<int>> converted;
    for (int i=0;i<3;++i) {
        vector<int> line;
        for (int j=0;j<3;++j) {
            line.push_back(0);
        }
        converted.push_back(line);
    }
    for (int i=0;i<3;++i) {
        for (int j=0;j<3;++j) {
            if (elements[i][j] != 0 && elements[i][j] != 1) {
                converted[i][j] = ch;
                ch++;
            } else {
                converted[i][j] = elements[i][j];
            }
        }
    }
    return converted;
}

bool isGameOver(vector<vector<int>> elements) {
    elements = convertVector(elements);
    if ((elements[0][0] == elements[0][1] && elements[0][1] == elements[0][2])
        || (elements[1][0] == elements[1][1] && elements[1][1] == elements[1][2])
        || (elements[2][0] == elements[2][1] && elements[2][1] == elements[2][2])
        || (elements[0][0] == elements[1][1] && elements[1][1] == elements[2][2])
        || (elements[2][0] == elements[1][1] && elements[1][1] == elements[0][2])
        || (elements[0][0] == elements[1][0] && elements[1][0] == elements[2][0])
        || (elements[0][1] == elements[1][1] && elements[1][1] == elements[2][1])
        || (elements[0][2] == elements[1][2] && elements[1][2] == elements[2][2])) {
        return true;
    }
    return false;
}

bool canGameOver(vector<vector<int>> elements, const int &k) {
    for (int i=0;i<3;++i) {
        for (int j=0;j<3;++j) {
            if (elements[i][j] != 0 && elements[i][j] != 1) {
                int oldElement = elements[i][j];
                elements[i][j] = k;
                if (isGameOver(elements)) {
                    return true;
                } else {
                    elements[i][j] = oldElement;
                }
            }
        }
    }
    return false;
}

vector<int> getWinnerPositions(vector<vector<int>> elements, const int &k) {
    vector<int> positions;
    for (int i=0;i<3;++i) {
        for (int j=0;j<3;++j) {
            if (elements[i][j] != 0 && elements[i][j] != 1) {
                int oldElement = elements[i][j];
                elements[i][j] = k;
                if (isGameOver(elements)) {
                    positions.push_back(i);
                    positions.push_back(j);
                    return positions;
                } else {
                    elements[i][j] = oldElement;
                }
            }
        }
    }
    return positions;
}

int main() {
    bool gameOver = false;
    srand(time(NULL));
    int turn = rand() % 2;
    vector<vector<int>> binaryValues;
    for (int i=0;i<3;++i) {
        vector<int> line;
        for (int j=0;j<3;++j) {
            line.push_back(9);
        }
        binaryValues.push_back(line);
    }
    vector<vector<char>> area;
    for (int i=0;i<3;++i) {
        vector<char> line;
        for (int j=0;j<3;++j) {
            line.push_back('*');
        }
        area.push_back(line);
    }
    if (turn == 0) {
        cout << "First player: Computer" << endl;
    } else {
        cout << "First player: You" << endl;
    }
    while (!gameOver) {
        int n, m;
        if (turn == 0) {
            if (canGameOver(binaryValues, 0)) {
                vector<int> positions = getWinnerPositions(binaryValues, 0);
                n = positions[0];
                m = positions[1];
                binaryValues[n][m] = 0;
                area[n][m] = 'o';
                gameOver = true;
            } else if (canGameOver(binaryValues, 1)) {
                vector<int> positions = getWinnerPositions(binaryValues, 1);
                n = positions[0];
                m = positions[1];
                binaryValues[n][m] = 0;
                area[n][m] = 'o';
            } else {
                vector<int> positions = makeRandomPositions(binaryValues);
                n = positions[0];
                m = positions[1];
                binaryValues[n][m] = 0;
                area[n][m] = 'o';
            }
            turn++;
        } else {
            cout << "Enter position: ";
            cin >> n >> m;
            n--;
            m--;
            binaryValues[n][m] = 1;
            area[n][m] = 'x';
            turn = 0;
        }
        for (const vector<char> &ch : area) {
            for (const char &c : ch) {
                cout << c << " ";
            }
            cout << endl;
        }
        for (int i=0;i<10;++i) {
            cout << "=";
        }
        if (isGameOver(binaryValues)) {
            cout << endl << "Game Over";   
        }
        cout << endl;
    }
    return 0;
}

#include<iostream>

using namespace std;

const int mapSize = 3;


bool isPossible(int x, int y, int num, int area[mapSize*mapSize][mapSize*mapSize]);

pair<int, int> findEmpty(int area[mapSize*mapSize][mapSize*mapSize]);

void solve(int area[mapSize*mapSize][mapSize*mapSize]);

int main() {

    int area[mapSize*mapSize][mapSize*mapSize] = {

        {8, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 6, 0, 0, 0, 0, 0},
        {0, 7, 0, 0, 9, 0, 2, 0, 0},
        {0, 5, 0, 0, 0, 7, 0, 0, 0},
        {0, 0, 0, 0, 4, 5, 7, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 3, 0},
        {0, 0, 1, 0, 0, 0, 0, 6, 8},
        {0, 0, 8, 5, 0, 0, 0, 1, 0},
        {0, 9, 0, 0, 0, 0, 4, 0, 0}

    };

    solve(area);

    return 0;

}

bool isPossible(int x, int y, int num, int area[mapSize*mapSize][mapSize*mapSize]) {

    for (int i=0;i<mapSize*mapSize;++i) {

        if (area[i][y] == num)
            return false;

    }

    for (int i=0;i<mapSize*mapSize;++i) {

        if (area[x][i] == num)
            return false;

    }

    int startX = 0, startY = 0;

    if (x < 3) {
        startX = 0;
    } else if (x > 2 && x < 6) {
        startX = 3;
    } else {
        startX = 6;
    }

    if (y < 3) {
        startY = 0;
    } else if (y > 2 && y < 6) {
        startY = 3;
    } else {
        startY = 6;
    }

    for (int i=0;i<3;++i) {

        for (int j=0;j<3;++j) {

            if (area[startX+i][startY+j] == num)
                return false;

        }

    }

    return true;

}

pair<int, int> findEmpty(int area[mapSize*mapSize][mapSize*mapSize]) {

    for (int i=0;i<mapSize*mapSize;++i) {

        for (int j=0;j<mapSize*mapSize;++j) {

            if (area[i][j] == 0)
                return {i, j};

        }

    }

    return {-1, -1};

}
# mnogo interesno
void solve(int a[mapSize*mapSize][mapSize*mapSize]) {

    pair<int, int> coordinates = findEmpty(a);

    int x = coordinates.first, y = coordinates.second;

    if (x == -1) {

        for (int i=0;i<mapSize*mapSize;++i) {

            for (int j=0;j<mapSize*mapSize;++j) {

                cout << a[i][j] << " ";

            }

            cout << endl;

        }

        cout << endl;

    } else {

        for (int num=1;num<=mapSize*mapSize;++num) {

            if (isPossible(x, y, num, a)) {

                a[x][y] = num;

                solve(a);

                a[x][y] = 0;

            }

        }

    }

}

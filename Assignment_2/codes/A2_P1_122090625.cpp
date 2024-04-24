#include <iostream>
#include <vector>
using namespace std;


int find_winner(vector<vector<int>>& x, int n) {
    int winner = 0;

    for (int i = 1; i < n; i++) {
        if (x[winner][i] == 1) {
            winner = i;
        }
    }//assume the current candidate is the winner
     //if find any "1" in its line, we will update the winner
     //to the candidate in the i-th label, and check he has 
     //sent note or not

    for (int j = 0; j < n; j++) {
        if ((j != winner && x[winner][j] == 1) || (j != winner && x[j][winner] == 0)) {
            return -1;
        }
    }//find any candidate don't send note to winner, or winner send note to him

    return winner;
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>> x(n, vector<int>(n)); //the input matrix 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x[i][j];
        }
    }

    cout << find_winner(x, n) << endl;
}
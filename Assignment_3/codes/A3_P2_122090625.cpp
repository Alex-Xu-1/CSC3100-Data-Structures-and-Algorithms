#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    int T;
    cin >> T;
    vector<double> result(T);

    for (int i = 0; i < T; ++i){
        int r1, r2, d;
        cin >> r1 >> r2 >> d;
        double d2 = r2 - cbrt(pow((r1 - d), 3) - pow(r1, 3) + pow(r2, 3));
        result[i] = d2;
    };
    
    for (double i : result){
        printf("%.10f\n", i);
    };
}

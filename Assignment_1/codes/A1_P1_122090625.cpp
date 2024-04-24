#include <iostream>
#include <algorithm>
#include <list>
#include <cmath>
#include <tuple>
#include <vector>
#include <functional>

using namespace std;

bool cmp_1(const tuple<int, int>& left, const tuple<int, int>& right)
{
    if (get<0>(left) < get<0>(right))
        return true;
    if (get<0>(left) == get<0>(right))
        return get<1>(left) < get<1>(right);
    return false;
}

bool cmp_2(const tuple<int, int>& left, const tuple<int, int>& right)
{
    if (get<0>(left) > get<0>(right))
        return true;
    if (get<0>(left) == get<0>(right))
        return get<1>(left) < get<1>(right);
    return false;
}

bool cmp_3(const tuple<int, int>& left, const tuple<int, int>& right)
{
    if (get<0>(left) < get<0>(right))
        return true;
    if (get<0>(left) == get<0>(right))
        return get<1>(left) > get<1>(right);
    return false;
}

bool cmp_4(const tuple<int, int>& left, const tuple<int, int>& right)
{
    if (get<0>(left) > get<0>(right))
        return true;
    if (get<0>(left) == get<0>(right))
        return get<1>(left) > get<1>(right);
    return false;
}

int main(){
    int k, n, id, T;
    cin >> T; 
    vector<vector<tuple<int, int>>> result = {};

    for (int i = 0; i < T; i++){
        cin >> n >> k >> id;
        list <int> A;
        for (int j = 0; j < n; j++){
            int a;
            cin >> a;
            A.push_back(a);
        }

        vector<tuple <int, int>> coordinates = {};   

        for (int i : A){
            int x = floor(i / k);
            int y = i % k;  
            coordinates.push_back(tuple(x, y));
        }

        if (id == 1)
            sort(coordinates.begin(), coordinates.end(), cmp_1); 
        else if (id == 2)
            sort(coordinates.begin(), coordinates.end(), cmp_2); 
        else if (id == 3)
            sort(coordinates.begin(), coordinates.end(), cmp_3);
        else if (id == 4)
            sort(coordinates.begin(), coordinates.end(), cmp_4);

        result.push_back(coordinates);
    }

    for (auto& coordinates : result){
        for (auto& coordinate: coordinates)
            cout << get<0>(coordinate) << " " << get<1>(coordinate) << endl;
        cout << endl;
    }
}

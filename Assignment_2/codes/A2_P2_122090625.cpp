#include <iostream>
#include <deque>
#include <vector>

using namespace std;


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int height_of_each_house[n];

    for (int i = 0; i < n; i++) {
        cin >> height_of_each_house[i];
    }

    deque<int> double_queue;
    vector<int> tallest_visible_house_each_stop;
    for (int i = 0; i < n; ++i) {
        while (!double_queue.empty() && double_queue.back() <= i - k)
            double_queue.pop_back();

        while (!double_queue.empty() && height_of_each_house[double_queue.front()] < height_of_each_house[i])
            double_queue.pop_front();

        double_queue.push_front(i);

        if (i >= k - 1)
            tallest_visible_house_each_stop.push_back(height_of_each_house[double_queue.back()]);
    }

    for (int i : tallest_visible_house_each_stop) {
        cout << i << "\n";
    }

}




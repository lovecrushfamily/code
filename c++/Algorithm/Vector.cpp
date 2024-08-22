#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> a; // khai báo 1 vector
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back(x); // chèn x vào cuối của vector
    }

    vector<int> b(n); // khai báo 1 vector b có tối đa n phần tử
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int x : a) {
        cout << x << " "; // in các phần tử của a, có 2 cách
    }
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    // với b cũng chọn được 1 trong 2 cách;

    // sắp xếp 1 vector với thứ tự tăng dần dùng thư viện algorithm
    sort(a.begin(), a.end());

    // sắp xếp với thứ tự giảm dần
    sort(a.rbegin(), a.rend());

    return 0;
}
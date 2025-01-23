#include <bits/stdc++.h>
using namespace std;

// Function to generate Gray code sequence up to n
vector<int> generate_gray_code(int n) {
    vector<int> gray_code;
    for (int i = 0; i < (1 << n); i++) {
        gray_code.push_back(i ^ (i >> 1)); // Gray code formula
    }
    return gray_code;
}

// Utility to print the Gray code sequence
void print_gray_code(const vector<int>& gray_code) {
    for (int code : gray_code) {
        cout << code << " ";
    }
    cout << endl;
}

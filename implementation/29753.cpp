#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
using namespace std;

/*
 * Problem: 최소 성적
 * Platform: BOJ
 * Problem Number: 29753
 * URL: https://www.acmicpc.net/problem/29753
 * Category: Implementation
 * Difficulty: Silver IV
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    map<string, int> gradeMap = {
        {"A+", 450}, {"A0", 400},
        {"B+", 350}, {"B0", 300},
        {"C+", 250}, {"C0", 200},
        {"D+", 150}, {"D0", 100},
        {"F",    0}
    };

    string grades[] = {"F", "D0", "D+", "C0", "C+", "B0", "B+", "A0", "A+"};

    int n;
    double targetD;
    cin >> n >> targetD;
    long long target = llround(targetD * 100);
    long long sumW = 0;
    int totalC = 0;
    for (int i = 1; i < n; i++) {
        int c; string ch;
        cin >> c >> ch;
        sumW += (long long)c * gradeMap[ch];
        totalC += c;
    }
    int c;
    cin >> c; totalC += c;
    for (auto& g : grades) {
        if ((long long)c * gradeMap[g] + sumW >= target * totalC) {
            cout << g;
            return 0;
        }
    }
    cout << "impossible";
    return 0;
}

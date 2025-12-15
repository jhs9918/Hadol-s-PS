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
 * Problem: $A + B - C$
 * Platform: BOJ
 * Problem Number: 31403
 * URL: https://www.acmicpc.net/problem/31403
 * Category: String
 * Difficulty: Bronze IV
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a,b,c; cin>>a>>b>>c;

    cout << a+b-c << endl;
    cout << stoi(to_string(a)+to_string(b)) - c ;


    return 0;
}

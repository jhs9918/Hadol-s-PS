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
 * Problem: 숫자 정사각형
 * Platform: BOJ
 * Problem Number: 1051
 * URL: https://www.acmicpc.net/problem/1051
 * Category: Bruteforce
 * Difficulty: Silver III
 */

int arr[50][50];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++) {
        string line; cin>>line;
        for(int j=0;j<m;j++) {
            arr[i][j] = line[j] - '0';
        }
    }
    if (n == 1 || m == 1) {
        cout << 1;
        return 0;
    }
    int ans = 1;
    //부르트 포스로 시작점 기준, n-1, m-1까지만 탐색? n이 더 클때와 m이 더 클때를 효율적으로 처리하는게 좋아보임 정사각형이므로
     for (int i = 0 ; i < n-1 ; i++) {
         for (int j = 0 ; j < m-1 ; j++) {
             for (int k = 1; i+k < n && j+k < m ; k++) {
                 if (arr[i][j] == arr[i+k][j+k] and arr[i][j] == arr[i][j+k] and arr[i][j] == arr[i+k][j]) ans = max(ans,(k+1)*(k+1));
             }
         }
     }
    cout << ans;
    return 0;
}
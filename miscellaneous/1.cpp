//
// Created by 장하연 on 26. 4. 4..
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;
int n;
vector<vector<char>> arr;
int calc() {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == '+') {
                int dx[4] = {1, 0, -1, 0};
                int dy[4] = {0, 1, 0, -1};
                for (int k = 0; k < 4; k++) {
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if (nx<0 || nx>=n || ny<0 || ny>=n) continue;
                    if (arr[i+dx[k]][j+dy[k]] != '.') sum += 1;
                }
            }
            else if (arr[i][j] == 'x') {
                int dx[4] = {1, 1, -1, -1};
                int dy[4] = {1, -1, -1, 1};
                for (int k = 0; k < 4; k++) {
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if (nx<0 || nx>=n || ny<0 || ny>=n) continue;
                    if (arr[nx][ny] != '.') sum += 1;
                }
            }
            else if (arr[i][j] == '*') {
                set<char> types;
                int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
                int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
                for (int k = 0; k < 8; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (arr[nx][ny] != '.') types.insert(arr[nx][ny]);
                }
                sum += types.size()*2;
            }
        }
    }
    return sum;
}

int main() {
    cin >> n;
    arr.resize(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        string line; cin >> line;
        for (int j = 0; j < n; j++) arr[i][j] = line[j];
    }
    char inp; cin >> inp;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j]!= '.') continue;
            arr[i][j] = inp;
            ans = max(ans, calc());
            arr[i][j] = '.';
        }
    }
    cout << ans;
}
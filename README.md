# 알고리즘 문제 풀이

CLion에서 알고리즘 문제를 풀기 위한 개인 저장소입니다.

🛠️ **사용 도구**: [ps-generator](https://github.com/username/ps-generator)

## 프로젝트 구조

```
ps/
├── dp/                  # 동적 프로그래밍
├── greedy/              # 탐욕법
├── graph/               # 그래프
├── implementation/      # 구현
├── string/              # 문자열
├── data_structure/      # 자료구조
├── math/                # 수학
├── bruteforce/          # 완전탐색
├── binary_search/       # 이분탐색
├── sorting/             # 정렬
├── backtracking/        # 백트래킹
├── simulation/          # 시뮬레이션
├── template.cpp         # 문제 풀이 템플릿
├── main.cpp             # 테스트용 메인 파일
└── CMakeLists.txt       # CMake 설정
```

## 사용 방법

### 0. 🚀 빠른 시작 - CLion에서 바로 사용하기 (추천!)

**CLion 메뉴에서 바로 실행 가능!**

#### 방법 1: CLion 메뉴 사용 (가장 간편!)

1. **Tools → External Tools → 새 문제 생성** 클릭
2. 다이얼로그에 **문제 URL** 입력
3. **카테고리** 선택
4. 자동으로 파일 생성! ✨

**또는 단축키 설정:**
- `Settings/Preferences` → `Keymap`
- `External Tools → 새 문제 생성` 검색
- 원하는 단축키 설정 (예: `Cmd+Shift+N`)

**사용 흐름:**
```
CLion에서 메뉴 클릭
    ↓
[다이얼로그] URL 입력: https://www.acmicpc.net/problem/2178
    ↓
[다이얼로그] 카테고리 선택: BFS
    ↓
터미널 자동 실행 → 문제 정보 가져오기
    ↓
✅ bfs/2178.cpp 파일 생성!
    ↓
CLion에서 CMake Reload (자동)
    ↓
Run Configuration에서 'bfs_2178' 선택하여 실행!
```

#### 방법 2: 터미널 사용

```bash
# 백준 문제 자동 생성
python3 create_problem.py https://www.acmicpc.net/problem/2178

# 또는 URL 없이 실행하면 대화형으로 진행
python3 create_problem.py
```

**지원하는 플랫폼:**
- ✅ 백준 (BOJ) - 제목, 난이도 자동 추출
- ✅ 프로그래머스 - 수동 입력

**자동으로 채워지는 정보:**
- Problem (문제 제목)
- Platform (플랫폼)
- Problem Number (문제 번호)
- URL (문제 링크)
- Difficulty (난이도) - 백준은 solved.ac에서 자동 추출
- Category (선택한 카테고리)

**실행 예시:**
```bash
$ python3 create_problem.py https://www.acmicpc.net/problem/2178

============================================================
🚀 알고리즘 문제 파일 생성기
============================================================

🔍 문제 정보를 가져오는 중...

✅ 문제 정보:
   제목: 미로 탐색
   플랫폼: BOJ
   번호: 2178
   난이도: Silver 1

📁 카테고리를 선택하세요:
  1. DP (dp/)
  2. Greedy (greedy/)
  3. Graph (graph/)
  4. BFS (bfs/)
  ...

선택 (번호 또는 폴더명): 4

📝 파일을 생성하는 중...

✅ 파일이 생성되었습니다: bfs/2178.cpp

💡 CLion에서 'bfs_2178'를 실행하세요!
```

### 1. 새로운 문제 추가하기 (수동)

1. `template.cpp` 파일을 복사합니다
2. 해당 문제의 카테고리 폴더로 이동합니다
3. 파일명을 문제 번호나 제목으로 변경합니다 (예: `1234.cpp`, `fibonacci.cpp`)
4. 파일 상단의 주석을 채웁니다:
   - Problem: 문제 이름
   - Platform: 플랫폼 (BOJ, Programmers 등)
   - Problem Number: 문제 번호
   - URL: 문제 링크
   - Category: 카테고리
   - Difficulty: 난이도

예시:
```bash
cp template.cpp dp/1003.cpp
```

### 2. 빌드 및 실행

#### CLion에서:

1. 상단의 **Run Configuration** 드롭다운에서 실행할 문제를 선택
   - 실행 파일 이름 형식: `카테고리_문제번호` (예: `dp_1003`)
2. Run 버튼 (▶️) 또는 `Shift + F10` 눌러 실행
3. Debug 버튼 (🐞) 또는 `Shift + F9`로 디버깅

#### 터미널에서:

```bash
# 프로젝트 빌드
cmake -B build
cmake --build build

# 특정 문제 실행
./build/dp_1003

# 또는 입력 파일 리다이렉션
./build/dp_1003 < input.txt
```

### 3. 입출력 파일 사용 (선택사항)

각 문제 파일과 같은 디렉토리에 `input.txt`, `output.txt` 파일을 만들어 테스트할 수 있습니다.

```bash
# 입력 파일로 실행
./build/dp_1003 < dp/input.txt

# 출력을 파일로 저장
./build/dp_1003 < dp/input.txt > dp/output.txt
```

## 팁

### 빠른 입출력 설정
템플릿에 이미 포함되어 있습니다:
```cpp
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
```

### 자주 사용하는 헤더
템플릿에 포함된 헤더:
- `<iostream>`: 기본 입출력
- `<vector>`: 동적 배열
- `<algorithm>`: 정렬, 이진탐색 등
- `<string>`: 문자열
- `<queue>`, `<stack>`: 큐, 스택
- `<map>`, `<set>`: 맵, 셋
- `<cmath>`: 수학 함수

### CMake 재설정
새로운 카테고리 폴더를 추가한 경우 `CMakeLists.txt`의 `file(GLOB_RECURSE SOURCE_FILES ...)` 부분에 추가하세요.

## 문제 풀이 예시

```cpp
#include <iostream>
#include <vector>
using namespace std;

/*
 * Problem: 피보나치 함수
 * Platform: BOJ
 * Problem Number: 1003
 * URL: https://www.acmicpc.net/problem/1003
 * Category: DP
 * Difficulty: Silver 3
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        // DP 문제 풀이 코드...
    }

    return 0;
}
```

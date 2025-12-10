#!/bin/bash
# CLion에서 실행하는 문제 생성 스크립트 (macOS용)

cd "$(dirname "$0")"

# URL 입력 다이얼로그
URL=$(osascript -e 'Tell application "System Events" to display dialog "문제 URL을 입력하세요:" default answer "" with title "새 문제 생성"' -e 'text returned of result' 2>/dev/null)

if [ -z "$URL" ]; then
    osascript -e 'display notification "취소되었습니다." with title "문제 생성"'
    exit 1
fi

# 카테고리 선택 다이얼로그
CATEGORY=$(osascript <<EOF
tell application "System Events"
    set categoryList to {"DP", "Greedy", "Graph", "BFS", "DFS", "Implementation", "String", "Data Structure", "Math", "Bruteforce", "Binary Search", "Sorting", "Backtracking", "Simulation"}
    set selectedCategory to choose from list categoryList with prompt "카테고리를 선택하세요:" default items {"BFS"}

    if selectedCategory is false then
        return ""
    else
        return item 1 of selectedCategory
    end if
end tell
EOF
)

if [ -z "$CATEGORY" ]; then
    osascript -e 'display notification "취소되었습니다." with title "문제 생성"'
    exit 1
fi

# 카테고리 이름을 폴더명으로 변환
case "$CATEGORY" in
    "DP") FOLDER="dp" ;;
    "Greedy") FOLDER="greedy" ;;
    "Graph") FOLDER="graph" ;;
    "BFS") FOLDER="bfs" ;;
    "DFS") FOLDER="dfs" ;;
    "Implementation") FOLDER="implementation" ;;
    "String") FOLDER="string" ;;
    "Data Structure") FOLDER="data_structure" ;;
    "Math") FOLDER="math" ;;
    "Bruteforce") FOLDER="bruteforce" ;;
    "Binary Search") FOLDER="binary_search" ;;
    "Sorting") FOLDER="sorting" ;;
    "Backtracking") FOLDER="backtracking" ;;
    "Simulation") FOLDER="simulation" ;;
    *) FOLDER="implementation" ;;
esac

# Python 스크립트 실행 (터미널 창 열기)
osascript <<EOF
tell application "Terminal"
    activate
    do script "cd '$PWD' && python3 create_problem.py '$URL' -c '$FOLDER' && echo '\n✅ 완료! CLion에서 CMake를 Reload 하세요.\n' && read -p '아무 키나 누르면 종료합니다...' && exit"
end tell
EOF

# 성공 알림
sleep 2
osascript -e "display notification \"파일이 생성되었습니다: $FOLDER/\" with title \"문제 생성 완료\""

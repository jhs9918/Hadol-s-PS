#!/bin/bash
# miscellaneous 폴더의 문제를 해당 카테고리 폴더로 이동하는 스크립트

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
cd "$SCRIPT_DIR"

MISC_DIR="$SCRIPT_DIR/miscellaneous"

# miscellaneous 폴더 확인
if [ ! -d "$MISC_DIR" ]; then
    osascript -e 'display alert "miscellaneous 폴더가 없습니다." as warning'
    exit 1
fi

# miscellaneous 폴더의 cpp 파일 목록 수집
FOUND=$(find "$MISC_DIR" -maxdepth 1 -name "*.cpp" | sort)

if [ -z "$FOUND" ]; then
    osascript -e 'display alert "miscellaneous 폴더에 이동할 파일이 없습니다." as warning'
    exit 1
fi

FILES=()
while IFS= read -r line; do
    FILES+=("$(basename "$line")")
done <<< "$FOUND"

# AppleScript 배열 문자열 생성
FILE_LIST=$(printf '"%s", ' "${FILES[@]}")
FILE_LIST="{${FILE_LIST%, }}"

# 파일 선택 다이얼로그
SELECTED_FILE=$(osascript <<EOF
tell application "System Events"
    set fileList to $FILE_LIST
    set selectedFile to choose from list fileList with prompt "이동할 파일을 선택하세요:" default items {item 1 of fileList}
    if selectedFile is false then
        return ""
    else
        return item 1 of selectedFile
    end if
end tell
EOF
)

if [ -z "$SELECTED_FILE" ]; then
    osascript -e 'display notification "취소되었습니다." with title "문제 이동"'
    exit 1
fi

# 카테고리 선택 다이얼로그
CATEGORY=$(osascript <<EOF
tell application "System Events"
    set categoryList to {"DP", "Greedy", "Graph", "BFS", "DFS", "Implementation", "String", "Data Structure", "Math", "Bruteforce", "Binary Search", "Sorting", "Backtracking", "Simulation"}
    set selectedCategory to choose from list categoryList with prompt "$SELECTED_FILE 을(를) 이동할 카테고리:" default items {"BFS"}
    if selectedCategory is false then
        return ""
    else
        return item 1 of selectedCategory
    end if
end tell
EOF
)

if [ -z "$CATEGORY" ]; then
    osascript -e 'display notification "취소되었습니다." with title "문제 이동"'
    exit 1
fi

# 카테고리 → 폴더명 변환
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

SRC="$MISC_DIR/$SELECTED_FILE"
DEST_DIR="$SCRIPT_DIR/$FOLDER"
DEST="$DEST_DIR/$SELECTED_FILE"

# 대상 폴더 없으면 생성
mkdir -p "$DEST_DIR"

# 이미 존재하는 경우 확인
if [ -f "$DEST" ]; then
    CONFIRM=$(osascript -e "button returned of (display dialog \"$DEST 파일이 이미 존재합니다. 덮어쓸까요?\" buttons {\"취소\", \"덮어쓰기\"} default button \"취소\")" 2>/dev/null)
    if [ "$CONFIRM" != "덮어쓰기" ]; then
        osascript -e 'display notification "취소되었습니다." with title "문제 이동"'
        exit 1
    fi
fi

# 파일 내부 Category 주석 업데이트 후 이동
sed "s/\* Category: Miscellaneous/\* Category: $CATEGORY/" "$SRC" > "$DEST"
rm "$SRC"

# 실행 파일(확장자 없는 동명 파일) 삭제
EXEC_NAME="${SELECTED_FILE%.cpp}"
rm -f "$MISC_DIR/$EXEC_NAME"

osascript -e "display notification \"$SELECTED_FILE → $FOLDER/\" with title \"문제 이동 완료\""

#!/bin/bash
# 현재 파일만 커밋하고 푸시

set -e

# 현재 파일 경로 (CLion에서 전달받음)
FILE_PATH="$1"

if [ -z "$FILE_PATH" ]; then
    echo "❌ 파일 경로가 제공되지 않았습니다."
    exit 1
fi

cd "$(dirname "$0")"

# 파일이 존재하는지 확인
if [ ! -f "$FILE_PATH" ]; then
    echo "❌ 파일을 찾을 수 없습니다: $FILE_PATH"
    exit 1
fi

# 상대 경로로 변환
REL_PATH=$(realpath --relative-to="$(pwd)" "$FILE_PATH" 2>/dev/null || python3 -c "import os; print(os.path.relpath('$FILE_PATH', '$(pwd)'))")

# 커밋 메시지 생성 (예: "Solve: bfs/2178")
COMMIT_MSG="Solve: $REL_PATH"

echo "📝 커밋 중: $REL_PATH"

# Git 작업
git add "$REL_PATH"

if git diff --cached --quiet; then
    echo "⚠️  변경사항이 없습니다."
    exit 0
fi

git commit -m "$COMMIT_MSG"
echo "✅ 커밋 완료: $COMMIT_MSG"

echo "🚀 푸시 중..."
git push

echo "✅ 완료!"

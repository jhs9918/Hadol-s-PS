#!/bin/bash
# 모든 변경사항 커밋하고 푸시

set -e

cd "$(dirname "$0")"

echo "📝 모든 변경사항 확인 중..."

# 변경사항 확인
if git diff --quiet && git diff --cached --quiet; then
    echo "⚠️  변경사항이 없습니다."
    exit 0
fi

# 변경된 파일 목록 출력
echo "변경된 파일:"
git status --short

# 모든 파일 추가
git add .

# 커밋 메시지 생성
TIMESTAMP=$(date "+%Y-%m-%d %H:%M:%S")
COMMIT_MSG="Update problems - $TIMESTAMP"

echo ""
echo "📝 커밋 중..."
git commit -m "$COMMIT_MSG"
echo "✅ 커밋 완료: $COMMIT_MSG"

echo "🚀 푸시 중..."
git push

echo "✅ 완료!"

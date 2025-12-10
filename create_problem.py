#!/usr/bin/env python3
"""
알고리즘 문제 파일 자동 생성 스크립트
문제 URL을 입력하면 자동으로 메타 정보를 채워서 cpp 파일을 생성합니다.
"""

import re
import sys
import os
import argparse
from urllib.request import urlopen, Request
from urllib.error import URLError, HTTPError
from html.parser import HTMLParser


class BOJParser(HTMLParser):
    """백준 온라인 저지 페이지 파서"""

    def __init__(self):
        super().__init__()
        self.title = ""
        self.in_title = False
        self.problem_id = ""

    def handle_starttag(self, tag, attrs):
        if tag == "title":
            self.in_title = True

    def handle_data(self, data):
        if self.in_title:
            # "1234번: 문제 제목" 형식에서 제목 추출
            match = re.match(r'(\d+)번:\s*(.+)', data.strip())
            if match:
                self.problem_id = match.group(1)
                self.title = match.group(2).strip()
            self.in_title = False


def fetch_url(url):
    """URL에서 HTML 컨텐츠 가져오기"""
    try:
        headers = {
            'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36'
        }
        req = Request(url, headers=headers)
        with urlopen(req, timeout=10) as response:
            return response.read().decode('utf-8')
    except (URLError, HTTPError) as e:
        print(f"❌ URL을 가져오는 중 오류 발생: {e}")
        return None


def parse_boj_problem(url):
    """백준 문제 정보 파싱"""
    # URL에서 문제 번호 추출
    match = re.search(r'/problem/(\d+)', url)
    if not match:
        print("❌ 올바른 백준 문제 URL이 아닙니다.")
        return None

    problem_number = match.group(1)

    # 페이지 가져오기
    html = fetch_url(url)
    if not html:
        return None

    # 제목 파싱
    parser = BOJParser()
    parser.feed(html)

    if not parser.title:
        print("❌ 문제 제목을 찾을 수 없습니다.")
        return None

    # 난이도 정보는 solved.ac API 사용 (선택사항)
    tier = get_boj_tier(problem_number)

    return {
        'platform': 'BOJ',
        'number': problem_number,
        'title': parser.title,
        'url': url,
        'difficulty': tier
    }


def get_boj_tier(problem_number):
    """solved.ac API로 문제 난이도 가져오기 (선택사항)"""
    try:
        api_url = f"https://solved.ac/api/v3/problem/show?problemId={problem_number}"
        headers = {'User-Agent': 'Mozilla/5.0'}
        req = Request(api_url, headers=headers)
        with urlopen(req, timeout=5) as response:
            import json
            data = json.loads(response.read().decode('utf-8'))
            level = data.get('level', 0)

            # 레벨을 티어로 변환
            tiers = {
                range(1, 6): ["Bronze V", "Bronze IV", "Bronze III", "Bronze II", "Bronze I"],
                range(6, 11): ["Silver V", "Silver IV", "Silver III", "Silver II", "Silver I"],
                range(11, 16): ["Gold V", "Gold IV", "Gold III", "Gold II", "Gold I"],
                range(16, 21): ["Platinum V", "Platinum IV", "Platinum III", "Platinum II", "Platinum I"],
                range(21, 26): ["Diamond V", "Diamond IV", "Diamond III", "Diamond II", "Diamond I"],
                range(26, 31): ["Ruby V", "Ruby IV", "Ruby III", "Ruby II", "Ruby I"],
            }

            for tier_range, tier_names in tiers.items():
                if level in tier_range:
                    return tier_names[level - min(tier_range)]

            return "Unrated"
    except:
        return "Unknown"


def parse_programmers_problem(url):
    """프로그래머스 문제 정보 파싱"""
    # URL에서 문제 번호 추출
    match = re.search(r'/learn/courses/\d+/lessons/(\d+)', url)
    if not match:
        print("❌ 올바른 프로그래머스 문제 URL이 아닙니다.")
        return None

    problem_number = match.group(1)

    # 프로그래머스는 제목을 수동으로 입력받기
    print("⚠️  프로그래머스는 문제 제목을 직접 입력해주세요.")
    title = input("문제 제목: ").strip()

    print("난이도를 입력해주세요 (예: Level 1, Level 2, Level 3):")
    difficulty = input("난이도: ").strip() or "Unknown"

    return {
        'platform': 'Programmers',
        'number': problem_number,
        'title': title,
        'url': url,
        'difficulty': difficulty
    }


def parse_problem_url(url):
    """URL 파싱 및 플랫폼 판별"""
    if 'acmicpc.net' in url or 'boj.kr' in url:
        return parse_boj_problem(url)
    elif 'programmers.co.kr' in url:
        return parse_programmers_problem(url)
    else:
        print("❌ 지원하지 않는 플랫폼입니다. (지원: 백준, 프로그래머스)")
        return None


def get_category_input():
    """카테고리 선택"""
    categories = {
        '1': ('dp', 'DP'),
        '2': ('greedy', 'Greedy'),
        '3': ('graph', 'Graph'),
        '4': ('bfs', 'BFS'),
        '5': ('dfs', 'DFS'),
        '6': ('implementation', 'Implementation'),
        '7': ('string', 'String'),
        '8': ('data_structure', 'Data Structure'),
        '9': ('math', 'Math'),
        '10': ('bruteforce', 'Bruteforce'),
        '11': ('binary_search', 'Binary Search'),
        '12': ('sorting', 'Sorting'),
        '13': ('backtracking', 'Backtracking'),
        '14': ('simulation', 'Simulation'),
    }

    print("\n📁 카테고리를 선택하세요:")
    for key, (folder, name) in categories.items():
        print(f"  {key}. {name} ({folder}/)")

    choice = input("\n선택 (번호 또는 폴더명): ").strip()

    # 숫자로 선택한 경우
    if choice in categories:
        return categories[choice]

    # 폴더명으로 선택한 경우
    for folder, name in categories.values():
        if choice.lower() == folder.lower():
            return (folder, name)

    print("❌ 잘못된 선택입니다. 기본값(implementation)을 사용합니다.")
    return ('implementation', 'Implementation')


def create_cpp_file(problem_info, category_folder, category_name):
    """C++ 파일 생성"""

    # 파일 경로 설정
    filename = f"{problem_info['number']}.cpp"
    filepath = os.path.join(category_folder, filename)

    # 폴더가 없으면 생성
    os.makedirs(category_folder, exist_ok=True)

    # 이미 파일이 존재하는지 확인
    if os.path.exists(filepath):
        overwrite = input(f"⚠️  {filepath} 파일이 이미 존재합니다. 덮어쓸까요? (y/n): ")
        if overwrite.lower() != 'y':
            print("❌ 취소되었습니다.")
            return None

    # 템플릿 내용
    template = f"""#include <iostream>
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
 * Problem: {problem_info['title']}
 * Platform: {problem_info['platform']}
 * Problem Number: {problem_info['number']}
 * URL: {problem_info['url']}
 * Category: {category_name}
 * Difficulty: {problem_info['difficulty']}
 */

int main() {{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 코드 작성

    return 0;
}}
"""

    # 파일 작성
    with open(filepath, 'w', encoding='utf-8') as f:
        f.write(template)

    return filepath


def main():
    parser = argparse.ArgumentParser(description='알고리즘 문제 파일 자동 생성')
    parser.add_argument('url', nargs='?', help='문제 URL')
    parser.add_argument('-c', '--category', help='카테고리 폴더명')

    args = parser.parse_args()

    print("=" * 60)
    print("🚀 알고리즘 문제 파일 생성기")
    print("=" * 60)

    # URL 입력
    url = args.url
    if not url:
        url = input("\n📝 문제 URL을 입력하세요: ").strip()

    if not url:
        print("❌ URL이 입력되지 않았습니다.")
        return 1

    # 문제 정보 파싱
    print(f"\n🔍 문제 정보를 가져오는 중... ({url})")
    problem_info = parse_problem_url(url)

    if not problem_info:
        return 1

    # 정보 출력
    print("\n✅ 문제 정보:")
    print(f"   제목: {problem_info['title']}")
    print(f"   플랫폼: {problem_info['platform']}")
    print(f"   번호: {problem_info['number']}")
    print(f"   난이도: {problem_info['difficulty']}")

    # 카테고리 선택
    if args.category:
        category_folder = args.category
        category_name = args.category.title()
    else:
        category_folder, category_name = get_category_input()

    # 파일 생성
    print(f"\n📝 파일을 생성하는 중...")
    filepath = create_cpp_file(problem_info, category_folder, category_name)

    if filepath:
        print(f"\n✅ 파일이 생성되었습니다: {filepath}")
        print(f"\n💡 CLion에서 '{category_folder}_{problem_info['number']}'를 실행하세요!")

    return 0


if __name__ == '__main__':
    sys.exit(main())

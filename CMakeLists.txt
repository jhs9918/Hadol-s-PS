cmake_minimum_required(VERSION 3.20)
project(ps)

set(CMAKE_CXX_STANDARD 17)

# 실행 파일은 빌드 디렉토리에만 생성
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# 각 카테고리 디렉토리의 모든 .cpp 파일을 찾아서 개별 실행 파일로 빌드
file(GLOB_RECURSE SOURCE_FILES
        "dp/*.cpp"
        "greedy/*.cpp"
        "graph/*.cpp"
        "bfs/*.cpp"
        "dfs/*.cpp"
        "implementation/*.cpp"
        "string/*.cpp"
        "data_structure/*.cpp"
        "math/*.cpp"
        "bruteforce/*.cpp"
        "binary_search/*.cpp"
        "sorting/*.cpp"
        "backtracking/*.cpp"
        "simulation/*.cpp"
)

# 각 소스 파일마다 개별 실행 파일 생성
foreach(SOURCE_FILE ${SOURCE_FILES})
    # 파일명에서 확장자 제거하여 실행 파일 이름으로 사용
    get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)
    # 디렉토리 이름 가져오기 (카테고리)
    get_filename_component(DIR_NAME ${SOURCE_FILE} DIRECTORY)
    get_filename_component(DIR_NAME ${DIR_NAME} NAME)

    # 실행 파일 이름: 카테고리_문제번호 형식
    set(FULL_EXECUTABLE_NAME "${DIR_NAME}_${EXECUTABLE_NAME}")

    add_executable(${FULL_EXECUTABLE_NAME} ${SOURCE_FILE})
endforeach()

# 기본 main.cpp도 유지
add_executable(ps main.cpp)

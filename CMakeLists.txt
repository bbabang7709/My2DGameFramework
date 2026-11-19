cmake_minimum_required(VERSION 3.21)
project(My2DGameFramework VERSION 0.1.0 LANGUAGES CXX)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 외부 라이브러리 찾기 (vcpkg가 준비해 줌)
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)

# 하위 레시피 불러오기
add_subdirectory(game)
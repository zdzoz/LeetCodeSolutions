cmake_minimum_required(VERSION 3.24)
project(LeetCode)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(LeetCode src/Arrays&Hashing/GroupAnagram.cpp src/TwoPointers/ValidPalindrome.cpp src/Graphs/NumberOfIslands.cpp src/Graphs/CloneGraph.cpp src/Graphs/MaximumSubarray.cpp)
target_link_libraries(LeetCode gtest gtest_main)
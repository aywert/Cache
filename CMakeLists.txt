cmake_minimum_required(VERSION 3.16)
project( MyCache
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set (DEBUG_FLAGS  -DDEBUG -ggdb3 -fsanitize=address,alignment -Wall -Wextra -Weffc++ 
    -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts 
    -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wno-format-nonliteral 
    -Wformat-security -Wformat=2 -Winline -Wnon-virtual-dtor -Woverloaded-virtual -Wpacked 
    -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo 
    -Wstrict-overflow=2 -Wsuggest-override -Wswitch-default -Wundef -Wunreachable-code -Wunused 
    -Wvariadic-macros -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs 
    -Wno-unused-parameter -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -fPIC -fPIE 
    -fno-omit-frame-pointer -fPIE -Werror=vla -Wno-write-strings)
set (RELEASE_FLAGS -O2)

file(GLOB HEADERS "include/*.hpp" "include/*.h")
file(GLOB MAIN_LRU_SOURCES "src/LRU/*.cpp" "src/tests/*.cpp")
file(GLOB MAIN_OPT_SOURCES "src/OPT/*.cpp")

add_executable(Cache_LRU ${MAIN_LRU_SOURCES}  ${HEADERS})
add_executable(Cache_OPT  ${MAIN_OPT_SOURCES} ${HEADERS})

target_include_directories(Cache_LRU 
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(Cache_OPT 
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

foreach (target Cache_LRU Cache_OPT)
    target_compile_options (${target}  PRIVATE $<$<CONFIG:Debug>:${DEBUG_FLAGS}>)
    target_compile_options (${target}  PRIVATE $<$<CONFIG:Release>:${RELEASE_FLAGS}>)

    target_link_options (${target}  PRIVATE $<$<CONFIG:Debug>:${DEBUG_FLAGS}>)
    target_link_options (${target} PRIVATE $<$<CONFIG:Release>:${RELEASE_FLAGS}>)
endforeach()
#cmake -S ./ -B build/Release -DCMAKE_BUILD_TYPE=Release
#cmake --build build/Release
#./build/Release/MyHash

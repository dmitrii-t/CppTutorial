cmake_minimum_required(VERSION 3.15)
project(VirtualFunctions CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra)
elseif(MSVC)
    add_compile_options(/W4)
endif()

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(BIN_DIR ${CMAKE_CURRENT_BINARY_DIR}/bin)

file(GLOB SOURCES "${SRC_DIR}/*.cpp")
file(GLOB HEADERS "${INC_DIR}/*.h" "${INC_DIR}/*.hpp")

add_executable(app ${SOURCES} ${HEADERS})
target_include_directories(app PRIVATE ${INC_DIR})

set_target_properties(app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${BIN_DIR}
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${BIN_DIR}
)

install(TARGETS app
    RUNTIME DESTINATION bin
)

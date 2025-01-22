#!/bin/bash

BUILD_TYPE="Debug"

while [[ $# -gt 0 ]]; do
    case $1 in
        --build-type)
            if [[ $2 == "Debug" || $2 == "Release" ]]; then
                BUILD_TYPE="$2"
            else
                echo "Error: Build type must be Debug or Release"
                exit 1
            fi
            shift 2
            ;;
        *)
            echo "Usage: $0 [--build-type Debug|Release]"
            exit 1
            ;;
    esac
done

find "$(dirname "$0")" -name "CMakeLists.txt" | while read -r cmake_file; do
    project_dir=$(dirname "$cmake_file")
    echo "Building project in: $project_dir"
    
    pushd "$project_dir" > /dev/null
    
    mkdir -p build && cd build || exit 1
    
    cmake .. || { 
        echo "Error: CMake configuration failed for $project_dir"
        exit 1
    }
    
    cmake --build . --config "$BUILD_TYPE" || {
        echo "Error: Build failed for $project_dir"
        exit 1
    }
    
    popd > /dev/null
done
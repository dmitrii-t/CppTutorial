#!/bin/bash

BUILD_TYPE="Debug"
CLEAN=false

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
        --clean)
            CLEAN=true
            shift
            ;;
        *)
            echo "Usage: $0 [--build-type Debug|Release] [--clean]"
            exit 1
            ;;
    esac
done

if [ "$CLEAN" = true ]; then
    find "$(dirname "$0")" -type d -name "build" -exec rm -rf {} +
fi

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
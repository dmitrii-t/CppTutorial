#!/bin/bash

# Define source directory and makefile paths
SOURCE_DIR="./.templates"
SOURCE_MAKEFILE="${SOURCE_DIR}/Makefile.template"

# Check if source Makefile exists
if [ ! -f "${SOURCE_MAKEFILE}" ]; then
    echo "Error: Source Makefile not found in ${SOURCE_DIR}"
    exit 1
fi

# Find all .vcxproj files and process their directories
find . -name "*.vcxproj" -type f | while read -r proj_file; do
    # Get the directory containing the .vcxproj file
    target_dir=$(dirname "$proj_file")

    # Skip the source directory if it contains a .vcxproj
    if [ "$target_dir" = "${SOURCE_DIR}" ]; then
        echo "Skipping source directory: $target_dir"
        continue
    fi

    # Copy the Makefile
    cp -v "${SOURCE_MAKEFILE}" "$target_dir/Makefile"

    # Check if copy was successful
    if [ $? -eq 0 ]; then
        echo "Successfully copied Makefile to: $target_dir"
    else
        echo "Failed to copy Makefile to: $target_dir"
    fi
done

echo "Makefiles were successfully updated"

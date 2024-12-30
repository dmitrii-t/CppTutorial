# Makefile at the root of the repository

# Variables
CLANG_FORMAT := clang-format
SHELL := /bin/bash

# Targets
.PHONY: all fmt check-fmt build check-readme

# all: check-fmt check-readme build

fmt:
	@echo "Formatting all source files..."
	@find . -type f \( -name "*.cpp" -o -name "*.h" -o -name "*.hpp" \) -exec $(CLANG_FORMAT) -style=file -i {} \;

check-fmt:
	@echo "Running format check..."
	@FORMATTING_ISSUES=0; \
	while IFS= read -r file; do \
		if ! $(CLANG_FORMAT) -style=file --dry-run --Werror "$$file"; then \
			FORMATTING_ISSUES=1; \
			$(CLANG_FORMAT) -style=file --dry-run "$$file"; \
		fi \
	done < <(find . -type f \( -name "*.cpp" -o -name "*.h" -o -name "*.hpp" \)); \
	if [ $$FORMATTING_ISSUES -eq 1 ]; then \
		echo "Formatting issues found. Please run 'make fmt' locally."; \
		exit 1; \
	fi

build:
	@echo "Building all projects..."
	@EXIT_CODE=0; \
	while IFS= read -r project_dir; do \
		echo "Building project in $$project_dir"; \
		( \
			cd "$$project_dir" && \
			if ! make -s all; then \
				echo "Build failed for project in $$project_dir"; \
				exit 1; \
			fi; \
			if [ ! -f "bin/a.exe" ]; then \
				echo "Binary not created for project in $$project_dir"; \
				exit 1; \
			fi \
		) || EXIT_CODE=$$?; \
	done < <(find . -mindepth 2 -name Makefile -exec dirname {} \;); \
	exit $$EXIT_CODE

check-readme:
	@echo "Checking for README.md in each project..."
	@EXIT_CODE=0; \
	while IFS= read -r dir; do \
		if [ ! -f "$$dir/README.md" ]; then \
			echo "Missing README.md in $$dir"; \
			EXIT_CODE=1; \
		fi \
	done < <(find . -name 'Makefile' -exec dirname {} \;); \
	if [ $$EXIT_CODE -eq 0 ]; then \
		echo "All projects have README.md files"; \
	fi; \
	exit $$EXIT_CODE

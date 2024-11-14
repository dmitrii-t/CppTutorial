# Compiler settings
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
# Include header files for formatting
HEADERS = $(wildcard $(SRC_DIR)/*.h $(SRC_DIR)/*.hpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

# Executable name
BINARY = $(BIN_DIR)/a.exe

.PHONY: exec
exec: $(BINARY)
	@$(BINARY)

# Default target
.PHONY: all
all: exec

# Format source files
.PHONY: fmt
fmt:
	@echo "Formatting source files..."
	@clang-format -i $(SOURCES) $(HEADERS)
	@echo "Formatting complete."

# Rule to create directories
$(OBJ_DIR) $(BIN_DIR):
	@mkdir -p $@

# Rule to compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to link object files into the executable
$(BINARY): $(OBJECTS) | $(BIN_DIR)
	@$(CXX) $(OBJECTS) -o $@

# Clean rule
.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

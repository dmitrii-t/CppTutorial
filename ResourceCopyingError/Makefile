# Compiler settings
CXX = g++
CXXFLAGS = -m64 -Wall -Wextra -std=c++17 

# drmemory flags
CXXFLAGS += -static-libgcc -static-libstdc++ -gdwarf-2

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
# Include header files for formatting
HEADERS = $(wildcard $(INC_DIR)/*.h $(INC_DIR)/*.hpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

# Include path for headers
CXXFLAGS += -I$(INC_DIR)

# Executable name
BINARY = $(BIN_DIR)/a.exe

.PHONY: exec
exec: $(BINARY)
	@$(BINARY)

# Default target
.PHONY: all
all: clean $(BINARY)

# Format source files
.PHONY: fmt
fmt:
	@echo "Formatting source files..."
	@clang-format -i $(SOURCES) $(HEADERS)
	@echo "Formatting complete."

# Rule to create directories
$(OBJ_DIR) $(BIN_DIR) $(INC_DIR):
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
	@rm -rf $(OBJ_DIR) $(BIN_DIR)

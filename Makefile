CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -Idatabase -I/usr/include/postgresql
LDFLAGS = -lpq

SRC_DIR = src
DB_DIR = database
BUILD_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(DB_DIR)/*.cpp)
OBJS = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(notdir $(SRCS)))

TARGET = programa

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(DB_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

run: all
	./$(TARGET)

.PHONY: all clean run
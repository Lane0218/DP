# 定义编译器
CXX = g++

# 定义编译选项
CXXFLAGS = -Wall -std=c++11 -g

# 定义目标文件
TARGET = DP

# 定义源文件
SOURCES = algorithm.cpp utils.cpp main.cpp

# 定义头文件
HEADERS = algorithm.h utils.h

# 生成目标文件的依赖
OBJECTS = $(SOURCES:.cpp=.o)

# 默认目标
all: $(TARGET)

# 链接目标文件生成可执行文件
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 编译源文件生成目标文件
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -f $(OBJECTS) $(TARGET)

# 伪目标，确保在依赖中使用
.PHONY: all clean
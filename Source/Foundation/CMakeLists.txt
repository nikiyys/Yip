# 指定CMake最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(Foundation)

# 收集源文件
file(GLOB SOURCES 
	"Math/Private/*.cpp"
)
file(GLOB HEADERS
	"*.h"
	"Math/Public/*.h"
)

# 创建动态库
add_library(Foundation SHARED ${SOURCES} ${HEADERS})

# 包含头文件目录
target_include_directories(Foundation PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}"
	"${CMAKE_CURRENT_SOURCE_DIR}/Math/Public"
)
# 添加动态库Export宏
target_compile_definitions(Foundation PRIVATE FOUNDATION_EXPORTS)

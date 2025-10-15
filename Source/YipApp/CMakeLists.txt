# 指定CMake最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(YipApp)

# 收集源文件
file(GLOB SOURCES 
	"*.cpp"
)

# 创建可执行程序
add_executable(YipApp ${SOURCES})

# 链接动态库
target_link_libraries(YipApp PRIVATE Foundation)

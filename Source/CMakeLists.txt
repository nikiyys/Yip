# 指定CMake最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(Yip)

# 设置使用C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 统一输出到Bin目录
set(OUTPUT_DIR "${CMAKE_BINARY_DIR}/../Binaries")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})

# 添加子目录 - 先构建库，再构建应用
add_subdirectory(Foundation)
add_subdirectory(YipApp)

# 不要生成INSTALL和ZERO_CHECK，ALL_BUILD貌似没有办法
set(CMAKE_SUPPRESS_REGENERATION true)  	# 禁用 ZERO_CHECK
set(CMAKE_SKIP_INSTALL_ALL_DEPENDENCY true)
set(CMAKE_SKIP_INSTALL_RULES true)		# 禁用INSTALL

# 安装规则 - 将所有目标安装到系统的bin目录
install(DIRECTORY ${OUTPUT_DIR}/ DESTINATION bin)

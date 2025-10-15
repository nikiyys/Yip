@echo off

cd ..

chcp 65001 >nul
title CMake Build Script

setlocal

echo ================================
echo    CMake Build Script
echo ================================

set "BUILD_DIR=Build"
set "SOURCE_DIR=../Source"

:: 检查 Build 目录是否存在
if not exist "%BUILD_DIR%" (
    echo Creating Build directory...
    mkdir "%BUILD_DIR%"
    if errorlevel 1 (
        echo Error: Failed to create Build directory!
        pause
        exit /b 1
    )
    echo Build directory created successfully.
) else (
    echo Build directory already exists.
)

:: 进入 Build 目录
echo Changing to Build directory...
cd "%BUILD_DIR%"
if errorlevel 1 (
    echo Error: Failed to enter Build directory!
    pause
    exit /b 1
)

:: 执行 CMake
echo ================================
echo Running CMake...
echo Source directory: %SOURCE_DIR%
echo ================================

cmake %SOURCE_DIR%

if errorlevel 1 (
    echo.
    echo Error: CMake configuration failed!
    pause
    exit /b 1
) else (
    echo.
    echo CMake configuration completed successfully!
)

echo.
echo Current directory: %CD%
echo.
pause
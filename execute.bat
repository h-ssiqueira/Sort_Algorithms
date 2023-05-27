cls
rem @echo off
title Sorting Algorithms
echo Compiling...
set "SRC_DIR=src\"
set "OBJ_DIR=bin\"

if exist "%OBJ_DIR%" (
    dir /b "%OBJ_DIR%" | findstr "^" >nul
    if errorlevel 1 (
        del /q "%OBJ_DIR%\*.*"
    )
) else (
    mkdir bin
)

for /R "%SRC_DIR%" %%f in (*.c) do (
    gcc -lm -c -O3 -march=native -mtune=native "%%f" -o "%OBJ_DIR%%%~nf.o"
)

gcc -o %OBJ_DIR%sort %OBJ_DIR%*.o
%OBJ_DIR%sort
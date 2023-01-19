set SRC_DIR = src/
set OBJ_DIR = bin/
mkdir bin
for /R %SRC_DIR% %%f in (*.c) do (
    gcc -lm -c -O3 -march=native -mtune=native "%%f" -o %OBJ_DIR%%%~nf.o
)
gcc -o sort %OBJ_DIR%*.o
.\sort
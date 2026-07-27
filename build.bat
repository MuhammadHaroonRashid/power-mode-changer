@echo off
echo Installing CMake, Ninja and Ziglang via Python...
python -m pip install cmake ninja ziglang

for /f "delims=" %%i in ('python -c "import sysconfig; print(sysconfig.get_path('scripts'))"') do set PYTHON_SCRIPTS=%%i
set PATH=%PYTHON_SCRIPTS%;%PATH%

if exist build\ (
    echo Clearing old build cache...
    rmdir /S /Q build
)

echo Configuring CMake with Zig...
cmake -G "Ninja" -DCMAKE_C_COMPILER="%cd%\zigcc.bat" -DCMAKE_CXX_COMPILER="%cd%\zigcxx.bat" -DCMAKE_SYSTEM_NAME=Windows -B build -S .

echo Building the project...
cmake --build build --config Release
echo Build complete! Executable is in the build folder.

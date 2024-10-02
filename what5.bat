@echo off
echo N	S	T
for /L %%i in (1, 1, 10) do "./App612.exe" %%i
for /L %%i in (20, 10, 100) do "./App612.exe" %%i
for /L %%i in (200, 100, 1000) do "./App612.exe" %%i
for /L %%i in (2000, 1000, 10000) do "./App612.exe" %%i
for /L %%i in (100000, 100000, 1000000) do "./App612.exe" %%i
for /L %%i in (2000000, 2000000, 50000000) do "./App612.exe" %%i

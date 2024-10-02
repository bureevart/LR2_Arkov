@echo off
echo p	S	T
for /L %%i in (1, 1, 5) do for /L %%j in (1, 1, 12) do "./App553.exe" %%j

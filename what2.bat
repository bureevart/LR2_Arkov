@echo off
echo N	S	Twin	Tomp
set "a=1000000"
set "max=10000000000"
:loop
for /L %%i in (1,1,10) do (
	"./App541.exe" %a%
)
echo %a%
set "a=%a%0"
if %a% gtr %max% goto :end
goto :loop
:end

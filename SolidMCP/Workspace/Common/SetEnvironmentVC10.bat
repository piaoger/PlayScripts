
@echo off

:: Setup SolidMCP Environment
goto SETENVIRONMENTS
goto SETCOMPONENTS

goto SOLIDMCPINFO
goto DISPLAY3RDCOMPONENTS

goto STARTDEVIDE
goto THEEND



:SETENVIRONMENTS

set SMCP_ROOT=s:
set SMCP_COMPONENTS=%SMCP_ROOT%\Components
set SMCP_COMPONENTS_CPP=%SMCP_COMPONENTS%\CPlusPlus
 
set CODE_NAME=PlayScripts
set SMCP_VER_MAJOR=1
set SMCP_VER_MINOR=0


:SETCOMPONENTS

set SMCP_COMP_CPP_PYTHON=%SMCP_COMPONENTS_CPP%\Python\Python-2.6.7
set SMCP_COMP_CPP_V8=%SMCP_COMPONENTS_CPP%\V8\V8-3.9\Win64


rem Set Debug dll pathes;
 
set PATH=%PATH%;%SMCP_COMP_CPP_V8%
set PATH=%PATH%;%SMCP_COMP_CPP_PYTHON%\PCbuild\amd64


echo

:SOLIDMCPINFO
echo **********************************************************
echo SolidMCP is a sample project created by Piaoger 
echo **********************************************************
echo [SolidMCP Information]
echo ...
echo Code Name      = %CODE_NAME%
echo Directory      = %SMCP_DIRECTORY%
echo ROOT PATH      = %SMCP_ROOT%
echo Components     = %SMCP_COMPONENTS%
echo Major Version  = %SMCP_VER_MAJOR%
echo Minor Version  = %SMCP_VER_MINOR%


:DISPLAY3RDCOMPONENTS
echo [SolidMCP 3rd Components]
echo ...
@echo C++/C Components
echo
echo Python          = %SMCP_COMP_CPP_PYTHON%
echo V8            = %SMCP_COMP_CPP_V8%
echo ...

:STARTDEVIDE
call %SMCP_ROOT%\Workspace\Develop\StartDevIDE.bat dev10
 

:THEEND
set PATH
cd /d %SMCP_ROOT%
@echo on




 



















 


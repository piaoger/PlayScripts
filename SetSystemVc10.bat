@ set SMCP_ROOT=s:

@ set THIS_FOLDER=%~dp0
@ set SMCP_DIRECTORY=%THIS_FOLDER%SolidMCP
@ subst %SMCP_ROOT% /d
@ subst %SMCP_ROOT% %SMCP_DIRECTORY%

call %SMCP_DIRECTORY%\workspace\Common\SetEnvironmentVC10.bat
echo [Setting Development Environment]

set SOLIDMCP_SOLUTION=S:\Workspace\Build\Solutions\iScripts.sln
if /I .%1 == .     (call "%VS90COMNTOOLS%vsvars32" & devenv   %SOLIDMCP_SOLUTION%)
if /I .%1 == .dev10 (call "%VS100COMNTOOLS%vsvars32" & devenv   %SOLIDMCP_SOLUTION%)
if /I .%1 == .dev9 (call "%VS80COMNTOOLS%vsvars32" & devenv   %SOLIDMCP_SOLUTION%)
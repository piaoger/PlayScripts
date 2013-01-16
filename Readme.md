
# What's PlayScripts

PlayScripts is the play groud of scripting of Piaoger Gong.


# How to use:
- subst this folder as s:
- Run S:\SetSystemVc10.bat
  - It calls S:\Workspace\Common\SetEnvironmentVC10.bat
  - Set Environment Variables
  - Automatically Open VS solution  S:\Workspace\Build\Solutions\iScripts.sln
- Build X64/Debug
  - Unfortunately, It's Healthy Only configuration now.
  - Run TestServer to invoke TUT cases
  - Run PyInterpreter to invoke Python Embedded test cases.

  
# What's in AdSimMemory
- S:\
	- ClientApps
		- Interpreter (Python Interpreter)
		- TestServer (Run TUT Test cases)
	- Components (3rd components)
	- Server
		- BedRock (Base Library)
		- Python
		- JavaScript
	- Workspaces (Scripts and test files)
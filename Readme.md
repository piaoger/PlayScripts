# What's PlayScripts

PlayScripts is the playground for script binding/embedded.

# Involved Script languages

- Python:CPython + PyCXX
- JavaScript:Google V8 Engine
- Scheme:TinyScheme

# How to use:
- subst child folder "SolidMCP" as s:
- Run S:\SetSystemVc10.bat
  - It calls S:\Workspace\Common\SetEnvironmentVC10.bat
  - Set Environment Variables
  - Automatically Open VS solution  S:\Workspace\Build\Solutions\iScripts.sln
- Build X64/Debug
  - Unfortunately, It's "Healthy Only" configuration now.
  - Run TestServer to invoke TUT cases
  - Run PyInterpreter to invoke Python Embedded test cases.

  
# What's in PlayScripts
- S:\
	- ClientApps
		- Interpreter (Python Interpreter)
		- TestServer (Run TUT Test cases)
	- Components (3rd components)
	- Server
		- BedRock (Base Library)
		- Python  (Pyton Bindings and Embedded cases)
		  - PlayCXX   (Try Cases based on PyCXX)
		  - PyCXX     (PyCXX library)
		  - Simeple   (Simple module built on raw python api)
		  - SimpleCXX (Simple module built on PyCXX)
		- JavaScript (V8 Try Cases)
	- Workspaces (Scripts and test files)

@rem Used by the buildbot "compile" step.
cmd /c Tools\buildbot\external-amd64.bat
call "%VS90COMNTOOLS%\..\..\VC\vcvarsall.bat" x86_amd64
::cmd /c Tools\buildbot\clean-amd64.bat
vcbuild /useenv PCbuild\kill_python.vcproj "Release|x64" && PCbuild\amd64\kill_python_d.exe
vcbuild PCbuild\pcbuild.sln "Release|x64"

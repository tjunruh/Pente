msbuild /m /p:Configuration=Release Code/windows_msbuild/Pente.vcxproj
mkdir build
mkdir build\bin
mkdir build\bin\board_configs
copy Code\windows_msbuild\Release\Pente.exe build\bin\
copy Code\windows_msbuild\Release\ascii_engine.dll build\bin\
copy board_configs\* build\bin\board_configs\
copy Pente.bat build\
FOR /D %%p IN ("Code\windows_msbuild\*.*") DO rmdir "%%p" /s /q
Get-ChildItem -Recurse -Include *.c,*.h,*.cpp,*.hpp -Path src | ForEach-Object {
    & "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\Llvm\x64\bin\clang-format.exe" -i $_.FullName
}
# Update CMakeLists.txt in all the projects with the template .templates/CMakeLists.template
Get-ChildItem -Path "./**/CMakeLists.txt" -Recurse | ForEach-Object {
    $content = Get-Content ".templates/CMakeLists.template"
    $folderName = Split-Path -Parent $_.FullName | Split-Path -Leaf
    $content = $content -replace "project\(.*\)", "project($folderName CXX)"
    Set-Content $_.FullName $content
}

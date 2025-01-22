param(
    [ValidateSet("Debug", "Release")]
    [string]$BuildType = "Debug"
)

$cmakeFiles = Get-ChildItem -Path $PSScriptRoot -Filter "CMakeLists.txt" -Recurse
foreach ($cmakeFile in $cmakeFiles) {
    $projectDir = $cmakeFile.DirectoryName
    Write-Host "Building project in: $projectDir"

    Push-Location $projectDir
    $buildDir = Join-Path $projectDir "build"

    if (-not (Test-Path $buildDir)) {
        New-Item -ItemType Directory -Path $buildDir
    }

    Set-Location $buildDir
    cmake -G "Visual Studio 17 2022" ..
    cmake --build . --config $BuildType

    if ($LASTEXITCODE -ne 0) {
        Write-Error "Build failed for project in $projectDir"
        exit 1
    }

    Pop-Location
}

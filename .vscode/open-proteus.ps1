$proteusPath = "C:\Program Files (x86)\Labcenter Electronics\Proteus 8 Professional\BIN\PDS.exe"
$projectFile = $args[0]

if (-not (Get-Process PDS -ErrorAction SilentlyContinue)) {
    Start-Process $proteusPath $projectFile
}

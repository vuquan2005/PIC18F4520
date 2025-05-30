$proteusPath = "C:\Program Files (x86)\Labcenter Electronics\Proteus 8 Professional\BIN\PDS.exe"
$projectFile = $args[0]

if (-Not (Test-Path $proteusPath)) {
    Write-Error "Proteus không được tìm thấy tại: $proteusPath"
    exit 1
}

# Nếu Proteus đang chạy thì không mở nữa, bỏ if đi nếu muốn chạy bất ngay
if (-not (Get-Process PDS -ErrorAction SilentlyContinue)) {
    Start-Process $proteusPath -ArgumentList "`"$projectFile`""
}
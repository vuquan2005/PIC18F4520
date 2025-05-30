param (
    [string]$projectFile = "", # Tham số cho file dự án
    [switch]$forceNewInstance = $false # Tham số để quyết định mở instance mới
)

# Đường dẫn đến file thực thi của Proteus
$proteusPath = "C:\Program Files (x86)\Labcenter Electronics\Proteus 8 Professional\BIN\PDS.exe"

# Kiểm tra xem Proteus có tồn tại không
if (-Not (Test-Path $proteusPath)) {
    Write-Host "Proteus is not found at: $proteusPath" -ForegroundColor Red
    exit 1
}

# Kiểm tra xem Proteus có đang chạy không
if (Get-Process -Name "PDS" -ErrorAction SilentlyContinue) {
    Write-Host "Proteus has been opened!" -ForegroundColor Yellow
    exit 0
}

# Thử mở Proteus với file dự án
try {
    Start-Process $proteusPath -ArgumentList "`"$projectFile`"" -ErrorAction Stop
    Write-Host "Proteus opened successfully with file: $projectFile" -ForegroundColor Green
}
catch {
    if ($_.Exception -is [System.InvalidOperationException]) {
        Write-Host "User refused to open Proteus (UAC disabled,...)." -ForegroundColor Red
    } else {
        Write-Host "Error when opening Proteus: $($_.Exception.Message)" -ForegroundColor Red
    }
}